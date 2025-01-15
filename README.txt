Combat System and Multiplayer Gameplay
Overview
This repository contains two major features developed using Unreal Engine:

Combat System: A basic combat system featuring melee, ranged, and AoE attacks, health management, and reward mechanics.
Multiplayer Gameplay: Enables real-time multiplayer interaction with synchronized actions, health, scores, and rewards.
The project is implemented using Unreal Engine's Gameplay Ability System (GAS) and Networking Framework.


Optimization:
Use profiling tools to monitor and optimize network and resource usage.
Prerequisites
Unreal Engine 4/5: Installed and set up.

Development Environment:
Visual Studio or other IDE for Unreal Engine development.
Optional Tools:
Git: For version control.

Setup Instructions
General Setup
Clone the Repository:

bash
Copy code
git clone https://github.com/yourusername/project-repo.git
cd project-repo
Open Project:

Launch Unreal Engine and open the .uproject file.
Build the Project:

Compile the project from Build > Compile in Unreal Engine.


Topic 1: Combat System Setup
Add Combat Characters:

Drag and drop the CombatCharacter and TestDummy classes into your game level.
Health Bars:

Ensure health bars are linked to characters in the Blueprint editor.
Attach the HealthBarWidget to enemies and allies.
Game Over Screen:

Use the GameOverWidget to display scores upon win/loss conditions.
Customize it to show rewards and other information.
Reward Mechanics:

Modify the scoring system in the ScoreAPI or similar component.
Test and Debug:

Test combat mechanics with different scenarios: melee, ranged, and AoE attacks.


Topic 2: Multiplayer Setup
Enable Multiplayer:

Open Edit > Project Settings > Maps & Modes.
Set Net Mode to Multiplayer.
Replication:

Ensure properties like health, scores, and usernames are marked with Replicated:
CurrentHealth
PlayerName
PlayerScore
Username Display:

Add the UsernameWidget to display player names above characters.
Multiplayer Testing:

Launch multiple game instances:
Use Play > New Editor Window (PIE) and set the player count to 2 or more.
Network Optimization:

Use Unreal Network Profiler to monitor latency and synchronization.