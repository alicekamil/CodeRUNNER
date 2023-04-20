// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Containers/Array.h"
#include "GameFramework/Pawn.h"
#include "CPPPawnBase.generated.h"

UCLASS()
class CODERUNNER_API ACPPPawnBase : public APawn
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	class ACPPLevelManager* ForwardedLevelManager; //Forward declaration
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* ForwardedCamera;
	

public:
	// Sets default values for this pawn's properties
	ACPPPawnBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void MoveRight(float value);



	//class UCameraComponent* GetCameraComponent() const
	//{
	//	return ForwardedCamera;
	//}
};
	
	
