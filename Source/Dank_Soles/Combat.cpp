// Fill out your copyright notice in the Description page of Project Settings.


#include "Combat.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UCombat::UCombat()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UCombat::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ACharacter>(GetOwner());
	PC = OwnerCharacter ? Cast<APlayerController>(OwnerCharacter->GetController()) : nullptr;

	// bind Enhanced Input if present on the owner
	if (AActor* Owner = GetOwner())
	{
		if (Owner->InputComponent)
		{
			if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(Owner->InputComponent))
			{
				if (AttackAction)     EIC->BindAction(AttackAction,     ETriggerEvent::Started, this, &UCombat::OnAttackPressed);
				if (ToggleLockAction) EIC->BindAction(ToggleLockAction, ETriggerEvent::Started, this, &UCombat::OnToggleLock);
			}
		}
	}
}

void UCombat::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	ClearTarget();
}

// Called every frame
void UCombat::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateAiming(DeltaTime);
	// ...
}


void UCombat::OnAttackPressed()
{
	FireProjectile();
}

void UCombat::OnToggleLock()
{
	if (bLockedOn && CurrentTarget)
	{
		bLockedOn = false;
		ClearTarget();
		return;
	}

	CurrentTarget = FindBestTarget();
	bLockedOn = (CurrentTarget != nullptr);
}

/* ------------- TARGET MGMT ------------- */

void UCombat::SetTarget(AActor* NewTarget)
{
	CurrentTarget = NewTarget;
	bLockedOn = (CurrentTarget != nullptr);
}

void UCombat::ClearTarget()
{
	CurrentTarget = nullptr;
	bLockedOn = false;
}

/* ---------------- AIMING ----------------
   Blueprint analogue:
   Event Tick → Get Actor Location, Get Target Location →
   FindLookAtRotation → RInterpTo → Set Control Rotation
-----------------------------------------*/
void UCombat::UpdateAiming(float DeltaSeconds)
{
	if (!PC || !OwnerCharacter) return;

	FRotator DesiredRot = PC->GetControlRotation();

	if (bLockedOn && IsValid(CurrentTarget))
	{
		const FVector From = OwnerCharacter->GetActorLocation();
		const FVector To   = CurrentTarget->GetActorLocation();

		const FRotator LookAt = UKismetMathLibrary::FindLookAtRotation(From, To);
		DesiredRot = FMath::RInterpTo(PC->GetControlRotation(), LookAt, DeltaSeconds, RotationInterpSpeed);

		// (optional) visualize like your debug lines
		DrawDebugLine(GetWorld(), From + FVector(0,0,50), To, FColor::Green, false, 0.f, 0, 1.5f);
	}

	PC->SetControlRotation(DesiredRot);
}

/* -------------- FIRING ------------------
   Mirrors your “Spawn projectile at muzzle” path
-----------------------------------------*/
void UCombat::FireProjectile()
{
	if (!bCanFire || !ProjectileClass || !OwnerCharacter) return;

	FVector SpawnLoc = OwnerCharacter->GetActorLocation();
	FRotator SpawnRot = (PC ? PC->GetControlRotation() : OwnerCharacter->GetActorRotation());

	// if owner has a mesh + socket, use it (BP used a socket attach)
	if (USkeletalMeshComponent* Mesh = OwnerCharacter->FindComponentByClass<USkeletalMeshComponent>())
	{
		if (Mesh->DoesSocketExist(MuzzleSocketName))
		{
			const FTransform SocketTM = Mesh->GetSocketTransform(MuzzleSocketName);
			SpawnLoc = SocketTM.GetLocation();
			SpawnRot = SocketTM.GetRotation().Rotator();
		}
	}

	GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnLoc, SpawnRot);

	// simple cooldown like your timers/timeline
	bCanFire = false;
	GetWorld()->GetTimerManager().SetTimer(
		FireCooldownHandle,
		[this](){ bCanFire = true; },
		FireCooldown, false
	);
}

/* -------- FIND TARGET (closest) -------- */
AActor* UCombat::FindBestTarget() const
{
	if (!OwnerCharacter) return nullptr;

	TArray<AActor*> Candidates;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), Candidates);

	AActor* Best = nullptr;
	float BestDist = TargetAcquireRadius;

	const FVector Origin = OwnerCharacter->GetActorLocation();

	for (AActor* A : Candidates)
	{
		if (A == OwnerCharacter) continue;
		// TODO: filter to your enemy base class or by tag
		if (!A->ActorHasTag(TEXT("Enemy"))) continue;

		const float D = FVector::Dist(Origin, A->GetActorLocation());
		if (D < BestDist)
		{
			BestDist = D;
			Best = A;
		}
	}
	return Best;
}