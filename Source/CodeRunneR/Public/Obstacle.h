#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class CODERUNNER_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	AObstacle();

	UPROPERTY(VisibleAnywhere)
	class USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* StaticMesh;
	

protected:
	virtual void BeginPlay() override;
	

};
