// Fill out your copyright notice in the Description page of Project Settings.


#include "BHPlayerCube.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#define PRINT(text) if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text); UE_LOG(LogTemp, Warning, TEXT(text)); }
// Sets default values
ABHPlayerCube::ABHPlayerCube()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PRINT("I have been constructed");

	Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Cube);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	RootComponent = Cube;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ABHPlayerCube::BeginPlay()
{
	Super::BeginPlay();
	PRINT("I am beginning my play muahaha");
	//InputComponent->BindAxis("MoveLeftRight", this, &ABHPlayerCube::MoveLeftRight);
	Cube->SetSimulatePhysics(true);
	Mass = Cube->GetMass();
}

void ABHPlayerCube::MoveLeftRight(float AxisValue)
{
	if (!bLevelEnded)
	{
		const FVector Impulse(0.0f, AxisValue * SideForce * Mass * DeltaSeconds, 0.0f);
		Cube->AddImpulse(Impulse);
	}
}

// Called every frame
void ABHPlayerCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!bLevelEnded)
	{
		const FVector Impulse(ForwardForce * Mass * DeltaTime, 0.0f, 0.0f);
		Cube->AddImpulse(Impulse);
	}

	DeltaSeconds = DeltaTime;
}

// Called to bind functionality to input
void ABHPlayerCube::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveLeftRight", this, &ABHPlayerCube::MoveLeftRight);
}
