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

#include "Characters/DBBaseCharacter.h"

#include "Characters/Components/DBCharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Net/UnrealNetwork.h"

ADBBaseCharacter::ADBBaseCharacter(const FObjectInitializer& ObjInit)
	: Super(ObjInit.SetDefaultSubobjectClass<UDBCharacterMovementComponent>(CharacterMovementComponentName))
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADBBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADBBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

FRotator ADBBaseCharacter::GetLocalAimRotation() const
{
	FVector	 AimDirectionWorld = GetBaseAimRotation().Vector();
	FVector	 AimDirectionLocal = GetTransform().InverseTransformVectorNoScale(AimDirectionWorld);
	FRotator AimRotationLocal = AimDirectionLocal.ToOrientationRotator();

	return AimRotationLocal;
}