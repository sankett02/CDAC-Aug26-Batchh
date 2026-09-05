#include<iostream>
#include<string>
using namespace std;

class Entity {
    private:
        string name;
        int health;
        int level;
        string type;
    
    public:
        Entity& setName(const string& name){
            this->name=name;
            return *this;
        }

        Entity& setLevel(int level){
            this->level=level;
            return *this;
        }

        Entity& setHealth(int health){
            this->health=health;
            return *this;
        }

        Entity& setType(const string& Type){
            if(type == "Player" || type == "Enemy" || type == "Item"){
                this->type=type;
            }
            return *this;
        }

        string getName()  const{
            return name;
        }

        int getHealth() const{
            return health;
        }

        int getLevel() const{
            return level;
        }

        string getType() const{
            return type;
        }
        void displayInfo() const{
            cout << "Name: " << name << endl;
            cout << "Health: " << health << endl;
            cout << "Level: " << level << endl;
            cout << "Type: " << type << endl;

        }
};

int main(){
    Entity player;
    Entity enemy;
    Entity item;

    player.setName("Aragorn").setHealth(100).setLevel(10).setType("Player");
    cout<<player.getHealth()<<endl;
    player.displayInfo();
    
    enemy.setName("Orc")
     .setHealth(60)
     .setLevel(5)
     .setType("Enemy");
     enemy.displayInfo();;

    item.setName("HealthPotion")
    .setHealth(0)
    .setLevel(1)
    .setType("Item");
    item.displayInfo();

}