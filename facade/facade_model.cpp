/**
 * author : zhaohua
 * date : June 12th, 2016
 * discription: 《大话设计模式》，（程杰）。外观模式模型， page 109
 * **/

#include <iostream>

using namespace std;

/* 子系统类 */
class SubClassOne {
    public:
        void MethodOne() {
            cout << "this is the MethodOne from SubClassOne." << endl;
        }
};

/* 子系统类 */
class SubClassTwo {
    public:
        void MethodTwo() {
            cout << "this is the MethodTwo from SubClassTwo." << endl;
        }
};

/* 子系统类 */
class SubClassThree {
    public:
        void MethodThree() {
            cout << "this is the MethodThree from SubClassThree." << endl;
        }
};

/* 子系统类 */
class SubClassFour {
    public:
        void MethodFour() {
            cout << "this is the MethodFour from SubClassFour." << endl;
        }
};

/* 外观类 需要了解所有子系统的方法或属性，进行组合，以备外界使用*/
class Facade {
    private :
        SubClassOne * classOne;
        SubClassTwo * classTwo;
        SubClassThree * classThree;
        SubClassFour * classFour;
    public :
        Facade() {
            classOne = new SubClassOne();
            classTwo = new SubClassTwo();
            classThree = new SubClassThree();
            classFour = new SubClassFour();
        }

        void MethodA() {
            cout << "Method A -------" << endl;
            classOne->MethodOne();
            classTwo->MethodTwo();
            classFour->MethodFour();
        }

        void MethodB() {
            cout << "Method B -------" << endl;
            classTwo->MethodTwo();
            classThree->MethodThree();
        }
};


int main() {
    Facade * facade = new Facade();

    facade->MethodA();
    facade->MethodB();

    return 0;
}


