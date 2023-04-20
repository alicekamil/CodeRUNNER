// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPLevelManager.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "TargetInterfaces/MeshTargetInterfaceTypes.h"
// Sets default values
ACPPLevelManager::ACPPLevelManager()
{	
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Defaultoot"));
	RootComponent = DefaultRoot;
		
	CPPLevelBounds = CreateDefaultSubobject<UBoxComponent>(FName("CPPLevelBounds"));
	CPPLevelBounds->SetupAttachment(DefaultRoot);
	//CPPLevelBounds->SetBoxExtent(CPPOutOfBoundBoxScale, true);
	//CPPLevelBounds->SetWorldLocation(CPPOutOfBoundBoxLocation);
	
	
}
	
// Called when the game starts or when spawned
void ACPPLevelManager::BeginPlay()
{
	Super::BeginPlay();
	
	
	if (CPPLevelBounds != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("CPPLevelBounds works"));
	}
	
	
	
}

// Called every frame
void ACPPLevelManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

