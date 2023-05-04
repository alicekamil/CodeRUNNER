#include "Spawner.h"
#include "Math/UnrealMathUtility.h"
#include "EndlessRunnerGameMode.h"
#include "Kismet/GameplayStatics.h"

ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = true;
	CurrentDistance = 0;
}

void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	GameMode = GetWorld()->GetAuthGameMode<AEndlessRunnerGameMode>();
}

void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CurrentDistance += GameMode->CPPLevelSpeed * DeltaTime;

	// Spawn Logic
	if (CurrentDistance > SpawnDistance)
	{
		CurrentDistance -= SpawnDistance;
		GetWorld()->SpawnActor<AActor>(SpawnableObject[FMath::RandRange(0, SpawnableObject.Num() - 1)], GetActorLocation(), GetActorRotation(), FActorSpawnParameters());
	}
}