#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "HamsterCharacterBase.generated.h"

class UHamsterAbilitySystemComponent;
class UHamsterAttributeSet;
class UDataAsset_SetupDataBase;

UCLASS()
class HAMSTER_API AHamsterCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AHamsterCharacterBase();

protected:
	virtual void BeginPlay() override;

protected:
	// ~Begin APawn Interfaces
	virtual void PossessedBy(AController* NewController) override;
	// ~End APawn Interfaces

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UHamsterAbilitySystemComponent* HamsterAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UHamsterAttributeSet* HamsterAtributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	TSoftObjectPtr<UDataAsset_SetupDataBase> CharacterSetupData;


public:
	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface Interface

public:
	FORCEINLINE UHamsterAbilitySystemComponent* GetHamsterAbilitySystemComponent() const {return HamsterAbilitySystemComponent; }
	FORCEINLINE UHamsterAttributeSet* GetHamsterAttributeSet() const { return HamsterAtributeSet; }
};
