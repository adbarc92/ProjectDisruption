#include <vector>
#include <string>

struct stats{
  int con,str,dex,res,agl;
  stats(){};
  stats(int _con, int _str, int _dex, int _res, int _agl): con(_con), str(_str), dex(_dex), res(_res), agl(_agl){};
  // stats(int = 7, int = 7, int = 7, int = 7, int = 7); // Defunct default constructor
};

class Unit{
  private:
    Unit* a;
    int id;
    static int currentID;
    std::string name;
    stats statSet;
  public:
    Unit();
    Unit(std::string name, int con, int str, int dex, int res, int agl);
    Unit* createUnit(std::string name, int con, int str, int dex, int res, int agl);
    ~Unit();
    void deleteUnit();
    void setStats();
    void printUnit();
};

class Party{
  private:
    std::vector<Unit*> team;
    std::string name;
    friend class Unit;
  public:
    Party();
    Party(std::string);
    Party* createParty();
    ~Party();
    void deleteParty();
    void printParty();
};

Unit::Unit(){}

Unit::Unit(std::string _name, int _con, int _str, int _dex, int _res, int _agl){
  id = currentID++;
  name = _name;
  statSet = stats(_con, _str, _dex, _res, _agl);
}

Unit* Unit::createUnit(std::string _name, int _con, int _str, int _dex, int _res, int _agl){
  Unit* newUnit = new Unit(_name, _con, _str, _dex, _res, _agl);
  return newUnit;
}

Party::Party(){}

Party::Party(std::string _name){
  name = _name;
}

Party* Party::createParty(){
  Party* p = new Party("reckoners");
  Unit* cyrus;
  cyrus = cyrus->createUnit("Cyrus", 8, 9, 5, 4, 6); // An existing unit* is required to create a unit*; that seems wrong.
  Unit* vaughn;
  vaughn = vaughn->createUnit("Vaughn", 6, 5, 9, 6, 10);
  Unit* phaidros;
  phaidros = phaidros->createUnit("Phaidros", 10, 8, 3, 6, 4);
  Unit* lione;
  lione = lione->createUnit("Lione", 5, 4, 8, 10, 8);
  return p;
}
