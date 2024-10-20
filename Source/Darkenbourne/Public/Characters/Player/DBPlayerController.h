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
#include "GameFramework/PlayerController.h"
#include "DBPlayerController.generated.h"

struct FInputActionValue;
class UInputActionsData;
class ADBPlayerCharacter;
class UInputMappingContext;

UCLASS()
class DARKENBOURNE_API ADBPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void Move(const FInputActionValue& Value);
	void LookAround(const FInputActionValue& Value);
	void Jump();

protected:
	virtual void SetupInputComponent() override;
	virtual void SetPawn(APawn* InPawn) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnhancedMovement")
	UInputMappingContext* MappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnhancedMovement")
	UInputActionsData* InputActions;

private:
	TWeakObjectPtr<ADBPlayerCharacter> CachedPlayerCharacter;
};
