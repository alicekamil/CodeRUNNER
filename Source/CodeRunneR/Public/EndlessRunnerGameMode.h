#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "EndlessRunnerGameMode.generated.h"

class USceneComponent;

UCLASS()
class AEndlessRunnerGameMode : public AGameModeBase
{
 GENERATED_BODY()

public:
 AEndlessRunnerGameMode();

	float LaneOffset(int laneIndex);
	
 UPROPERTY(EditAnywhere)
 USceneComponent* DefaultRoot;

	
 UPROPERTY(EditAnywhere)
 int CPPNumberOfLanes = 3;
 UPROPERTY(EditAnywhere)
 float CPPLaneWidth = 250.f;
 UPROPERTY(EditAnywhere)
 float CPPLevelSpeed = 500.f;

	
 UPROPERTY(EditAnywhere)
 float OutOfBoundsLoc = -100.f;
 //TArray<FVector> ObstacleRelativeOffsets;
};