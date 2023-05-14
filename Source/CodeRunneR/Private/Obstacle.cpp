#include "Obstacle.h"
#include "PawnBaseClass.h"
#include "Engine/Engine.h"
#include "Components/BoxComponent.h"

AObstacle::AObstacle()
{
	PrimaryActorTick.bCanEverTick = true;
	
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	BoxCollider->SetBoxExtent(FVector(32.f,32.f,32.f));
	BoxCollider->SetCollisionProfileName("Trigger");
	RootComponent = BoxCollider;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMesh->SetupAttachment(RootComponent);
	
}

void AObstacle::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Check if OtherActor is an instance of the PawnBaseClass
	if (APawnBaseClass* PawnBase = Cast<APawnBaseClass>(OtherActor))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Collided")));
	}
}


void AObstacle::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	// Check if OtherActor is an instance of the PawnBaseClass
	if (APawnBaseClass* PawnBase = Cast<APawnBaseClass>(OtherActor))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Collided end")));
	}
}


void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AObstacle::OnOverlapBegin);
	BoxCollider->OnComponentEndOverlap.AddDynamic(this, &AObstacle::OnOverlapEnd);
	
}
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AObstacle::NotifyActorBeginOverlap(AActor* Other)
{
	Super::NotifyActorBeginOverlap(Other);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("NotifyActor")));
	
}

