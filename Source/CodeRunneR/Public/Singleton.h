// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPLevelManager.h"
#include "GameFramework/Actor.h"
#include "Singleton.generated.h"

UCLASS()
class CODERUNNER_API ASingleton : public AActor
{
	GENERATED_BODY()
	
public:	
	static ASingleton* GetInstance();
	ACPPLevelManager* GetLevelManager() const;
private:
	ASingleton();
	static ASingleton* Instance;
	UPROPERTY()
	ACPPLevelManager* MyLevelManager;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
