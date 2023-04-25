#include "CPPPawnBase.h"

#include "EndlessRunnerGameMode.h"
#include "GameFramework/Actor.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/Engine.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Containers/Array.h"

// Sets default values
ACPPPawnBase::ACPPPawnBase()
{
    PrimaryActorTick.bCanEverTick = true;
    CPPSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultfbnfghRoot"));
    SetRootComponent(CPPSceneRoot);
    PawnMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PawnMesh"));
    PawnMesh->SetupAttachment(RootComponent);
    Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
    Capsule->SetupAttachment(RootComponent);

    SpringArmCPP = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmCPP"));
    SpringArmCPP->SetupAttachment(RootComponent);
    SpringArmCPP->TargetArmLength = 800.f;

    ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCameraCPP"));
    ViewCamera->SetupAttachment(SpringArmCPP);

    AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ACPPPawnBase::BeginPlay()
{
    Super::BeginPlay();

    Mode = Cast<AEndlessRunnerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
    if(Mode)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("Theres a mode!")));
    }
    currentLane = Mode->CPPNumberOfLanes / 2; //Start with the middle lane (1)
    //Mode->CPPLaneWidth
}

void ACPPPawnBase::Left()
{
    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("LEFT!")));
    MoveLane(-1);
}

void ACPPPawnBase::Right()
{
    GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("RIGHT!")));
    MoveLane(1);
}

void ACPPPawnBase::MoveLane(int direction)
{
    //if (isMoving) return;
    // Tries to move the character lane in a direction
    int newLane = currentLane + direction;
    // Check if we are moving within legal limits
    if (newLane < 0 || newLane > Mode->CPPNumberOfLanes - 1) return;
    
    isMoving = true;
    // Update current lane
    currentLane = newLane;
    targetPosition = (currentLane - Mode->CPPNumberOfLanes / 2) * Mode->CPPLaneWidth;

    // Move actor
    FVector currentPosition = GetActorLocation();
    currentPosition.Y = targetPosition;
    SetActorLocation(currentPosition);
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

    PlayerInputComponent->BindAction("Left", IE_Pressed, this, &ACPPPawnBase::Left);
    PlayerInputComponent->BindAction("Right", IE_Pressed, this, &ACPPPawnBase::Right);
}
