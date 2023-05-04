#include "Obstacle.h"

AObstacle::AObstacle()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = SceneComponent;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMesh->SetupAttachment(SceneComponent);
	
}

void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

