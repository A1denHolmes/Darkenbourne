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

#include "Characters/Player/DBPlayerCharacter.h"

#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

ADBPlayerCharacter::ADBPlayerCharacter(const FObjectInitializer& ObjInit)
	: Super(ObjInit)
{
	TPSpringArm = CreateDefaultSubobject<USpringArmComponent>("TP Spring Arm");
	TPSpringArm->SetupAttachment(RootComponent);
	TPSpringArm->bUsePawnControlRotation = true;

	TPCamera = CreateDefaultSubobject<UCameraComponent>("TP Camera");
	TPCamera->SetupAttachment(TPSpringArm);

	CameraCollision = CreateDefaultSubobject<USphereComponent>("Camera Collision");
}

void ADBPlayerCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D MoveValue = Value.Get<FVector2D>();
	const FRotator	MoveRotation(0, Controller->GetControlRotation().Yaw, 0);

	if (!FMath::IsNearlyZero(MoveValue.Y, 1e-6f))
	{
		const FVector MoveDirection = MoveRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(MoveDirection, MoveValue.Y);
	}
	if (!FMath::IsNearlyZero(MoveValue.X, 1e-6f))
	{
		const FVector MoveDirection = MoveRotation.RotateVector(FVector::RightVector);
		AddMovementInput(MoveDirection, MoveValue.X);
	}
}

void ADBPlayerCharacter::LookAround(const FInputActionValue& Value)
{

	const FVector2D LookValue = Value.Get<FVector2D>();

	if (!FMath::IsNearlyZero(LookValue.Y, 1e-6f))
	{
		AddControllerPitchInput(LookValue.Y);
	}
	if (!FMath::IsNearlyZero(LookValue.X, 1e-6f))
	{
		AddControllerYawInput(LookValue.X);
	}
}