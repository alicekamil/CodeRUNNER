#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

class AEndlessRunnerGameMode;
class ATargetPoint;

UCLASS()
class CODERUNNER_API ASpawner : public AActor
{
	GENERATED_BODY()

public:
	ASpawner();

	UPROPERTY()
	TArray<AActor*> TargetPoints;
	
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<AActor>> SpawnableObject;
	UPROPERTY(EditAnywhere)
	float SpawnDistance;
	
	FVector newPos;
	UPROPERTY()
	ATargetPoint* RandomTarget;

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	FVector GetTargetPosition(int32 Index);

private:
	UPROPERTY()
	AEndlessRunnerGameMode* GameMode;

	float CurrentDistance;
};