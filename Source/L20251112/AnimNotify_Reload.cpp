// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_Reload.h"
#include "TestCharacter.h"

FString UAnimNotify_Reload::GetNotifyName_Implementation() const
{
	return TEXT("Reload");
}

void UAnimNotify_Reload::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	ATestCharacter* BaseCharacter = Cast<ATestCharacter>(MeshComp->GetOwner());
	if (BaseCharacter)
	{
		BaseCharacter->ReloadWeapon();
	}
}
