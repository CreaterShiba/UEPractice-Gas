// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "PlayerAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class GAS_API UPlayerAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	// コンストラクタの定義
	UPlayerAttributeSet();

	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	// スタミナ値の保持
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UPlayerAttributeSet, Stamina)

		// HP
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FGameplayAttributeData HitPoint;
	ATTRIBUTE_ACCESSORS(UPlayerAttributeSet, HitPoint)
};
