#pragma once

#include "CoreMinimal.h"
#include "CPPFloorBase.h"
#include "CPPFloorSide.generated.h"

class UBoxComponent;

UCLASS()
class CODERUNNER_API ACPPFloorSide : public ACPPFloorBase
{
	GENERATED_BODY()

public:
	ACPPFloorSide();


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,  meta = (AllowPrivateAccess = true))
	UBoxComponent* Box;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,  meta = (AllowPrivateAccess = true))
	UInstancedStaticMeshComponent* InstancedMesh;
};

