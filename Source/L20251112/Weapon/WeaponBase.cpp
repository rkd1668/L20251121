// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "BaseDamageType.h"
#include "Engine/DamageEvents.h"
#include "GameFramework/Character.h"
#include "TimerManager.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeaponBase::Reload()
{
	CurrentBulletCount = MaxBulletCount;
	UE_LOG(LogTemp, Warning, TEXT("Reload bullet %d"), CurrentBulletCount);
}

void AWeaponBase::Fire()
{
	float CurrentTimeOfShoot = GetWorld()->TimeSeconds - TimeOfLastShoot;

	if (CurrentTimeOfShoot < ReFireRate)
	{
		return;
	}

	if (bFullAtuo)
	{
		GetWorld()->GetTimerManager().SetTimer(ReFireTimer, this, &AWeaponBase::Fire, ReFireRate, false);
	}

	ACharacter* Character = Cast<ACharacter>(GetOwner());
	
	ensure(Character);
	if (!Character)
	{
		return;
	}
	APlayerController* PC = Cast<APlayerController>(Character->GetController());
	if (PC)
	{
		int32 SizeX = 0;
		int32 SizeY = 0;
		int32 CenterX = 0;
		int32 CenterY = 0;
		FVector WorldDirection;
		FVector WorldLocation;
		FVector CameraLocation;
		FRotator CameraRotation;

		PC->GetViewportSize(SizeX, SizeY);
		CenterX = SizeX / 2;
		CenterY = SizeY / 2;

		//PC->DeprojectMousePositionToWorld();
		PC->DeprojectScreenPositionToWorld((float)CenterX, (float)CenterY, WorldLocation, WorldDirection);

		PC->GetPlayerViewPoint(CameraLocation, CameraRotation);

		FVector Start = CameraLocation;
		FVector End = CameraLocation + WorldDirection * 100000.0f;

		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldDynamic));
		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic));
		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_PhysicsBody));

		TArray<AActor*> IgnoreActors;

		FHitResult HitResult;

		bool bResult = UKismetSystemLibrary::LineTraceSingleForObjects(
			GetWorld(),
			Start,
			End,
			ObjectTypes,
			true,
			IgnoreActors,
			EDrawDebugTrace::ForDuration,
			HitResult,
			true
		);
		if (bResult)
		{
			//UGameplayStatics::ApplyDamage(HitResult.GetActor(),
			//	50,
			//	GetController(),
			//	this,
			//	UBaseDamageType::StaticClass()
			//);
			UGameplayStatics::ApplyPointDamage(HitResult.GetActor(),
				10,
				-HitResult.ImpactNormal,
				HitResult,
				PC,
				this,
				UBaseDamageType::StaticClass()
			);
			//UGameplayStatics::ApplyRadialDamage(HitResult.GetActor(),
			//	10,
			//	HitResult.ImpactPoint,
			//	300.0f,
			//	UBaseDamageType::StaticClass(),
			//	IgnoreActors,
			//	this,
			//	GetController(),
			//	true
			//);

			//UE_LOG(LogTemp, Warning, TEXT("Hit %s"), *HitResult.GetActor()->GetName());
		}
	}

	CurrentBulletCount--;
	UE_LOG(LogTemp, Warning, TEXT("Fire %d"), CurrentBulletCount);
	UGameplayStatics::SpawnSoundAtLocation(GetWorld(), FireSound, GetActorLocation());

	TimeOfLastShoot = GetWorld()->TimeSeconds;
}

void AWeaponBase::FireProjectile()
{
}

void AWeaponBase::StopFire()
{
	GetWorld()->GetTimerManager().ClearTimer(ReFireTimer);
}
