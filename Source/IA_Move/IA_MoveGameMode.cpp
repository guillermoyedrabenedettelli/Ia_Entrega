// Copyright Epic Games, Inc. All Rights Reserved.

#include "IA_MoveGameMode.h"
#include "IA_MoveCharacter.h"
#include "UObject/ConstructorHelpers.h"

AIA_MoveGameMode::AIA_MoveGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
