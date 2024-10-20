/** Copyright 2024 Aiden Holmes
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Characters/Player/DBPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "EnhancedInputComponent.h"
#include "Characters/Player/DBPlayerCharacter.h"
#include "Input/InputActionsData.h"

void ADBPlayerController::Move(const FInputActionValue& Value)
{
	if (CachedPlayerCharacter.IsValid())
	{
		CachedPlayerCharacter->Move(Value);
	}
}

void ADBPlayerController::LookAround(const FInputActionValue& Value)
{
	if (CachedPlayerCharacter.IsValid())
	{
		CachedPlayerCharacter->LookAround(Value);
	}
}

void ADBPlayerController::Jump()
{
	if (CachedPlayerCharacter.IsValid())
	{
		CachedPlayerCharacter->Jump();
	}
}

void ADBPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(EnhancedInputSubsystem);
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	check(EnhancedInputComponent);

	check(MappingContext);
	check(InputActions);
	EnhancedInputSubsystem->ClearAllMappings();
	EnhancedInputSubsystem->AddMappingContext(MappingContext, 0);

	EnhancedInputComponent->BindAction(InputActions->InputMove, ETriggerEvent::Triggered, this, &ThisClass::Move);
	EnhancedInputComponent->BindAction(InputActions->InputLookAround, ETriggerEvent::Triggered, this, &ThisClass::LookAround);
	EnhancedInputComponent->BindAction(InputActions->InputJump, ETriggerEvent::Started, this, &ThisClass::Jump);
}

void ADBPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	CachedPlayerCharacter = Cast<ADBPlayerCharacter>(InPawn);
}
