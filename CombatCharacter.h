#pragma once // Prevents multiple inclusions of this header file

#include "CoreMinimal.h" // Includes core functionality of Unreal Engine
#include "GameFramework/Character.h" // Base class for characters
#include "CombatCharacter.generated.h" // Macro for UE reflection and object generation

UCLASS() // Declares this class as a UE4 UCLASS, enabling reflection and Blueprint support
class ComCharacter_API ACombatCharacter : public ACharacter // Define the class and inherit from ACharacter
{
    GENERATED_BODY() // Macro to handle UE-specific generated code for the class

public:
    // Constructor for initializing default properties
    ACombatCharacter();

    // Health property
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Health") 
    float MaxHealth; // Maximum health of the character

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Health") 
    float CurrentHealth; // Current health of the character

    // Function to handle damage
    UFUNCTION(BlueprintCallable, Category="Health") 
    void TakeDamage(float DamageAmount); // Reduces health by the damage amount

    // Function to check if the character is dead
    UFUNCTION(BlueprintCallable, Category="Health") 
    bool IsDead() const; // Returns true if health is <= 0

    // Ability System Component for abilities (GAS)
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Abilities")
    class UAbilitySystemComponent* AbilitySystemComponent; // Handles ability logic and systems

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override; // UE4 lifecycle function for initialization
};

