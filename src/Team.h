#pragma once
#include <vector>
#include "Unit.h"


class Party{
    private:
        std::vector<Character*> team;
        bool is_friendly;
        int party_id;
    public:
        Party();
};
