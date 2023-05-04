#include "PawnBaseClass.h"

#include "EndlessRunnerGameMode.h"
#include "Obstacle.h"
#include "GameFramework/Actor.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/Engine.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Containers/Array.h"

APawnBaseClass::APawnBaseClass()
{
	PrimaryActorTick.bCanEverTick = true;
    
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);
    Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
    Mesh->SetupAttachment(RootComponent);
    Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
    Capsule->SetupAttachment(RootComponent);


    AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void APawnBaseClass::BeginPlay()
{
	Super::BeginPlay();
	Mode = GetWorld()->GetAuthGameMode<AEndlessRunnerGameMode>();
}

void APawnBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!Initialised)
	{
		Initialised = true;
		CurrentLane = PlayerIndex == 0 ? 0 : Mode->CPPNumberOfLanes - 1;
		UpdatePosition();
		UE_LOG(LogTemp, Warning, TEXT("Initialised Player Index: %d, Player Lane: %d"), PlayerIndex, CurrentLane);
	}
}

void APawnBaseClass::Right()
{
	MoveLane(1);
}

void APawnBaseClass::Left()
{
	MoveLane(-1);
}

void APawnBaseClass::AssignIndex(int index)
{
	PlayerIndex = index;
	Initialised = false;
	UE_LOG(LogTemp, Warning, TEXT("Assigned Player Index: %d"), PlayerIndex);
}

void APawnBaseClass::MoveLane(int direction)
{
    // Tries to move the character lane in a direction
    const int NewLane = CurrentLane + direction;
    // Check if we are moving within legal limits
    if (NewLane < 0 || NewLane > Mode->CPPNumberOfLanes - 1) return;
	
    // Update current lane
    CurrentLane = NewLane;
	UpdatePosition();
}

void APawnBaseClass::UpdatePosition()
{
	const float TargetPosition = (CurrentLane - Mode->CPPNumberOfLanes / 2) * Mode->CPPLaneWidth; //?

	// Move actor
	FVector CurrentPosition = GetActorLocation();
	CurrentPosition.Y = TargetPosition;
	CurrentPosition.Z = 0;
	SetActorLocation(CurrentPosition);
}

void APawnBaseClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
