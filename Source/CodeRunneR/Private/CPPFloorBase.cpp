#include "CPPFloorBase.h"
#include "Kismet/GameplayStatics.h"
#include "EndlessRunnerGameMode.h"


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
	Mode = Cast<AEndlessRunnerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	
}
void ACPPFloorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	Movement = (GetActorForwardVector() * Mode->CPPLevelSpeed) * DeltaTime; 
	AddActorLocalOffset(Movement);
}

