// Fill out your copyright notice in the Description page of Project Settings.

#include "EndlessRunnerGameMode.h"
#include "Components/BoxComponent.h"
#include "CPPPawnBase.h"
#include "UObject/ConstructorHelpers.h"

AEndlessRunnerGameMode::AEndlessRunnerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_CPPawnBase"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	
	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Defaultoot"));
	RootComponent = DefaultRoot;
		
	CPPLevelBounds = CreateDefaultSubobject<UBoxComponent>(FName("CPPLevelBounds"));
	CPPLevelBounds->SetupAttachment(DefaultRoot);
};	

