
#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	DefaultHealth = 3.f;
	Health = DefaultHealth;
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();
	if (Owner)
	{
		//Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Cfff")));
	}
}

/*void UHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser)
{
	if(Damage <= 0)
	{
		return;
	}
	
	Health = Health - Damage;
	
}*/



