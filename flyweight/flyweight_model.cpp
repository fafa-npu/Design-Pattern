/**
 * author : zhaohua
 * date : July 4, 2016
 * discription : 《大话设计模式》，（程杰）。享元模式模型代码（page269）
 * **/

#include <iostream>
#include <map>

using namespace std;

class Flyweight {
    public :
        virtual void Operation(int extrinsicstate) = 0;
};

class ConcreteFlyweight : public Flyweight{
    public :
        void Operation(int extrinsicstate) {
            cout << "Concrete : "  << extrinsicstate << endl;
        }
};

class UnsharedConcreteFlyweight : public Flyweight {
    public :
        void Operation(int extrinsicstate) {
            cout << "UnsharedConcrete : "  << extrinsicstate << endl;
        }
};

class FlyweightFactory {
    private :
        map<string, ConcreteFlyweight *> * flyweights;
    public :
        FlyweightFactory() {
            flyweights = new map<string, ConcreteFlyweight *>();
            flyweights->insert(make_pair("X", new ConcreteFlyweight()));
            flyweights->insert(make_pair("Y", new ConcreteFlyweight()));
            flyweights->insert(make_pair("Z", new ConcreteFlyweight()));
        }

        Flyweight * GetFlyweight(string key) {
            return (*flyweights)[key];
        }
};

int main() {
    int extrinsicstate = 22;

    FlyweightFactory * factory = new FlyweightFactory();

    Flyweight * fx = factory->GetFlyweight("X");
    fx->Operation(--extrinsicstate);

    Flyweight * fy = factory->GetFlyweight("Y");
    fy->Operation(--extrinsicstate);

    Flyweight * fz = factory->GetFlyweight("Z");
    fz->Operation(--extrinsicstate);

    Flyweight * uf = new UnsharedConcreteFlyweight();
    uf->Operation(--extrinsicstate);

    return 0;
}
