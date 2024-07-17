// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor // A는 액터를 나타낸다
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// 게임 플레이 시작할 때 바로 실행될 코드
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category="Moving")
	FVector PlatformVelocity = FVector(100,0,0);

	UPROPERTY(EditAnywhere, Category="Moving")
	float MoveDistance = 100;

	UPROPERTY(EditAnywhere, Category="Rotation")
	FRotator RotationVelocity;

	// 블루프린트에 노출되는 변수가 아니라 C++ 스크립트에서만 필요한 변수이기에 UPROPERTY를 붙이지 않는다.
	FVector StartLocation;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn();
	float GetDistanceMoved() const;
};
