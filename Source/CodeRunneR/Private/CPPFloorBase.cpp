#include "CPPFloorBase.h"
#include "Kismet/GameplayStatics.h"

ACPPFloorBase::ACPPFloorBase()
{
	PrimaryActorTick.bCanEverTick = true;
	BaseSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("BaseSceneRoot"));
	RootComponent = BaseSceneRoot;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorMesh"));
	Mesh->SetupAttachment(RootComponent);
}
void ACPPFloorBase::BeginPlay()
{
	Super::BeginPlay();
}
void ACPPFloorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

