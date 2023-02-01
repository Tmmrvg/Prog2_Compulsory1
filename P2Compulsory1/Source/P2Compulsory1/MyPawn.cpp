// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPawn.h"
#include "Components/SphereComponent.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include <UObject/ConstructorHelpers.h>
#include "Containers/Array.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMyPawn::AMyPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	
	Spheres.Init(NULL, 9);
	Spheres[0] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh1"));
	Spheres[1] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh2"));
	Spheres[2] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh3"));
	Spheres[3] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh4"));
	Spheres[4] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh5"));
	Spheres[5] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh6"));
	Spheres[6] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh7"));
	Spheres[7] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh8"));
	Spheres[8] = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh9"));

	RootComponent = Spheres[4];
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		MeshComponentAsset(TEXT("StaticMesh'/Game/StarterContent/Props/MaterialSphere.MaterialSphere'"));
	for (int i{}; i < 9; i++)
	{
		if (i != 4)
		{
			Spheres[i]->SetupAttachment(GetRootComponent());
		}
		Spheres[i]->SetStaticMesh(MeshComponentAsset.Object);
	}
	
	Red = CreateDefaultSubobject<UMaterial>(TEXT("RedMaterial"));
	Blue = CreateDefaultSubobject<UMaterial>(TEXT("BlueMaterial"));
	White = CreateDefaultSubobject<UMaterial>(TEXT("WhiteMaterial"));
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->SetRelativeRotation(FRotator(-70.f, 0.f, 0.f));
	SpringArm->TargetArmLength = 550.f;

	// Attach the Camera to SpringArm
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	
	Spheres[0]->SetRelativeLocation(FVector(200.f, -200.f, 0.f));
	Spheres[1]->SetRelativeLocation(FVector(200.f, 0.f, 0.f));
	Spheres[2]->SetRelativeLocation(FVector(200.f, 200.f, 0.f));
	Spheres[3]->SetRelativeLocation(FVector(0.f, -200.f, 0.f));
	Spheres[4]->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	Spheres[5]->SetRelativeLocation(FVector(0.f, 200.f, 0.f));
	Spheres[6]->SetRelativeLocation(FVector(-200.f, -200.f, 0.f));
	Spheres[7]->SetRelativeLocation(FVector(-200.f, 0.f, 0.f));
	Spheres[8]->SetRelativeLocation(FVector(-200.f, 200.f, 0.f));

	TurnCounter = 0;
	SphereStatus.Init(NULL, 9);
	SphereRed.Init(NULL, 9);
	SphereBlue.Init(NULL, 9);
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	RedWin = false;
	BlueWin = false;

	for (int i{}; i < 9; i++)
	{
		Spheres[i]->SetMaterial(0, White);
	}
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("1", IE_Pressed, this, &AMyPawn::OnePressed);
	PlayerInputComponent->BindAction("2", IE_Pressed, this, &AMyPawn::TwoPressed);
	PlayerInputComponent->BindAction("3", IE_Pressed, this, &AMyPawn::ThreePressed);
	PlayerInputComponent->BindAction("4", IE_Pressed, this, &AMyPawn::FourPressed);
	PlayerInputComponent->BindAction("5", IE_Pressed, this, &AMyPawn::FivePressed);
	PlayerInputComponent->BindAction("6", IE_Pressed, this, &AMyPawn::SixPressed);
	PlayerInputComponent->BindAction("7", IE_Pressed, this, &AMyPawn::SevenPressed);
	PlayerInputComponent->BindAction("8", IE_Pressed, this, &AMyPawn::EightPressed);
	PlayerInputComponent->BindAction("9", IE_Pressed, this, &AMyPawn::NinePressed);
}

void AMyPawn::OnePressed()
{
	TurnController(0);
}

void AMyPawn::TwoPressed()
{
	TurnController(1);
}

void AMyPawn::ThreePressed()
{
	TurnController(2);
}

void AMyPawn::FourPressed()
{
	TurnController(3);
}

void AMyPawn::FivePressed()
{
	TurnController(4);
}

void AMyPawn::SixPressed()
{
	TurnController(5);
}

void AMyPawn::SevenPressed()
{
	TurnController(6);
}

void AMyPawn::EightPressed()
{
	TurnController(7);
}

void AMyPawn::NinePressed()
{
	TurnController(8);
}

void AMyPawn::TurnController(int sphereindex)
{
	if (RedWin == true)
	{
		UE_LOG(LogTemp, Warning, TEXT("Red wins"));

		return;
	}
	else if (BlueWin == true)
	{
		UE_LOG(LogTemp, Warning, TEXT("Blue wins"));

		return;
	}
	
	if (SphereStatus[sphereindex] == true)
	{
		//UE_LOG(LogTemp, Warning, TEXT("That index is already taken"));

		return;
	}
	
	if (TurnCounter % 2 == 0)
	{
		Spheres[sphereindex]->SetMaterial(0, Blue);
		SphereBlue[sphereindex] = true;
	}
	else if (TurnCounter % 2 == 1)
	{
		Spheres[sphereindex]->SetMaterial(0, Red);
		SphereRed[sphereindex] = true;
	}
	SphereStatus[sphereindex] = true;
	TurnCounter++;
	WinCondition();
}

void AMyPawn::WinCondition()
{
	//UE_LOG(LogTemp, Warning, TEXT("Called WinCondition"));
	
#pragma region RedCondition
	//Checks Horisontally
	for (int i = 0; i < 9; i += 3)
	{
		if (SphereRed[i] == true && SphereRed[i + 1] == true && SphereRed[i + 2] == true)
		{
			RedWin = true;
			UE_LOG(LogTemp, Warning, TEXT("Red Wins"));
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Red Wins"));
		}
	}

	//Checks Vertically
	for (int i = 0; i < 2; i += 1)
	{
		if (SphereRed[i] == true && SphereRed[i + 3] == true && SphereRed[i + 6] == true)
		{
			RedWin = true;
			UE_LOG(LogTemp, Warning, TEXT("Red Wins"));
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Red Wins"));
		}
	}

	//Checks Diagonally
	if (SphereRed[0] == true && SphereRed[4] == true && SphereRed[8] == true)
	{
		RedWin = true;
		UE_LOG(LogTemp, Warning, TEXT("Red Wins"));
	}
	else if (SphereRed[2] && SphereRed[4] && SphereRed[6] )
	{
		RedWin = true;
		UE_LOG(LogTemp, Warning, TEXT("Red Wins"));
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Red Wins"));
	}

#pragma endregion

#pragma region BlueCondition
	//Checks Horisontally
	for (int i = 0; i < 9; i += 3)
	{
		if (SphereBlue[i] == true && SphereBlue[i + 1] == true && SphereBlue[i + 2] == true)
		{
			BlueWin = true;
			UE_LOG(LogTemp, Warning, TEXT("Blue Wins"));
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, TEXT("Blue Wins"));
		}
	}

	//Checks Vertically
	for (int i = 0; i < 2; i += 1)
	{
		if (SphereBlue[i] == true && SphereBlue[i + 3] == true && SphereBlue[i + 6] == true)
		{
			BlueWin = true;
			UE_LOG(LogTemp, Warning, TEXT("Blue Wins"));
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, TEXT("Blue Wins"));
		}
	}

	//Checks Diagonally
	if (SphereBlue[0] == true && SphereBlue[4] == true && SphereBlue[8] == true)
	{
		BlueWin = true;
		UE_LOG(LogTemp, Warning, TEXT("Blue Wins"));
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, TEXT("Blue Wins"));
	}
	else if (SphereBlue[2] && SphereBlue[4] && SphereBlue[6])
	{
		BlueWin = true;
		UE_LOG(LogTemp, Warning, TEXT("Blue Wins"));
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, TEXT("Blue Wins"));
	}
	
#pragma endregion
	
}