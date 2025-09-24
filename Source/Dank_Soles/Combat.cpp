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
        playerReff = Cast<ADank_SolesCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
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

    // 6. If hit, update references and settings
    if (bHit && Hit.GetActor())
    {
        EnemyReff = Hit.GetActor();

        // SAFELY spawn dot actor
        if (Dot) // Ensure Dot is set in blueprint or code
        {
            AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(Dot, Hit.GetActor()->GetActorLocation(), Hit.GetActor()->GetActorRotation());
            if (SpawnedActor)
            {
                Dotreff = SpawnedActor;

                // Disable movement-based rotation, use controller rotation
                if (playerReff)
                {
                    playerReff->GetCharacterMovement()->bOrientRotationToMovement = false;
                    playerReff->GetCharacterMovement()->bUseControllerDesiredRotation = true;
                }

                // Attach the dot to the enemy
                Dotreff->AttachToActor(Hit.GetActor(), FAttachmentTransformRules::SnapToTargetIncludingScale);
            }
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

void UCombat::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    // Intentionally empty, or future input bindings
}

