#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "RunnerCharacter.generated.h"

class AEndlessRunnerGameMode;
class USpringArmComponent;
class UCapsuleComponent;
class USkeletalMeshComponent;
class UCameraComponent;

UCLASS()
class CODERUNNER_API ARunnerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ARunnerCharacter();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	class USceneComponent* CPPSceneRoot;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void RestarttheLevel();
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, //TODO: Move logic to obstacle?
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

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
