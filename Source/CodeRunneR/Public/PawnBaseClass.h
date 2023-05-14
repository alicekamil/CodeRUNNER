#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBaseClass.generated.h"

class AEndlessRunnerGameMode;
class AObstacle;
class UCapsuleComponent;
class USkeletalMeshComponent;


UCLASS()
class CODERUNNER_API APawnBaseClass : public APawn
{
	GENERATED_BODY()
public:
	APawnBaseClass();
	
	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Capsule;
	
	
	void Right();
	void Left();
	void AssignIndex(int index);
	int GetIndex();


protected:

	virtual void BeginPlay() override;
	void MoveLane(int direction);
	void UpdatePosition();

private:
	UPROPERTY()
	AEndlessRunnerGameMode* Mode;

    
	int CurrentLane;
	int PlayerIndex;
	bool Initialised;
};