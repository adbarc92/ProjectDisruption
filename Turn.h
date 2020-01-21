#pragma once
#include <string>
#include "Unit.h"

class Turn{
    private:
        bool action;
        bool bonus_action;
        std::string attack_actions[3] = {"Strike", "Smite", "Intercept"};
        std::string special_actions[2] = {"Tech", "Hold"};
        std::string bonus_actions[4] = {"Drain", "Item", "Move", "Focus"};
    public:
        // Menu Management
        void add_attack_action(std::string);
        void add_special_action(std::string);
        void add_bonus_action(std::string);
        void remove_attack_action(std::string);
        void remove_special_action(std::string);
        void remove_bonus_action(std::string);
        void print_turn_menu();
        void fix_turn_priority(); // Run once every round, at the end
        void end_turn(int unit_id);
        // Actions
        void use_strike(int attacker_id, int defender_id);
        void use_smite(void strike(int attacker_id, int defender_id));
        void use_defend(int unit_id);
        void use_tech(std::string name, int user_id);
        void use_movement(int unit_id);
        void use_drain();
        void use_item();
        void use_focus();
        // Turn Checks
        bool is_turn_over();
        bool is_dead();
        bool is_blessed(Character*);
        bool is_baned(Character*);
};