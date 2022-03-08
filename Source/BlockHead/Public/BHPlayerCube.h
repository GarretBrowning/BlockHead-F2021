// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BHPlayerCube.generated.h"

UCLASS()
class BLOCKHEAD_API ABHPlayerCube : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABHPlayerCube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
	UStaticMeshComponent* Cube;


	// Forward declare and create pointer for spring arm:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
	class USpringArmComponent* SpringArm;

	// Forward declare and create pointer for spring arm:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
	class UCameraComponent* Camera;


	UPROPERTY(EditAnywhere, Category = "Movement")
	float ForwardForce{2000};

	UPROPERTY(EditAnywhere, Category = "Movement")
	float SideForce{3000};

	UFUNCTION() // Our own function to be bound to Cube's on hit event.
	void OnHit(class UPrimitiveComponent* MyComp, AActor* Other,
	           UPrimitiveComponent* OtherComp,
	           FVector NormalImpulse,
	           const FHitResult& Hit);
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp,
	                    AActor* OtherActor,
	                    UPrimitiveComponent* OtherComp,
	                    int32 OtherBodyIndex,
	                    bool bFromSweep,
	                    const FHitResult& SweepResult);


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	class ABHGameMode* GameMode; // Forward declare ABHGameMode for a pointer to the game mode.
	bool bLevelEnded = false;
	float Mass;
	float DeltaSeconds;

	void MoveLeftRight(float AxisValue);
};
