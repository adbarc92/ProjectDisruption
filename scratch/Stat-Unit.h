#include <iostream>
#include "combat.h"
#include "technique.h"

const int PRIMARY_STAT_MAX = 100;
const int PRIMARY_STAT_MIN = 1;

struct primaryStats { // Range between 1 and 100
    int constitution; // Governs HP and exCap
    int strength; // Governs critDmg and physDmg
    int dexterity; // Governs critChance and accuracy
    int agility; // Governs initiative and reflexes
    int affinity; // Governs exRes and exDmg
};

struct derivedStats {
    // CON Stats
    int hitPoints; // Max: 999, Min: 10
    int exCap; // Max: 99, Min: 5
    // STR Stats
    float physDmg; // STR*5
    float critDmg; // STR*0.2
    // DEX Stats
    float critChance;
    float accuracy;
    // AGL Stats
    int initiative; // Combat speed
    float reflexes;
    // AFF Stats
    float exDmg; // Exousia Damage
    float exRes; // Exousia Resonance; entails Exousia Defense and Exousia Recovery
    
};

struct charInfo{
	std::string name;
	const int id = 0;
	battleProfile bp(id);

};

class Unit{
    private:
        primaryStats statsP;
        derivedStats statsD;
        battleStats statsB;
        charInfo statsC;
        std::vector<technique> techs;

    public:
        // Normal Attack
            // Select target
            // checkHit(Unit* attacker, Unit* defender)
            // strike, recover
        // Techniques
        // Move
        // Devices
        
};