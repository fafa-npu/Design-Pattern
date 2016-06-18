/**
 * author : zhaohua
 * date : June 18th, 2016
 * discription : 《大话设计模式》，（程杰）。page173. 适配器模式模型代码
 * **/
#include <iostream>

using namespace std;

/* 客户所期待的接口，目标可以是具体的或抽象的类，也可以是接口 */
class Target {
    public :
        virtual void Request() {
            cout << "Commnon Request!" << endl;
        }
};

/* 需要适配的类 */
class Adaptee {
    public :
        void SpecificRequest() {
            cout << "Specific Request!" << endl;
        }
};

/* 通过在内部包装一个Adaptee类，把源接口转换成目标接口 */
class Adapter : public Target {
    private :
        Adaptee * _adaptee;
    public :
        Adapter() {
            this->_adaptee = new Adaptee();
        }

        void Request() {
            if (this->_adaptee != NULL) {
                this->_adaptee->SpecificRequest();
            }
        }
};


int main() {

    Target * target = new Adapter();
    target->Request();

    return 0;
}
