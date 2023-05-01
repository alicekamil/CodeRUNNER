#include "RunnerCharacter.h"

#include "EndlessRunnerGameMode.h"
#include "GameFramework/Actor.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Obstacle.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "Containers/Array.h"

ARunnerCharacter::ARunnerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(35.f, 75.f);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel1, ECR_Overlap); //TODO: Lookup
	
	CPPSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultfbnfghRoot"));
	SetRootComponent(CPPSceneRoot);

	SpringArmCPP = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmCPP"));
	SpringArmCPP->SetupAttachment(RootComponent);
	SpringArmCPP->TargetArmLength = 800.f;

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCameraCPP"));
	ViewCamera->SetupAttachment(SpringArmCPP);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void ARunnerCharacter::BeginPlay()
{
	Super::BeginPlay();

	Mode = Cast<AEndlessRunnerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if(Mode)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("Theres a mode!")));
	}
	currentLane = Mode->CPPNumberOfLanes / 2; //Start with the middle lane (1)

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ARunnerCharacter::OnOverlapBegin); // TODO: lookup beginoverlap 
	
}

void ARunnerCharacter::RestarttheLevel()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName())); // TODO: move to gamemode?
}

void ARunnerCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, // Detect collision
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor != nullptr)
	{
		AObstacle* Obstacle = Cast<AObstacle>(OtherActor);

		if(Obstacle)
		{
			GetMesh()->Deactivate();
			GetMesh()->SetVisibility(false);

			// TODO: move set to false

			FTimerHandle UnusedHandle;
			GetWorldTimerManager().SetTimer(UnusedHandle, this, &ARunnerCharacter::RestarttheLevel, 2.f, false); //TODO: Move to gamemode?

			//TODO: save score
			
		}
	}
}

void ARunnerCharacter::Left()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("LEFT!")));
	MoveLane(-1);
}

void ARunnerCharacter::Right()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("RIGHT!")));
	MoveLane(1);
}

void ARunnerCharacter::MoveLane(int direction)
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
void ARunnerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ARunnerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Left", IE_Pressed, this, &ARunnerCharacter::Left);
	PlayerInputComponent->BindAction("Right", IE_Pressed, this, &ARunnerCharacter::Right);
}

