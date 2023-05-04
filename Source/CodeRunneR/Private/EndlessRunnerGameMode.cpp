#include "EndlessRunnerGameMode.h"

#include "AITestsCommon.h"
#include "BasePlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "PawnBaseClass.h"
#include "UObject/ConstructorHelpers.h"

AEndlessRunnerGameMode::AEndlessRunnerGameMode()
{
	static ConstructorHelpers::FClassFinder<APawnBaseClass> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_PawnBase"));
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("Something is happening:D")));
	}
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
		
	}
	
	PlayerControllerClass = ABasePlayerController::StaticClass();
	
	CPPLevelSpeed = InitialLevelSpeed;
}

void AEndlessRunnerGameMode::BeginPlay()
{
	Super::BeginPlay();

	StartTime = GetWorld()->GetTimeSeconds();
	InitialLevelSpeed = 500.f; // Change this to an appropriate value
	SpeedMultiplier = 10.f; // Change this to an appropriate value
}
void AEndlessRunnerGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Ramp up the speed with a logarithmic function
	float TimeSinceStart = GetWorld()->GetTimeSeconds() - StartTime;
	float NewSpeed = InitialLevelSpeed + sqrt(TimeSinceStart) * SpeedMultiplier;
	CPPLevelSpeed = FMath::Max(NewSpeed, CPPLevelSpeed);
}



