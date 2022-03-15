// Fill out your copyright notice in the Description page of Project Settings.


#include "BHGameMode.h"

#include "Blueprint/UserWidget.h"

ABHGameMode::ABHGameMode()
{
}

void ABHGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Disable mouse cursor
	Controller = GetWorld()->GetFirstPlayerController();
	Controller->bShowMouseCursor = false;
	FInputModeGameOnly InputMode;
	Controller->SetInputMode(InputMode);

	CheckLevel();

	if (DefaultHUD)
	{
		HUD = CreateWidget<UUserWidget>(GetWorld(), DefaultHUD);
		HUD->AddToViewport();
	}
}

void ABHGameMode::EndGame()
{
	PRINT("GameMode Ended");
}

void ABHGameMode::LevelComplete()
{
	PRINT("GameMode LevelComplete");
	if (DefaultGameCompleteWidget)
	{
		LevelCompleteWidget = CreateWidget<UUserWidget>(GetWorld(), DefaultLevelCompleteWidget);
		LevelCompleteWidget->AddToViewport();
	}
	else
	{
		PRINT("No Default Level Complete Widget has Been Set in the Game Mode.")
	}

	GetWorldTimerManager().SetTimer(LevelSwapTimer, this, &ABHGameMode::LoadNextLevel, 2.0f, false);
}

void ABHGameMode::LoadNextLevel()
{
	PRINT("GameMode LoadNextLevel");
}

void ABHGameMode::CheckLevel()
{
	PRINT("GameMode CheckLevel");
}
