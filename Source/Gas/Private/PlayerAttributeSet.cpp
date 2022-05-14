// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAttributeSet.h"
#include "..\Public\PlayerAttributeSet.h"

UPlayerAttributeSet::UPlayerAttributeSet() :
	Stamina(100.f),
	HitPoint(1000.0f)
{
}

void UPlayerAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	// スタミナ値の更新が走った場合はスタミナ値をMaxとMinの間に収まるようにする
	//if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	//{
	//	SetStamina(FMath::Clamp(GetStamina(), 0.f, 100.f));
	//}
}
