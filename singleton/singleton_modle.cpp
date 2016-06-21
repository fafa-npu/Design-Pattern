/**
 * author : zhaohua
 * date : June 20th, 2016
 * discription : 《大话设计模式》， （程杰）。单例模式模型代码，page215
 * **/

#include <iostream>

using namespace std;

class Singleton {
    private :
        static Singleton * instance;
        Singleton() {
        }
    public :
        static Singleton * GetInstance() {
            if (instance == NULL) {
                instance = new Singleton();
            }

            return instance;
        }
};

Singleton * Singleton::instance = NULL;
int main() {
    Singleton * s1 = Singleton::GetInstance();
    Singleton * s2 = Singleton::GetInstance();

    if (s1 == s2) {
        cout << "same instance" << endl;
    }

    return 0;
}
