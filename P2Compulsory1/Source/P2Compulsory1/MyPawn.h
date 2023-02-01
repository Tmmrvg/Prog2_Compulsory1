// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

class UCameraComponent;
class USpringArmComponent;
class umaterial;

UCLASS()
class P2COMPULSORY1_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	//UPROPERTY(meta = (AllowPrivateAccess = "true"), VisibleAnywhere, BlueprintReadWrite)
	UPROPERTY(EditAnywhere)
		TArray<UStaticMeshComponent*> Spheres;

	UPROPERTY(VisibleAnywhere);
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere);
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		UMaterial* Red;
	UPROPERTY(EditAnywhere)
		UMaterial* Blue;
	UPROPERTY(EditAnywhere)
		UMaterial* White;

	int TurnCounter;

	void OnePressed();
	void TwoPressed();
	void ThreePressed();
	void FourPressed();
	void FivePressed();
	void SixPressed();
	void SevenPressed();
	void EightPressed();
	void NinePressed();

	void TurnController(int sphereindex);

	TArray<bool> SphereStatus;

	void ChangeColor(FColor color);
	
	TArray<bool> SphereRed;
	TArray<bool> SphereBlue;

	void WinCondition();

	bool BlueWin;
	bool RedWin;
};
