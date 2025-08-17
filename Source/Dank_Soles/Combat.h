// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Combat.generated.h"



class UInputAction;
class UEnhancedInputComponent;
class ACharacter;
class APlayerController;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DANK_SOLES_API UCombat : public UActorComponent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this component's properties
	UCombat();

	
	// --- CONFIG (editable like BP pins) ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Aiming")
	float RotationInterpSpeed = 10.f;               // RInterpTo speed in your BP

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Aiming")
	float TargetAcquireRadius = 3000.f;             // how far to search for targets

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Firing")
	TSubclassOf<AActor> ProjectileClass;            // your projectile BP

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Firing")
	FName MuzzleSocketName = TEXT("Muzzle");        // socket on the weapon/mesh

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Firing")
	float FireCooldown = 0.15f;

	// input actions (assign assets in Blueprint on the owning character)
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* AttackAction;

	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* ToggleLockAction;

	// target other actor (mirrors your “Target Lock” wires)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Target")
	AActor* CurrentTarget = nullptr;

	// expose simple helpers for BP too
	UFUNCTION(BlueprintCallable) void ClearTarget();
	UFUNCTION(BlueprintCallable) void SetTarget(AActor* NewTarget);




protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;



private:
	// cached
	ACharacter* OwnerCharacter = nullptr;
	APlayerController* PC = nullptr;
	FTimerHandle FireCooldownHandle;
	bool bCanFire = true;
	bool bLockedOn = false;

	// input handlers
	void OnAttackPressed();
	void OnToggleLock();

	// logic
	void UpdateAiming(float DeltaSeconds);          // Event Tick → FindLookAtRotation → SetControlRotation
	void FireProjectile();                          // SpawnActor like your BP “SpawnEmitter/Projectile”
	AActor* FindBestTarget() const;            
		
};
