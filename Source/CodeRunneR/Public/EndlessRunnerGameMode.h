// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "EndlessRunnerGameMode.generated.h"

class UBoxComponent;

UCLASS()

class AEndlessRunnerGameMode : public AGameModeBase
{
 GENERATED_BODY()


public:
 AEndlessRunnerGameMode();

 UPROPERTY(EditAnywhere)
 USceneComponent* DefaultRoot;
	
 UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Triggers")
 UBoxComponent* CPPLevelBounds;
	
 UPROPERTY(EditAnywhere)
 int CPPNumberOfLanes = 3;
 UPROPERTY(EditAnywhere)
 float CPPLaneWidth = 250.f;
 UPROPERTY(EditAnywhere)
 float CPPLevelSpeed = -500.f;
	
 UPROPERTY(BlueprintReadWrite, EditAnywhere)
 FVector CPPOutOfBoundBoxScale = FVector(0.f,0.f,0.f);
 UPROPERTY(BlueprintReadWrite, EditAnywhere,  Meta = (MakeEditWidget = true))
 FVector CPPOutOfBoundBoxLocation = FVector(0.f,0.f,0.f);
 //TArray<FVector> ObstacleRelativeOffsets;



};