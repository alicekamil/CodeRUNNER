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
};
