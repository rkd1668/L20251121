// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TestCharacter.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
	uint8 bLeftLean : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
	uint8 bRightLean : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
	uint8 bAiming : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
	float CurrentLeanAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
	EWeaponState WeaponState = EWeaponState::Unarmed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
	uint8 bCrouch : 1;
};
