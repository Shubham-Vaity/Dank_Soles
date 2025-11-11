#include "Combat.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"

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
        playerReff = Cast<ADank_SolesCharacter  >(UGameplayStatics::GetPlayerCharacter(this, 0));
    }
}

void UCombat::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (playerReff && EnemyReff)
    {
        FVector StartLocation = playerReff->GetActorLocation();
        FVector TargetLocation = EnemyReff->GetActorLocation();
        FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(StartLocation, TargetLocation);

        if (playerReff->Controller)
        {
            playerReff->Controller->SetControlRotation(LookAtRotation);
        }
    }
}

void UCombat::PerformLookSphereTrace()
{
    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
    if (!PC) return;

    FVector CamLoc;
    FRotator CamRot;
    PC->GetPlayerViewPoint(CamLoc, CamRot);
    FVector CamForward = CamRot.Vector();

    FVector Start = CamLoc;
    FVector End = Start + CamForward * 1696.0f;

    FCollisionQueryParams QueryParams;
    QueryParams.AddIgnoredActor(GetOwner());
    QueryParams.bTraceComplex = false;

    FCollisionObjectQueryParams ObjectQueryParams(FCollisionObjectQueryParams::InitType::AllDynamicObjects);
    ObjectQueryParams.AddObjectTypesToQuery(ECC_Pawn);

    FHitResult Hit;
    FCollisionShape SphereShape = FCollisionShape::MakeSphere(169.0f);

    bool bHit = GetWorld()->SweepSingleByObjectType(
        Hit, Start, End, FQuat::Identity, ObjectQueryParams, SphereShape, QueryParams
    );

    
    if (bHit && Hit.GetActor())
    {
        EnemyReff = Hit.GetActor();

        if (Dot && Dot->IsChildOf(AActor::StaticClass()))
        {
            AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(
                Dot,
                Hit.GetActor()->GetActorLocation(),
                Hit.GetActor()->GetActorRotation()
            );

            if (SpawnedActor)
            {
                Dotreff = SpawnedActor;

               
                if (playerReff)
                {
                    playerReff->GetCharacterMovement()->bOrientRotationToMovement = false;
                    playerReff->GetCharacterMovement()->bUseControllerDesiredRotation = true;
                }

                
                Dotreff->AttachToActor(Hit.GetActor(), FAttachmentTransformRules::SnapToTargetIncludingScale);
            }
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Dot variable is invalid or not an Actor class!"));
        }
    }
}

void UCombat::checkForEnemy()
{
    if (EnemyReff)
    {
        EnemyReff = nullptr;

        if (playerReff)
        {
            playerReff->GetCharacterMovement()->bOrientRotationToMovement = true;
            playerReff->GetCharacterMovement()->bUseControllerDesiredRotation = false;
        }

        if (Dotreff)
        {
            Dotreff->Destroy();
            Dotreff = nullptr;
        }
    }
    else
    {
        PerformLookSphereTrace();
    }
}

void UCombat::AttactingFunction()
{
    if (!playerReff) return;

    if (!IsAttacking)
    {
        IsAttacking = true;
        playerReff->GetMesh()->SetRelativeRotation(FRotator(0, 0, 0));

     
    }
    else
    {
        IsCombow = true;
    }
}



void UCombat::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    
}