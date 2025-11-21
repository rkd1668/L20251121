// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TestAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class L20251112_API UTestAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
	float GroundSpeed = 0.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
	uint8 bSprint : 1;

	UFUNCTION()
	void AnimNotify_SkeletonNotify();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
	float Direction;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
	float AimYaw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
	float AimPitch;
};
