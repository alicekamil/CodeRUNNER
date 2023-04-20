// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPPawnBase.h"

// Sets default values
ACPPPawnBase::ACPPPawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ACPPPawnBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPPPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPPPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

