// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask_WaitAttributeChange.h"
#include "MyAbilityTask_WAC.generated.h"

/**
 * 
 */
UCLASS()
class GAS_API UMyAbilityTask_WAC : public UAbilityTask_WaitAttributeChange
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
		static UAbilityTask_WaitAttributeChange* MyWaitForAttributeChange(UGameplayAbility* OwningAbility, FGameplayAttribute Attribute, FGameplayTag WithSrcTag, FGameplayTag WithoutSrcTag, bool TriggerOnce = true, AActor* OptionalExternalOwner = nullptr);


	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
		static bool MyTwoWaitForAttributeChange(UGameplayAbility* OwningAbility, FGameplayAttribute Attribute, FGameplayTag WithSrcTag, FGameplayTag WithoutSrcTag, bool TriggerOnce = true, AActor* OptionalExternalOwner = nullptr);
};
