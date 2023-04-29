
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CPPScrollingComponent.generated.h"

class AEndlessRunnerGameMode;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CODERUNNER_API UCPPScrollingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCPPScrollingComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	AEndlessRunnerGameMode* Mode;
	
	FVector Movement;
};
