// Copyright Epic Games, Inc. All Rights Reserved.

#include "GamePGGameMode.h"
#include "GamePGCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGamePGGameMode::AGamePGGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
