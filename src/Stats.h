#pragma once
#include <math.h>

#define DMG_MAX 999;
#define HP_MAX 999;
#define EX_MAX 99;

struct core_stats
{
    int con, str, dex, res, agl;
    core_stats(int _con, int _str, int _dex, int _res, int _agl) : con(_con), str(_str), dex(_dex), res(_res), agl(_agl){};
    core_stats() : con(5), str(5), dex(5), res(5), agl(5) {}
};

struct stat_block
{
    int hpCap, exCap, physDmg, exDmg, exDef, initiative;
    float critDmg, critChance, accuracy, evasion;
    stat_block(int _con = 5, int _str = 5, int _dex = 5, int _res = 5, int _agl = 5) : hpCap(_con * 10), exCap(_con * 5), physDmg(_str * 5), exDmg(_res * 4), exDef(_res * 3), initiative(floor(_agl / 2)), critDmg(_str * 0.5 + 50), critChance(_dex * 0.25 + 25), accuracy(_dex + 90), evasion(_agl + 10){};
    // stat_block(): hpCap(50), exCap(25), physDmg(25), exDmg(20), exDef(15), initiative(10), critDmg(52.5), critChance(26.5), accuracy(95), evasion(15){};
};

struct resistances
{
    float bleed, stun, move, poison, rooted, burning;
    float con_resist, str_resist, dex_resist, res_resist, agl_resist;
    resistances(int _con = 5, int _str = 5, int _dex = 5, int _res = 5, int _agl = 5) : bleed(_dex * 1.5 + 25), stun(), move(_str * 3 + 10), poison(_con * 2.5 + 20), rooted(_agl * 5 + 10), burning(_res * 2 + 20), con_resist(_con * 4), str_resist(_str * 4), dex_resist(_dex * 4), res_resist(_res * 4), agl_resist(_agl * 4){};
};

class Stats
{
private:
    core_stats core;
    core_stats core_modifiers;
    stat_block block;
    stat_block stat_modifiers;
    resistances resist;

public:
    Stats();
    Stats(int _con, int _str, int _dex, int _res, int _agl)
    {
        core = core_stats(_con, _str, _dex, _res, _agl);
        core_modifiers = core_stats(0, 0, 0, 0, 0);
        block = stat_block(_con, _str, _dex, _res, _agl);
        stat_modifiers = stat_block(0, 0, 0, 0, 0);
        resist = resistances(_con, _str, _dex, _res, _agl);
    };
    void fix_stats(); // Adjusts stats to account for modifiers and maxes
    // Could include individual stat fixers for adjusting stats following status ailment expiration
};
