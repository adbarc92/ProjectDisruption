#pragma once
#include <vector>
#include <string>
#include "Unit.h"

std::string target_types[11] = {
    "Self Square",
    "Single Ally Square",
    "Many Ally Square",
    "All Ally Square",
    "Single Enemy Square",
    "Many Enemy Square",
    "All Enemy Square",
    "AOE-X",
    "AOE-+",
    "Single Ally & Single Enemy Square",
    "All Square"
};

class Technique{
    private:
        static std::vector<Technique*> compendium;
        // Ownership & Details
        const std::string name;
        std::vector<int> owner_id;
        std::string tooltip; // In-game description
        // Key Modifiers
        float damage_modifier;
        std::pair<int,int> position_modifier; // Direction, Degree
        float hp_modifier;
        std::pair<std::string, float> status_modifier; // status, success rate
        // Types
        std::string damage_type;
        int target_type;
    public:
        // Constructor
        Technique();
        Technique(int owner_id, std::string tech_name, std::string tooltip);
        int calculate_damage(Unit* attacker, Unit* target);
        bool check_status(Unit* target);
        std::string get_owner_name(int owner_id);
};
