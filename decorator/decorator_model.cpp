/**
 * author: zhaohua
 * date : June 5th, 2016
 * discription:
 *  装饰模式（Decorator）: 动态地给一个对象添加一些额外的职责，就增加功能来说，装饰模式比生成子类更为灵活
 *  《大话设计模式》， 程杰。 page 51
 *  **/

#include <iostream>
using namespace std;

/* 定义一个对象接口，可以给这些对象动态地添加职责 */
class Component {
    public :
        virtual void Operation() = 0;
};

/* 定义一个具体的对象，也可以给这些对象添加一些职责 */
class ConcreteComponent : public Component {
    public :
        void Operation() {
            cout << "Operation in ConcreteComponent" << endl;
        }
};

/* 装饰抽象类，继承了Component，从外类来扩展Component的功能，但对于Component来说，是无需知道Decorator的存在的 */
class Decorator : public Component {
    protected :
        Component * component;
    public :
        void SetComponent(Component * pComponent) {
            this->component = pComponent;
        }

        void Operation() {
            if (component != NULL) {
                component->Operation();
            }
        }
};

/* 具体装饰对象，起到给Component添加职责的功能 */
class ConcreteDecoratorA : public Decorator {
    public :
        void Operation() {
            Decorator::Operation();
            this->_AddedFunc();
        }
    private:
        void _AddedFunc() {
            cout << "Operation add by ConcreteDecoratorA." << endl;
        }
};

/* 具体装饰对象，起到给Component添加职责的功能 */
class ConcreteDecoratorB : public Decorator {
    public :
        void Operation() {
            Decorator::Operation();
            this->_AddedFunc();
        }
    private:
        void _AddedFunc() {
            cout << "Operation add by ConcreteDecoratorB." << endl;
        }
};



int main() {
    Component * component = new ConcreteComponent;
    Decorator * drtA = new ConcreteDecoratorA;
    Decorator * drtB = new ConcreteDecoratorB;

    drtA->SetComponent(component);
    drtB->SetComponent(drtA);

    drtB->Operation();
    return 0;
}

