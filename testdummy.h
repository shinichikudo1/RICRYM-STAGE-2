#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestDummy.generated.h"
UCLASS()
class testdummy_API ATestDummy : public AActor
    GENERATED_BODY()
public:
    ATestDummy();
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health")
    float MaxHealth;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Health")
    float CurrentHealth;
    UFUNCTION(BlueprintCallable, Category="Health")
    void TakeDamage(float DamageAmount);
protected:
    virtual void BeginPlay() override;
#include "TestDummy.h"
ATestDummy::ATestDummy()
{
    MaxHealth = 50.f; // Set maximum health to 50
    CurrentHealth = MaxHealth; // Initialize current health to the maximum value
}
void ATestDummy::BeginPlay()
{
    Super::BeginPlay(); // Call the parent class's BeginPlay method
}
void ATestDummy::TakeDamage(float DamageAmount)
{
    CurrentHealth = FMath::Clamp(CurrentHealth - DamageAmount, 0.f, MaxHealth); // Reduce and clamp health
    if (CurrentHealth <= 0.f)
    {
        Destroy(); // Remove the dummy actor from the game world
    }
}
