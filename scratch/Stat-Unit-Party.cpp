// Working

#include <iostream>
#include <vector>
#include <string>

struct stats{
  int con,str,dex,res,agl;
  stats(): con(0), str(0), dex(0), res(0), agl(0){};
  stats(int _con, int _str, int _dex, int _res, int _agl): con(_con),str(_str),dex(_dex),res(_res),agl(_agl){};
  stats(int statArr[]){
    con = statArr[0];
    str = statArr[1];
    dex = statArr[2];
    res = statArr[3];
    agl = statArr[4];
  };
};

class Unit{
  public:
  Unit(std::string, int, int, int, int, int);
  Unit(std::string name);
  ~Unit();
  Unit* createUnit(std::string, int[]);
  Unit* createUnit(std::string, int, int, int, int, int);
  void printUnit();
  int sumStats();
  private:
  static int currentID;
  int id;
  std::string name;
  stats s;
  void setStats();

};

int Unit::currentID = 0;

class Party{
  public:
  Party();
  Party(std::string);
  ~Party();
  Party* createParty(std::string);
  void addToParty(Unit*);
  void removeFromParty(int);
  void printParty();
  private:
  std::vector<Unit*> team;
  std::string name;
};

Unit::Unit(std::string _name, int _con, int _str, int _dex, int _res, int _agl){
  id = currentID++;
  name = _name;
  s = stats(_con, _str, _dex, _res, _agl);
}

Unit::Unit(std::string _name = "sucka"){
  name = _name;
  id = currentID++;
}

Unit* Unit::createUnit(std::string _name, int statArr[]){
  Unit* newUnit = new Unit(_name);
  newUnit->s = stats(statArr);
  return newUnit;
}

Unit* Unit::createUnit(std::string _name, int _con, int _str, int _dex, int _res, int _agl){
  Unit* newUnit = new Unit(_name);
  newUnit->s = stats(_con, _str, _dex, _res, _agl);
  return newUnit;
}

void Unit::printUnit(){
  std::cout << "ID: " << id << std::endl;
  std::cout << "Name: " << name << std::endl;
  std::cout << "Constitution: " << s.con << std::endl;
  std::cout << "Strength: " << s.str << std::endl;
  std::cout << "Dexterity: " << s.dex << std::endl;
  std::cout << "Resonance: " << s.res << std::endl;
  std::cout << "Agility: " << s.agl << std::endl;
  std::cout << "Sum: " << sumStats() << std::endl;
  std::cout << std::endl;
}

int Unit::sumStats(){
  return s.con+s.str+s.dex+s.res+s.agl;
}

Party::Party(std::string _name){
  name = _name;
}

void Party::addToParty(Unit* newUnit){
  team.push_back(newUnit);
}

void Party::printParty(){
  for(int i = 0; i < team.size(); i++){
    team[i]->printUnit();
  }
}

int main(){
  Party* reckoners = new Party("reckoners");
  Unit* cyrus = new Unit("Cyrus", 8, 9, 6, 6, 6);
  Unit* vaughn = new Unit("Vaughn", 6, 4, 9, 6, 10);
  Unit* phaidros = new Unit("Phaidros", 10, 8, 5, 8, 4);
  Unit* lione = new Unit("Lione", 5, 4, 8, 10, 8);
  reckoners->addToParty(cyrus);
  reckoners->addToParty(vaughn);
  reckoners->addToParty(phaidros);
  reckoners->addToParty(lione);
  reckoners->printParty();
}