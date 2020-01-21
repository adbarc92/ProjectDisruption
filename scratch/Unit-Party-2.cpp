#include <vector>
#include <string>
#include <iostream>
// Attack Function

// Hit Calculation Function



class Unit{
  private:
    std::vector<std::pair<std::string, int>> stats;
    int id;
    std::string name;
  public:
    Unit(int _id, std::string _name): id(_id), name(_name){};
    void setStats(int _con, int _str, int _dex, int _res, int _agl){
      std::pair<std::string, int> con;
      con.first = "Constitution";
      con.second = _con;
      stats.push_back(con);
      
      std::pair<std::string, int> str;
      str.first = "Strength";
      str.second = _str;
      stats.push_back(str);
      
      std::pair<std::string, int> dex;
      dex.first = "Dexterity";
      dex.second = _dex;
      stats.push_back(dex);
      
      std::pair<std::string, int> res;
      res.first = "Resonance";
      res.second = _res;
      stats.push_back(res);
     
      std::pair<std::string, int> agl;
      agl.first = "Agility";
      agl.second = _agl;
      stats.push_back(agl);
    };
    void printUnit(){
      std::cout << "Name: " << name << std::endl;
      std::cout << "id: " << id << std::endl;
      std::cout << stats[0].first << ": " << stats[0].second << std::endl;
      std::cout << stats[1].first << ": " << stats[1].second << std::endl;
      std::cout << stats[2].first << ": " << stats[2].second << std::endl;
      std::cout << stats[3].first << ": " << stats[3].second << std::endl;
      std::cout << stats[4].first << ": " << stats[4].second << std::endl;
      std::cout << std::endl;
    }
};

class Party{
  private:
    std::string name;
    std::vector<Unit> team;
  public:
    Party(std::string _name){
      name = _name;
      this->fillTeam();
    };
    void fillTeam(){
      Unit cyrus = Unit(1, "Cyrus");
      cyrus.setStats(8,10,7,3,5);
      team.push_back(cyrus);


      Unit vaughn = Unit(2, "Vaughn");
      vaughn.setStats(6,6,8,5,8);
      team.push_back(vaughn);

      Unit phaidros = Unit(3, "Phaidros");
      phaidros.setStats(10,7,3,6,2);
      team.push_back(phaidros);

      Unit lione = Unit(4, "Lione");
      lione.setStats(3,3,9,10,9);
      team.push_back(lione);
    }
    void printTeam(){
      for(int i = 0; i < team.size(); i++){
        team[i].printUnit();
      }
    }
};

int main(){
  // Party* reckoners = new Party("reckoners");
  Party reckoners = Party("reckoners");
  reckoners.printTeam();
}

/* ========================= Output ========================= */

// Name: Cyrus
// id: 1
// Constitution: 8
// Strength: 10
// Dexterity: 7
// Resonance: 3
// Agility: 5

// Name: Vaughn
// id: 2
// Constitution: 6
// Strength: 6
// Dexterity: 8
// Resonance: 5
// Agility: 8

// Name: Phaidros
// id: 3
// Constitution: 10
// Strength: 7
// Dexterity: 3
// Resonance: 6
// Agility: 2

// Name: Lione
// id: 4
// Constitution: 3
// Strength: 3
// Dexterity: 9
// Resonance: 10
// Agility: 9