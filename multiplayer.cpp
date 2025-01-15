#include "CombatCharacter.h" // Include the header file that defines ACombatCharacter

// Constructor for the ACombatCharacter class
ACombatCharacter::ACombatCharacter()
{
    bReplicates = true; // Enable replication to ensure this character's state is synchronized across clients
}

// Called when the game begins or the actor is spawned
void ACombatCharacter::BeginPlay()
{
    Super::BeginPlay(); // Call the parent class's BeginPlay function to ensure any inherited setup logic runs
}

// Server implementation of the TakeDamage function
void ACombatCharacter::ServerTakeDamage_Implementation(float DamageAmount)
{
    // Reduce CurrentHealth by DamageAmount, clamping it to a minimum of 0 and a maximum of MaxHealth
    CurrentHealth = FMath::Clamp(CurrentHealth - DamageAmount, 0.f, MaxHealth);

    // Check if the character's health has reached 0
    if (IsDead())
    {
        Destroy(); // Destroy the character when health is depleted
    }
}

// Validation function for ServerTakeDamage
bool ACombatCharacter::ServerTakeDamage_Validate(float DamageAmount)
{
    return true; // Allow all calls; you can add specific validation logic here if needed
}

// Registers properties for replication
void ACombatCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps); // Ensure parent class's replication logic is preserved

    // Register CurrentHealth for replication to synchronize health across the server and clients
    DOREPLIFETIME(ACombatCharacter, CurrentHealth);

    // Register PlayerName for replication to ensure the player's name is consistent across the network
    DOREPLIFETIME(ACombatCharacter, PlayerName);

    // Register PlayerScore for replication to synchronize the player's score across clients
    DOREPLIFETIME(ACombatCharacter, PlayerScore);
}
