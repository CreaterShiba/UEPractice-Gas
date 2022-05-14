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

	// �X�^�~�i�l�̍X�V���������ꍇ�̓X�^�~�i�l��Max��Min�̊ԂɎ��܂�悤�ɂ���
	//if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	//{
	//	SetStamina(FMath::Clamp(GetStamina(), 0.f, 100.f));
	//}
}
