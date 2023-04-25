#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPFloorBase.generated.h"

class AEndlessRunnerGameMode;

UCLASS()
class CODERUNNER_API ACPPFloorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPPFloorBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

protected:
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* BaseSceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* Mesh;

	FVector Movement;
	
};
