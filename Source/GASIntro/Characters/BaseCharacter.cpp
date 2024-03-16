// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "AbilitySystemComponent.h"
#include "GASIntro/Gameplay/BaseGameplayAbility.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ABaseCharacter::AquireAbility(TSubclassOf<UBaseGameplayAbility> Ability)
{
	if (AbilitySystemComponent && Ability)
	{
		AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(Ability)); //使用FGameplayAbilitySpec实例化Ability
		AbilitySystemComponent->InitAbilityActorInfo(this, this);//初始化能力信息，单机参数都是自己，如果跟网络相关，参数一个是Playerstadium,一个是Character类
	}
}

