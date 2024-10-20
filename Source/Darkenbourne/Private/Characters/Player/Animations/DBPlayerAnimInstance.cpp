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

#include "Characters/Player/Animations/DBPlayerAnimInstance.h"

#include "KismetAnimationLibrary.h"
#include "Characters/DBBaseCharacter.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UDBPlayerAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	check(TryGetPawnOwner()->IsA<ADBBaseCharacter>());
	CachedBaseCharacter = StaticCast<ADBBaseCharacter*>(TryGetPawnOwner());
}

void UDBPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!CachedBaseCharacter.IsValid())
	{
		return;
	}

	UpdateEssentialVariables(DeltaSeconds);
}

void UDBPlayerAnimInstance::UpdateEssentialVariables(float DeltaSeconds)
{
	bInAir = CachedBaseCharacter->GetMovementComponent()->IsFalling();
	Velocity = CachedBaseCharacter->GetVelocity();
	Speed = Velocity.Length();
	Speed2D = Velocity.Size2D();
	MoveDirection = UKismetAnimationLibrary::CalculateDirection(Velocity, CachedBaseCharacter->GetActorRotation());
	AimRotation = CachedBaseCharacter->GetLocalAimRotation();
	bIdle = FMath::IsNearlyZero(Speed);

	bEnableLegsIK = !bInAir;

	TimeSinceLastYawSpeedCalculation += DeltaSeconds;

	if (TimeSinceLastYawSpeedCalculation >= YawSpeedCalculationInterval)
	{
		FRotator CurrentRotation = CachedBaseCharacter->GetActorRotation();
		YawSpeed = (CurrentRotation.Yaw - PreviousActorRotation.Yaw) / DeltaSeconds;
		PreviousActorRotation = CurrentRotation;

		if (FMath::Abs(YawSpeed) < MinAbsYawSpeedToTurn)
		{
			YawSpeed = 0.0f;
		}

		TimeSinceLastYawSpeedCalculation = 0.0f;
	}
}
