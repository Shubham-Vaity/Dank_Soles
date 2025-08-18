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


void UCombat:: Lock()
{
	
}