// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "Containers/Array.h"
#include "CPPPawnBase.generated.h"

class USpringArmComponent;
class UCapsuleComponent;
class USkeletalMeshComponent;
class UCameraComponent;

UCLASS()

class CODERUNNER_API ACPPPawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACPPPawnBase();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	class USceneComponent* CPPSceneRoot;
	
		// Called to bind functionality to input
    	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:

	
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* PawnMesh;
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Capsule;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmCPP;
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;
};
	
	
