#pragma once
#include "CoreMinimal.h"
#include "AnimInstances/HamsetAnimInstanceBase.h"
#include "CharacterAnimInstance.generated.h"

class AHamsterCharacterBase;
class UCharacterMovementComponent;

UCLASS()
class HAMSTER_API UCharacterAnimInstance : public UHamsetAnimInstanceBase
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	FVector Velocity;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	uint32 bShouldMove : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	uint32 bIsFalling : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	uint32 bIsAcceleration : 1;

private:
	AHamsterCharacterBase* OwnerCharacter;
	UCharacterMovementComponent* OwnerMovementComponent;
};
