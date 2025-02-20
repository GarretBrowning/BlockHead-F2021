// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BHObstacle.generated.h"

UCLASS()
class BLOCKHEAD_API ABHObstacle : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABHObstacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Using the AllowPrivateAccess meta tag allows us to make a private property blueprint
	// accessible if we wanted:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Configure", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Cube;
};
