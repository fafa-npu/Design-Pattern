/**
 * author : zhaohua
 * date : June 21, 2016
 * discription : 《大话设计模式》，（程杰）。桥接模式（bridge）基本代码，page231
 * **/

#include <iostream>

using namespace std;

/* 实现 */
class Implementor {
    public :
        virtual void OperationImp() = 0;
};

/* 具体实现 */
class ConcreteImplementorA : public Implementor {
    public :
        void OperationImp() {
            cout << "Concrete Implementor A operation." << endl;
        }
};

/* 具体实现 */
class ConcreteImplementorB : public Implementor {
    public :
        void OperationImp() {
            cout << "Concrete Implementor B operation." << endl;
        }
};


/* 抽象 */
class Abstraction {
    protected :
        Implementor * _implementor;
    public :
        void SetImplementor(Implementor * pImplementor) {
            this->_implementor = pImplementor;
        }

        virtual void Operation() {
            this->_implementor->OperationImp();
        }
};

/* 被提炼的抽象 */
class RefinedAbstraction : public Abstraction {
    public :
        void Operation() {
            this->_implementor->OperationImp();
        }
};

int main() {
    Abstraction * ab = new RefinedAbstraction();
    ab->SetImplementor(new ConcreteImplementorA());
    ab->Operation();

    ab->SetImplementor(new ConcreteImplementorB());
    ab->Operation();

    return 0;
}
