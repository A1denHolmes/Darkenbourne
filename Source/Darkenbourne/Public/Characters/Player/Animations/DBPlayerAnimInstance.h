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

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "DBPlayerAnimInstance.generated.h"

class ADBBaseCharacter;

UCLASS()
class DARKENBOURNE_API UDBPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category = "Movement Analysis")
	bool bInAir = false;

	/** Vector of character's velocity */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category = "Movement Analysis")
	FVector Velocity = FVector::ZeroVector;

	/** Float character's speed */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category = "Movement Analysis", meta = (ClampMin = 0.0f))
	float Speed = 0.0f;

	/** Float character's speed along X and Y axes*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category = "Movement Analysis", meta = (ClampMin = 0.0f))
	float Speed2D = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category = "Movement Analysis", meta = (ClampMin = -180.0f, ClampMax = 180.0f))
	float MoveDirection = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category = "Movement Analysis")
	FRotator AimRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category = "Movement Analysis")
	float YawSpeed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category = "Movement Analysis")
	bool bIdle = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category = "IK")
	bool bEnableLegsIK = true;

private:
	void UpdateEssentialVariables(float DeltaSeconds);

	FRotator PreviousActorRotation = FRotator::ZeroRotator;

	/** Used to accumulate DeltaSeconds since last Yaw Speed calculation to calculate it after an calculation interval. Zeroed at calculation. */
	float TimeSinceLastYawSpeedCalculation = 0.0f;

	/** Determines how often in seconds the yaw speed will be calculated. At defaults set to 0.05 */
	float YawSpeedCalculationInterval = 0.1f;

	/** Minimal yaw speed turn animation plays on */
	float MinAbsYawSpeedToTurn = 50.0f;

	TWeakObjectPtr<ADBBaseCharacter> CachedBaseCharacter;
};
