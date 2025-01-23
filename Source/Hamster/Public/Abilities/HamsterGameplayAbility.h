#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "HamsterGameplayAbility.generated.h"

UENUM(BlueprintType)
enum class EAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};

UCLASS()
class HAMSTER_API UHamsterGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	// Begin UGameplayAbility Interface
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	// End UGameplayAbility Interface
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	EAbilityActivationPolicy AbilityActivationPolicy = EAbilityActivationPolicy::OnGiven;
};
