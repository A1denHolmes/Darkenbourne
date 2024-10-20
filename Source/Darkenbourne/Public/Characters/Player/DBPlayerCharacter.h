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
#include "Characters/DBBaseCharacter.h"
#include "DBPlayerCharacter.generated.h"

class USphereComponent;
class UCameraComponent;
class USpringArmComponent;
struct FInputActionValue;

UCLASS(Blueprintable)
class DARKENBOURNE_API ADBPlayerCharacter : public ADBBaseCharacter
{
	GENERATED_BODY()

public:
	ADBPlayerCharacter(const FObjectInitializer& ObjInit);

	virtual void Move(const FInputActionValue& Value);
	virtual void LookAround(const FInputActionValue& Value);

protected:
	/** Debug only. Third person spring arm component. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USpringArmComponent* TPSpringArm;

	/** Debug only. Third person camera component. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCameraComponent* TPCamera;

	/**  */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USphereComponent* CameraCollision;
};
