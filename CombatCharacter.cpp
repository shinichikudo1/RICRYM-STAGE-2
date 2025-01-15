#include "CombatCharacter.h" // Include the corresponding header file
#include "AbilitySystemComponent.h" // Include GAS component support

// Constructor
ACombatCharacter::ACombatCharacter()
{
    // Set default values for MaxHealth and CurrentHealth
    MaxHealth = 100.0f; // Default maximum health
    CurrentHealth = MaxHealth; // Start at full health

    // Initialize the Ability System Component
    AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

// BeginPlay: Called when the game starts or is spawned
void ACombatCharacter::BeginPlay()
{
    Super::BeginPlay(); // Call the parent class's BeginPlay
    CurrentHealth = MaxHealth; // Ensure full health at the start
}

// TakeDamage: Reduces health by the damage amount
void ACombatCharacter::TakeDamage(float DamageAmount)
{
    CurrentHealth -= DamageAmount; // Subtract damage from current health
    CurrentHealth = FMath::Clamp(CurrentHealth, 0.0f, MaxHealth); // Clamp health between 0 and MaxHealth

    if (IsDead()) // Check if character is dead
    {
        // Placeholder for death logic (e.g., play animation, notify game mode)
        UE_LOG(LogTemp, Warning, TEXT("Character is dead!"));
    }
}

// IsDead: Checks if the character's health is <= 0
bool ACombatCharacter::IsDead() const
{
    return CurrentHealth <= 0.0f; // Return true if health is 0 or less
}
