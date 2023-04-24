// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPPawnBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/Engine.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Containers/Array.h"

// Sets default values
ACPPPawnBase::ACPPPawnBase()
{
	PrimaryActorTick.bCanEverTick = true;
	CPPSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultfbnfghRoot"));
	SetRootComponent(CPPSceneRoot);
	PawnMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PawnMesh"));
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));

	SpringArmCPP = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmCPP"));
	SpringArmCPP->SetupAttachment(RootComponent);
	SpringArmCPP->TargetArmLength = 800.f;
	
	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCameraCPP"));
	ViewCamera->SetupAttachment(SpringArmCPP);
	
	//AutoPossessPlayer = EAutoReceiveInput::Player0; ?
}

// Called when the game starts or when spawned
void ACPPPawnBase::BeginPlay()
{
	Super::BeginPlay();
	
	
}
// Called every frame
void ACPPPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*GetGameMode
	 *
	 *
	 *
	 * 
	 */
}

// Called to bind functionality to input
void ACPPPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

