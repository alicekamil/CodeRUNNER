#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "Containers/Array.h"
#include "CPPPawnBase.generated.h"

class AEndlessRunnerGameMode;
class USpringArmComponent;
class UCapsuleComponent;
class USkeletalMeshComponent;
class UCameraComponent;

UCLASS()

class CODERUNNER_API ACPPPawnBase : public APawn
{
	GENERATED_BODY()

public:
	ACPPPawnBase();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	class USceneComponent* CPPSceneRoot;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void BeginPlay() override;
	void Left();
	void Right();
	void MoveLane(int direction);
private:
	int currentLane;
	int laneWidth;
	float targetPosition;
	bool isMoving;
	
	AEndlessRunnerGameMode* Mode;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* PawnMesh;
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Capsule;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmCPP;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;
};