// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BHGameMode.generated.h"
#define PRINT(text) if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text); UE_LOG(LogTemp, Warning, TEXT(text)); }
/**
 * 
 */
UCLASS()
class BLOCKHEAD_API ABHGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABHGameMode();
	void EndGame();
	void LevelComplete();
	void LoadNextLevel();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
	TSubclassOf<UUserWidget> DefaultLevelCompleteWidget; // Exposes a picker of type UUserWidget
	UUserWidget* LevelCompleteWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
	TSubclassOf<UUserWidget> DefaultGameCompleteWidget;
	UUserWidget* GameCompleteWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
	TSubclassOf<UUserWidget> DefaultHUD;
	UUserWidget* HUD;

private:
	virtual void BeginPlay() override;
	void CheckLevel();

	APlayerController* Controller;

	int32 CurrentLevelIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Levels")
	TArray<FString> Levels;

	FString NextLevel;

	FTimerHandle LevelSwapTimer;
};
