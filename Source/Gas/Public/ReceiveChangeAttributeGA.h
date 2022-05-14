// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyGameplayAbility.h"
#include "ReceiveChangeAttributeGA.generated.h"

//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReceiveChangeAttributeDelegate, const float, OnChangeValue);	//こちらだとBPで使えない (イベントディスパッチャー)
DECLARE_DYNAMIC_DELEGATE_OneParam(FReceiveChangeAttributeDelegate, const float, OnChangeValue); //イベント。呼べなくね？

/**
 * 
 */
UCLASS()
class GAS_API UReceiveChangeAttributeGA : public UMyGameplayAbility
{
	GENERATED_BODY()
	

public:

	UFUNCTION(BlueprintCallable)
	void CallOnReceiveChangeAttribute(float value);

	//UPROPERTY(BlueprintAssignable, BlueprintCallable)
	UPROPERTY(BlueprintReadWrite)
	FReceiveChangeAttributeDelegate OnReceiveChangeAttribute;
};
