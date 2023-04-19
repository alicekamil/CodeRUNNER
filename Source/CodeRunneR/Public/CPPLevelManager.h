// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPLevelManager.generated.h"

class UBoxComponent;

UCLASS()
class CODERUNNER_API ACPPLevelManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPLevelManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Triggers")
	UBoxComponent* BoxCollider; 

public:	
	UPROPERTY(EditAnywhere)
	int CPPNumberOfLanes = 3;
	UPROPERTY(EditAnywhere)
	float CPPLaneWidth = 250.f;
	UPROPERTY(EditAnywhere)
	float CPPLevelSpeed = -500.f;

//	UPROPERTY(EditAnywhere)
//	FVector CPPOutOfBoundBoxScale = FVector(1000.f,1000.f,1000.f);
//	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
//	FVector CPPOutOfBoundBoxLocation = FVector(0,0,0);
};
