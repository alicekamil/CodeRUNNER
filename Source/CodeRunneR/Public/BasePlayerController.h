#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

class AEndlessRunnerGameMode;
class APawnBaseClass;

UCLASS()
class CODERUNNER_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ABasePlayerController();
	
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	virtual void Tick(float DeltaTime) override;

	AEndlessRunnerGameMode* gameMode;
	UPROPERTY(VisibleAnywhere)
	APawnBaseClass* Player1;
	UPROPERTY(VisibleAnywhere)
	APawnBaseClass* Player2;
	
	void CallLeft1();
	void CallLeft2();
	void CallRight1();
	void CallRight2();
	
	
};
