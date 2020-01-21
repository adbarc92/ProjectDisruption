#pragma once
#include <vector>
#include <string>

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
        float damage_modifier;
        std::string damage_type;
        float hp_modifier;
        std::pair<std::string, float> status_modifier; // status, success rate
        int target_type;
        std::pair<int,int> movement_modifier; // Direction, Degree
    public:
        // Constructor
        Technique();
        int calculate_damage();
};
