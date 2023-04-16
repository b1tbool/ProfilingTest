// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BestActor.generated.h"

UCLASS()
class PROFILINGTEST_API ABestActor : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (UIMin = 1, ClampMin = 1))
	int CycleCount = 1;

private:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* SMComponent;

	float Calculations = 0.f;

public:
	ABestActor();

private:
	UFUNCTION()
	void GoodBeginOverlap(UPrimitiveComponent* InOverlappedComponent, AActor* InOtherActor, UPrimitiveComponent* InOtherComponent, int32 InOtherBodyIndex, bool IsFromSweep, const FHitResult& InSweepResult);

	void GoodMathFunction();
};