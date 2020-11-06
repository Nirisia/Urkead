// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "Engine/StaticMesh.h"
#include "Weapon.generated.h"



UCLASS(meta=(BlueprintSpawnableComponent), Blueprintable)
class TAKEITBACK_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DataAssets", meta = (AllowPrivateAccess = "true"))
	class UDA_Weapon* WeaponData;
	
	// Sets default values for this actor's properties
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int MaxPower;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Power;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int Damage;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int BonusStack = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsSpecialAttackActive = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float AtkSpeed = 1.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float AtkSpeedBonus;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float DamageBonus;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float WinPower;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<class UAnimMontage*> AttacksAnim;
	
	UPROPERTY()
    int AtkCount = 0;
	
	AWeapon();
	
	UFUNCTION(BlueprintCallable)
	virtual void LightAttack();
	
	UFUNCTION(BlueprintCallable)
	virtual void SpecialAttack();

	UFUNCTION(BlueprintCallable)
	virtual void Defense();

	UFUNCTION(BlueprintCallable)
	virtual void StopDefense();
	
	UFUNCTION(BlueprintCallable)
	virtual void LoadPower(int InflictedDamage);
	
	UFUNCTION(BlueprintCallable)
	virtual void UnloadPower(int DamageTaken);

	UFUNCTION(BlueprintCallable)
	void SetWeaponCollision(bool bGenerateOverlap);

	UFUNCTION(BlueprintCallable)
	virtual void LoadDataAssets();
	
	UFUNCTION(BlueprintCallable)
	void ResetCombo();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	class ABaseCharacter* GetParentCharacter();

	UFUNCTION()
	virtual void AttackCollision(UPrimitiveComponent* OverlappedComponent, AActor* 
			OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool 
			bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	virtual void Tick(float DeltaTime) override;
};
