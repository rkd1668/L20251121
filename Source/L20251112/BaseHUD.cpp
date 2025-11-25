// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseHUD.h"
#include "Engine/Canvas.h"
#include "TestCharacter.h"
#include "KismetAnimationLibrary.h"

void ABaseHUD::DrawHUD()
{
	Super::DrawHUD();

	ATestCharacter* Character = Cast<ATestCharacter>(PlayerOwner->GetCharacter());

	int32 UnitX = Canvas->SizeX / 100;
	int32 UnitY = Canvas->SizeY / 100;
	int32 CenterX = Canvas->SizeX / 2;
	int32 CenterY = Canvas->SizeY / 2;
	int32 DrawSize = 4;
	float TargetDist = 0;
	Draw2DLine(CenterX - (UnitX * DrawSize) - Dist, CenterY, CenterX - Dist, CenterY, FColor::Red);
	Draw2DLine(CenterX + Dist, CenterY, CenterX + (UnitX * DrawSize) + Dist, CenterY, FColor::Red);
	Draw2DLine(CenterX, CenterY - (UnitX * DrawSize) - Dist, CenterX, CenterY - Dist, FColor::Red);
	Draw2DLine(CenterX, CenterY + Dist, CenterX, CenterY + (UnitX * DrawSize) + Dist, FColor::Red);

	if (Character->GetVelocity() != FVector(0, 0, 0))
	{
		UE_LOG(LogTemp, Warning, TEXT("Draw Hud"));
		TargetDist = 30;
	}
	else
	{
		TargetDist = 0;
	}
	
	Dist = FMath::FInterpTo(Dist, TargetDist, GetWorld()->GetDeltaSeconds(), 5.0f);
}