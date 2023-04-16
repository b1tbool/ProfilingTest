// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProfilingTestGameMode.h"
#include "ProfilingTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProfilingTestGameMode::AProfilingTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
