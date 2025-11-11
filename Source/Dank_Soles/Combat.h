#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "Dank_SolesCharacter.h"
#include "Combat.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DANK_SOLES_API UCombat : public UActorComponent
{
    GENERATED_BODY()

public:
    UCombat();

    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
    virtual void BeginPlay() override;

public:

    /** References */
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Combat")
    ACharacter* playerReff;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Combat")
    AActor* EnemyReff;

    /** Dot marker class to spawn (must be an Actor Blueprint) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    TSubclassOf<AActor> Dot;

    /** Spawned dot reference */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    AActor* Dotreff;

    /** Attack control booleans */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    bool IsAttacking = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    bool IsCombow = false;

    /** Optional animation references */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    UAnimMontage* AttackMontage;

    /** Functions */
    UFUNCTION()
    void PerformLookSphereTrace();

    UFUNCTION()
    void checkForEnemy();

    UFUNCTION()
    void AttactingFunction();


private:
    void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);
};
