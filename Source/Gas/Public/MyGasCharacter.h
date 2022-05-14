// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../GasCharacter.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "PlayerAttributeSet.h"
#include "MyGasCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GAS_API AMyGasCharacter : public AGasCharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AMyGasCharacter();

public:
	UAbilitySystemComponent* GetAbilitySystemComponent() const
	{
		return AbilitySystemComponent;
	}

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	UAbilitySystemComponent* AbilitySystemComponent;

	UFUNCTION(BlueprintCallable, meta = (DefaultToSelf = "Target"))
	void AddAbility(TSubclassOf<UGameplayAbility> Ability, int32 AbilityLevel);

	UFUNCTION(BlueprintCallable, meta = (DefaultToSelf = "Target"))
	bool ActivateAbilitiesWithTags(FGameplayTagContainer AbilityTags, bool bAllowRemoteActivation);

	// Effect‚Ì“o˜^
	UFUNCTION(BlueprintCallable, meta = (DefaultToSelf = "Target"))
	void AddEffect(TSubclassOf<class UGameplayEffect> Effect, int32 EffectLevel);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPlayerAttributeSet* PlayerAttributeSet;
};
