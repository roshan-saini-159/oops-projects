#include<iostream>
using namespace std;

class character{

    protected:

        string name;
        int health;
        int attackPower;
        int defense;

    public:

        character(string n,int h,int ap,int d)
        : name(n),health(h),attackPower(ap),defense(d){}

        virtual void attack(character* target) = 0; //purely virtual for each character

        int takeDamage(int damage){
            health -= max(0,damage - defense);
        }

        bool isAlive(){
            return health > 0;
        }


};

class warrier : public character{

    public:

        warrier(string n) : character(n,100,20,10){
          
        }

        void attack(character *target) override {
            int damage = attackPower;
            if(health<30){
                damage += 10;
                cout << name << " is enraged! Extra damage!\n";
            }
            cout<<name<<"Attacked with Sword! Took "<<damage<<" damage.\n" <<endl;
            target->takeDamage(damage);
        }

        

};

class archer : public character{

    public:
        archer(string n) : character(n,100,20,10){
          
        }

        void attack(character *target) override {
            int damage = attackPower;
            cout<<name<<"Attacked with Arrow! Took "<<damage<<" damage.\n" <<endl;
            target->takeDamage(damage);
        }


};


class gameManager{






};



int main(){



    return 0;
}
