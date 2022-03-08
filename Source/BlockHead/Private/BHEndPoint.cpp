// Fill out your copyright notice in the Description page of Project Settings.


#include "BHEndPoint.h"

#include "Components/BoxComponent.h"

// Sets default values
ABHEndPoint::ABHEndPoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	RootComponent = Box;
}

// Called when the game starts or when spawned
void ABHEndPoint::BeginPlay()
{
	Super::BeginPlay();
}
