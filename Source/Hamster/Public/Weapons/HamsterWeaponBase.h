#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HamsterWeaponBase.generated.h"

class UBoxComponent;

UCLASS()
class HAMSTER_API AHamsterWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AHamsterWeaponBase();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	UBoxComponent* WeaponCollisionBox;

public:
	FORCEINLINE UBoxComponent* GetWeaponCollisionBox() const { return WeaponCollisionBox; }
};
