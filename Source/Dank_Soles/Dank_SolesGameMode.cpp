// Copyright Epic Games, Inc. All Rights Reserved.

#include "Dank_SolesGameMode.h"
#include "Dank_SolesCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADank_SolesGameMode::ADank_SolesGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
