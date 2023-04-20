// Fill out your copyright notice in the Description page of Project Settings.


#include "Singleton.h"

ASingleton* ASingleton::Instance = nullptr;

ASingleton::ASingleton()
{
	MyLevelManager = nullptr;
}

ASingleton* ASingleton::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = NewObject<ASingleton>();
		check(Instance);
	}
	return Instance;
}

ACPPLevelManager* ASingleton::GetLevelManager() const
{
	return MyLevelManager;
}

void ASingleton::BeginPlay()
{
	Super::BeginPlay();
	MyLevelManager = NewObject<ACPPLevelManager>();
	check(MyLevelManager);
}

void ASingleton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

