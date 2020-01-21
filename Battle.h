#pragma once
#include <vector>
#include <string>
#include "Unit.h"

class Team;
class Technique;

class Item;

class Battle{
    private:
        Team* Party;
        Team* Enemies;
        std::vector<Character*> turn_priority;
        std::vector<Turn*> turn_history;
        int xp;
        std::vector<Item*> drops;
        int field[3][7];
    public:
        // Constructor
        Battle(std::vector<Character*> Party, std::vector<Enemy*> Enemies);
        // Battle Start
        void create_turn_priority();
        int calculate_xp();
        void determine_drops();
        // Turn Management
        void start_turn(Character*);
        void next_turn();
        
        // Action Utilities
        bool check_hit(int attacker_id, int defender_id);
        void get_move_tiles(int unit_id, int movement = 1);
        std::vector<Character*> get_targets(bool friendly);
        void fix_xp();
        bool is_countering();
};
