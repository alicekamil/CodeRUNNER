#include "CPPlatform.h"

// Sets default values
ACPPlatform::ACPPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ACPPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	//AActor SpawnedActor = UWorld::SpawnActor(this, FVector(-0.0f,0.f,-1000.f), );
}

// Called every frame
void ACPPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

