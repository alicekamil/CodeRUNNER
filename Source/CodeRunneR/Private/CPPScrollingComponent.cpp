#include "CPPScrollingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EndlessRunnerGameMode.h"


// Sets default values for this component's properties
UCPPScrollingComponent::UCPPScrollingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
void UCPPScrollingComponent::BeginPlay()
{
	Super::BeginPlay();
	Mode = Cast<AEndlessRunnerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	
}

// Called every frame
void UCPPScrollingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* Parent = GetOwner();
	if (Parent)
	{
		Movement = (Parent->GetActorForwardVector() * Mode->CPPLevelSpeed) * DeltaTime; 
		Parent->AddActorLocalOffset(Movement);
	}
};

