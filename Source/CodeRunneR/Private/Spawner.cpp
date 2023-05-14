#include "Spawner.h"
#include "Math/UnrealMathUtility.h"
#include "EndlessRunnerGameMode.h"
#include "Engine/TargetPoint.h"
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
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), TargetPoints);
}

FVector ASpawner::GetTargetPosition(int32 Index)
{
	if (Index >= 0 && Index < TargetPoints.Num())
	{
		ATargetPoint* Target = Cast<ATargetPoint>(TargetPoints[Index]);
		return Target->GetActorLocation();
	}
	else {
		return GetActorLocation();
	}
}

void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CurrentDistance += GameMode->CPPLevelSpeed * DeltaTime;

	// Spawn Logic
	if (CurrentDistance > SpawnDistance)
	{
		// Shuffle the TargetPoints array
		TargetPoints.Sort([](const AActor& A, const AActor& B) {
			return FMath::RandBool();
		});

		for (int i = 0; i < 4; i++)
		{
			FVector TargetPos = GetTargetPosition(i);
			GetWorld()->SpawnActor<AActor>(SpawnableObject[0], TargetPos, GetActorRotation(), FActorSpawnParameters());
		}
		CurrentDistance -= SpawnDistance;
	}
	
}



