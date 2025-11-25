// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_DeathEnd.h"
#include "TestCharacter.h"

FString UAnimNotify_DeathEnd::GetNotifyName_Implementation() const
{
	return TEXT("DeathEnd");
}

void UAnimNotify_DeathEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	ATestCharacter* Pawn = Cast<ATestCharacter>(MeshComp->GetOwner());
	if (Pawn)
	{
		Pawn->DoDeathEnd();
	}
}

