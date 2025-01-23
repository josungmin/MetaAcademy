#include "AnimInstances/CharacterAnimInstance.h"
#include "HamsterCharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"


void UCharacterAnimInstance::NativeInitializeAnimation()
{
	OwnerCharacter = Cast<AHamsterCharacterBase>(TryGetPawnOwner());
	if (!OwnerCharacter)
	{
		return;
	}

	OwnerMovementComponent = OwnerCharacter->GetCharacterMovement();
}

void UCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwnerCharacter || OwnerMovementComponent)
	{
		check("if (!OwnerCharacter || OwnerMovementComponent)")
		return;
	}
	
	Velocity = OwnerMovementComponent->Velocity;
	GroundSpeed = Velocity.Size2D();
	bIsFalling = OwnerMovementComponent->IsFalling();

	bIsAcceleration = OwnerMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.0f;
	UE_LOG(LogTemp, Warning, TEXT("%s"), bIsAcceleration);

	bShouldMove = (GroundSpeed > 3.0f) & bIsAcceleration;
}
