#include "CombatCharacter.h" // Include the header file for ACombatCharacter
#include "Net/UnrealNetwork.h" // Include Unreal Engine's network library for replication

// Constructor
ACombatCharacter::ACombatCharacter()
{
    // Initialize default values for properties
    CurrentHealth = 100.f; // Default health value
    PlayerScore = 0;       // Default score
    PlayerName = TEXT("DefaultPlayer"); // Default player name

    // Enable replication for the character
    bReplicates = true;
}

// Called when the game starts or when spawned
void ACombatCharacter::BeginPlay()
{
    Super::BeginPlay(); // Call parent class's BeginPlay method
}

// Function to handle damage on the server
void ACombatCharacter::ServerTakeDamage_Implementation(float DamageAmount)
{
    // Reduce CurrentHealth by DamageAmount, clamping it to a minimum of 0
    CurrentHealth = FMath::Clamp(CurrentHealth - DamageAmount, 0.f, 100.f);

    // Optional: Handle what happens if the character's health reaches zero
    if (CurrentHealth <= 0.f)
    {
        // Log death or notify other systems
        UE_LOG(LogTemp, Warning, TEXT("%s has died."), *PlayerName);
    }
}

// Validation for the ServerTakeDamage function
bool ACombatCharacter::ServerTakeDamage_Validate(float DamageAmount)
{
    return DamageAmount >= 0.f; // Ensure the damage amount is non-negative
}

// Configure replication for properties
void ACombatCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps); // Call parent implementation

    // Register properties for replication
    DOREPLIFETIME(ACombatCharacter, CurrentHealth); // Replicate CurrentHealth to clients
    DOREPLIFETIME(ACombatCharacter, PlayerName);    // Replicate PlayerName to clients
    DOREPLIFETIME(ACombatCharacter, PlayerScore);   // Replicate PlayerScore to clients
}
