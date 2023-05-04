#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "PawnBaseClass.h"
#include "EndlessRunnerGameMode.generated.h"

class ARunnerCharacter;

UCLASS()
class AEndlessRunnerGameMode : public AGameModeBase
{
 GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
 virtual void Tick(float DeltaSeconds) override;

public:
 AEndlessRunnerGameMode();

	// float LaneOffset(int laneIndex);

	APawnBaseClass* player1;
	APawnBaseClass* player2;

	float StartTime;
	float InitialLevelSpeed;
	float SpeedMultiplier;
	
 UPROPERTY(EditAnywhere)
 int CPPNumberOfLanes = 6;
 UPROPERTY(EditAnywhere)
 float CPPLaneWidth = 250.f;
 UPROPERTY(EditAnywhere)
 float CPPLevelSpeed = 500.f;

	
 UPROPERTY(EditAnywhere)
 float OutOfBoundsLoc = -100.f;
};