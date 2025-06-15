# Resident-Evil-Text-RPG
A text RPG was created as part of CS100 Introduction to Programming at LUMS. It leverages basic programming in C++ with some additional external libraries.
Created as part of a pair with Rafay Saeed Kazmi (25100197@lums.edu.pk) from LUMS. 

## 📜 Overview

This is a text-based combat adventure game built in C++. The player takes on the role of a survivor in a post-apocalyptic world infected by dangerous entities. The player must fight enemies, level up, and eventually face off against a powerful boss—**TYRANT**—to win.

The game features health-based turn-based combat, player stats like strength, stealth, and luck, and a simple story progression system.

---

## 🎮 Gameplay Features

- **Turn-Based Combat**: Choose to attack, block, or run away during encounters.
- **Dynamic HUD**: Displays health, levels, XP, and enemy information.
- **Leveling System**: Gain XP by defeating enemies and level up to increase your strength, health, and other attributes.
- **Randomized Enemy Stats**: Each enemy’s health and level are dynamically generated.
- **Boss Fight**: A final battle with the TYRANT boss after story progression.
- **Text Speed Control**: Users can set the speed at which story text is displayed.

---

## 🧱 Core Components

- `CreateEntity()`: Generates a new enemy with dynamic stats.
- `Combat()`: Handles the main combat logic against regular enemies.
- `CombatBoss()`: Special battle logic for the final boss.
- `LevelUp()`: Increases player stats when enough XP is earned.
- `CombatHUD()` & `CombatBossHUD()`: Print player/enemy health, level, XP.
- `story()`: Story sequences that include branching narratives.
- `speedoftext()`: Lets users choose how fast narrative text is displayed.

---

## 🛠️ How to Build and Run

### Prerequisites

- A C++ compiler (`g++` or any C++11-compliant compiler)
- Windows (`Sleep()` and `system("cls")` commands are used which Windows-specific)

### Build Command (using g++)

```bash
g++ -o project project.cpp
```

```bash
./project
```




