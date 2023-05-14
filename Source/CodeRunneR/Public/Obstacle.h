#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

class UBoxComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FObstacleCollisionDelegate);

UCLASS()
class CODERUNNER_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	AObstacle();

	void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* Other) override;

	UPROPERTY(BlueprintAssignable)
	FObstacleCollisionDelegate OnCollisionWithPlayerEvent;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere)
	class USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxCollider;

protected:
	virtual void BeginPlay() override;
};
