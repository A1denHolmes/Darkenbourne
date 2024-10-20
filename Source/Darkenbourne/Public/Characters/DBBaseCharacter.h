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
#include "GameFramework/Character.h"
#include "DBBaseCharacter.generated.h"

UCLASS(Abstract, NotBlueprintable)
class DARKENBOURNE_API ADBBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ADBBaseCharacter(const FObjectInitializer& ObjInit);

	virtual void Tick(float DeltaTime) override;

	/** Used to get Base Aim Rotation in local coordinates space (e.g. for correct aim offset replication) */
	FRotator GetLocalAimRotation() const;

protected:
	virtual void BeginPlay() override;
};
