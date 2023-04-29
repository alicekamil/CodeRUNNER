#include "EndlessRunnerGameMode.h"
#include "Components/BoxComponent.h"
#include "CPPPawnBase.h"
#include "UObject/ConstructorHelpers.h"

AEndlessRunnerGameMode::AEndlessRunnerGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_CPPawnBase"));
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("Something is happening:D")));
	}
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	
	
	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Default"));
	RootComponent = DefaultRoot;
};	

