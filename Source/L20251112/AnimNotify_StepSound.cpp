// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_StepSound.h"

FString UAnimNotify_StepSound::GetNotifyName_Implementation() const
{
	return TEXT("StepSound");
}

void UAnimNotify_StepSound::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	UE_LOG(LogTemp, Warning, TEXT("C++ Notify %d"), Gold);
}