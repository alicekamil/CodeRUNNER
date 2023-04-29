#include "CPPFloorSide.h"
#include "Components/BoxComponent.h"
#include "Components/InstancedStaticMeshComponent.h"


//ACPPFloorSide::ACPPFloorSide(const class FObjectInitializer& PCIP) : Super(PCIP)

ACPPFloorSide::ACPPFloorSide()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	InstancedMesh = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Instanced Mesh"));
	InstancedMesh->SetupAttachment(ACPPFloorBase::Mesh);
	InstancedMesh->SetWorldLocation(Box->GetRelativeLocation());
	//ClearInstanceComponents()
	
}
	
	

	



