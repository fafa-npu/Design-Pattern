/**
 * author : zhaohua
 * date : June 6th, 2016
 * discription: 《大话设计模式》（程杰），工厂方法模式应用实例，page 74
 * **/

#include <iostream>

using namespace std;

class LeiFeng {
    public :
        string type;
        LeiFeng() {
            this->type = "LeiFeng ";
        }
        void Sweep() {
            cout << type << " sweep " << endl;
        }

        void Wash() {
            cout << type << " wash " << endl;
        }

        void BuyRice() {
            cout << type << " buy rice " << endl;
        }
};


class Undergraduate : public LeiFeng {
    public :
        Undergraduate() : LeiFeng::LeiFeng() {
            LeiFeng::type = "Undergraduate ";
        }
};

class Volunteer : public LeiFeng {
    public :
        Volunteer() : LeiFeng::LeiFeng() {
            LeiFeng::type = "Volunteer " ;
        }
};

class LeiFengFactory {
    public :
        virtual LeiFeng * CreateLeiFeng(){
            return new LeiFeng();
        }
};

class UndergraduateFactory : public LeiFengFactory {
    public :
        LeiFeng * CreateLeiFeng() {
            return new Undergraduate();
        }
};

class VolunteerFactory : public LeiFengFactory {
    public :
        LeiFeng * CreateLeiFeng() {
            return new Volunteer();
        }
};


int main() {
    LeiFengFactory * factory = new UndergraduateFactory;
    LeiFeng * leifeng = factory->CreateLeiFeng();

    leifeng->Wash();
    leifeng->Sweep();
    leifeng->BuyRice();

    free(factory);
    free(leifeng);

    factory = new VolunteerFactory;
    leifeng = factory->CreateLeiFeng();

    leifeng->Wash();
    leifeng->Sweep();
    leifeng->BuyRice();

    free(factory);
    free(leifeng);

    return 0;
}
