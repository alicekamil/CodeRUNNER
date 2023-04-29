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
			Parent->Destroy();
		}
	}
};

