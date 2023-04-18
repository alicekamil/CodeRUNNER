// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPLevelManager.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
// Sets default values
ACPPLevelManager::ACPPLevelManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CreateDefaultSubobject<UBoxComponent>(FName("BoxCollider"));
	//BoxCollider->SetBoxExtent(FVector(CPPOutOfBoundBoxScale));
	//BoxCollider->SetupAttachment(GetRootComponent());
	//BoxCollider->SetGenerateOverlapEvents(true);
	
	BoxCollider->SetWorldLocation(CPPOutOfBoundBoxLocation);
}

// Called when the game starts or when spawned
void ACPPLevelManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACPPLevelManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

