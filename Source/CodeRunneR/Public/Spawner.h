#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

class AEndlessRunnerGameMode;

UCLASS()
class CODERUNNER_API ASpawner : public AActor
{
	GENERATED_BODY()

public:
	ASpawner();

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<AActor>> SpawnableObject;
	UPROPERTY(EditAnywhere)
	float SpawnDistance; 

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	AEndlessRunnerGameMode* GameMode;

	float CurrentDistance;
};