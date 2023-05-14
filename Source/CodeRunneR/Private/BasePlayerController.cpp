#include "BasePlayerController.h"
#include "PawnBaseClass.h"
#include "Kismet/GameplayStatics.h"
#include "EndlessRunnerGameMode.h"


ABasePlayerController::ABasePlayerController()
{
	gameMode = Cast<AEndlessRunnerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	
}

void ABasePlayerController::BeginPlay()
{
	
	Super::BeginPlay();
	
	
	Player1 = Cast<APawnBaseClass>(GetPawn()); 
	Player2 = GetWorld()->SpawnActor<APawnBaseClass>(GetWorld()->GetAuthGameMode()->DefaultPawnClass, FVector(0, 250, 0), FRotator(0, 0, 0));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Spawning players!")));

	Player1->AssignIndex(0);
	Player2->AssignIndex(1);
	
	InputComponent->BindAction("Left1", IE_Pressed, this, &ABasePlayerController::CallLeft1);
	InputComponent->BindAction("Right1", IE_Pressed, this, &ABasePlayerController::CallRight1);
	
	InputComponent->BindAction("Left2", IE_Pressed, this, &ABasePlayerController::CallLeft2);
	InputComponent->BindAction("Right2", IE_Pressed, this, &ABasePlayerController::CallRight2);
	

	/*if(!Player1)
	{
		Player1 = GetWorld()->SpawnActor<ARunnerCharacter>(PawnToSpawn, FVector(0,0,0), FRotator(0,0,0));
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("P1")));
	}
	if(!Player2)
	{
		Player2 = GetWorld()->SpawnActor<ARunnerCharacter>(PawnToSpawn, FVector(0,100,0), FRotator(0,0,0));
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("Spawned P2")));
		Possess(Player2);
	}*/
}

void ABasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
}
void ABasePlayerController::CallLeft1()
{
	if (Player1)
	{
		Player1->Left();
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("CallLeft1")));
	}
}
void ABasePlayerController::CallRight1()
{
	if (Player1)
	Player1->Right();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("CallRight1")));
}
void ABasePlayerController::CallLeft2()
{
	if (Player2)
	{
		Player2->Left();
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("CallLeft2")));
	}
}
void ABasePlayerController::CallRight2()
{
	if (Player2)
	Player2->Right();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("CallRight2")));
}

 void ABasePlayerController::Tick(float DeltaTime)
 {
	Super::Tick(DeltaTime);
 }





