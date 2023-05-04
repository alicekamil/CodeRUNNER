#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBaseClass.generated.h"

class AEndlessRunnerGameMode;
class UCapsuleComponent;
class USkeletalMeshComponent;

UCLASS()
class CODERUNNER_API APawnBaseClass : public APawn
{
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	APawnBaseClass();

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
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MoveLane(int direction);
	void UpdatePosition();
public:    
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY()
	AEndlessRunnerGameMode* Mode;
    
	int CurrentLane;
	int PlayerIndex;
	bool Initialised;
};