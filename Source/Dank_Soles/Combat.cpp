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

    if (EnemyReff)
    {
    FVector StartLocation =playerReff->GetActorLocation();
    FVector TargetLocation=EnemyReff->GetActorLocation();
        FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(StartLocation, TargetLocation);





        if (playerReff->Controller)
        {
            playerReff->Controller->SetControlRotation(LookAtRotation);
        }

    }else{
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
    /*
    FColor TraceColor = bHit ? FColor::Green : FColor::Red;
    DrawDebugLine(GetWorld(), Start, End, TraceColor, false, 5.0f, 0, 2.0f);
    DrawDebugSphere(GetWorld(), End, 169.0f, 16, TraceColor, false, 5.0f);
    */

    if (bHit && Hit.GetActor())
    {
        EnemyReff=Hit.GetActor();
        AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(Dot, Hit.GetActor()->GetActorLocation(), Hit.GetActor()->GetActorRotation());
        Dotreff = SpawnedActor;

        Dotreff=SpawnedActor;

        playerReff->GetCharacterMovement()->bOrientRotationToMovement=false;
        playerReff->GetCharacterMovement()->bUseControllerDesiredRotation = true;


        if (Dotreff && Hit.GetActor())
        {
            Dotreff->AttachToActor(Hit.GetActor(), FAttachmentTransformRules::SnapToTargetIncludingScale    );
        }
    }


}
void UCombat::checkForEnemy()
{
    if (EnemyReff)
    {
        EnemyReff=nullptr;
        playerReff->GetCharacterMovement()->bOrientRotationToMovement=true;
        playerReff->GetCharacterMovement()->bUseControllerDesiredRotation = false;
        if (Dotreff)
        {
            Dotreff->Destroy();
        }
    }
    else
    {

     //   PerformLookSphereTrace();



    }

}