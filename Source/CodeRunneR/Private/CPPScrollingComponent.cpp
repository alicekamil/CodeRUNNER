#include "CPPScrollingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EndlessRunnerGameMode.h"

UCPPScrollingComponent::UCPPScrollingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}
void UCPPScrollingComponent::BeginPlay()
{
	Super::BeginPlay();
	Mode = Cast<AEndlessRunnerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

void UCPPScrollingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* Parent = GetOwner();
	if (Parent)
	{
		Movement = (Parent->GetActorForwardVector() * Mode->CPPLevelSpeed) * DeltaTime; 
		Parent->AddActorLocalOffset(-Movement);
		if (Parent->GetActorLocation().X < Mode->OutOfBoundsLoc)
		{
			// 10% chance of explosion
			if (FMath::FRandRange(0.0f, 1.0f) < 0.0167f)
			{
				GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("10")));
			}
			Parent->Destroy();
		}
	}
};

