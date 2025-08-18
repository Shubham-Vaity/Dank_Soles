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
#include "Dank_SolesCharacter.h"
#include "DrawDebugHelpers.h"


UCombat::UCombat()
{

	PrimaryComponentTick.bCanEverTick = true;

	

	
}



void UCombat::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		playerReff=  Cast<ADank_SolesCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
		
	}
	
}



void UCombat::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
}

void UCombat::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{

	
	}
	
}


void UCombat::PerformLookSphereTrace()
{
	// 1. Get PlayerController
	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	if (!PC) return;

	// 2. Get camera location and forward vector
	FVector CamLoc;
	FRotator CamRot;
	PC->GetPlayerViewPoint(CamLoc, CamRot);
	FVector CamForward = CamRot.Vector();

	// 3. Calculate start and end
	FVector Start = CamLoc;
	FVector End = Start + CamForward * 1696.0f;  // trace distance

	// 4. Set up collision
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(GetOwner()); // don't hit self
	QueryParams.bTraceComplex = false;

	FCollisionObjectQueryParams ObjectQueryParams(FCollisionObjectQueryParams::InitType::AllDynamicObjects);
	ObjectQueryParams.AddObjectTypesToQuery(ECC_Pawn); // detect Pawns only

	// 5. Perform sphere trace
	FHitResult Hit;
	FCollisionShape SphereShape = FCollisionShape::MakeSphere(169.0f); // radius 169

	bool bHit = GetWorld()->SweepSingleByObjectType(
		Hit,
		Start,
		End,
		FQuat::Identity,
		ObjectQueryParams,
		SphereShape,
		QueryParams
	);

	// 6. Debug draw
	FColor TraceColor = bHit ? FColor::Green : FColor::Red;
	DrawDebugLine(GetWorld(), Start, End, TraceColor, false, 5.0f, 0, 2.0f);
	DrawDebugSphere(GetWorld(), End, 169.0f, 16, TraceColor, false, 5.0f);

	if (bHit && Hit.GetActor())
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit actor: %s"), *Hit.GetActor()->GetName());
	}
}
