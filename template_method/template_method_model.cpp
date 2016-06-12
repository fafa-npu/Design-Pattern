/**
 * author : zhaohua
 * date : June 12th, 2016
 * discription : 《大话设计模式》，（程杰）， 模板方法模式模型， page 97
 * **/

#include <iostream>

using namespace std;

/* AbstractClass, 实现了一个模板方法， 定义了算法的骨架，
 * 具体子类将重定义PrimitiveOperation 以实现一个算法的步骤 */
class AbstractClass {
    public :
        void TemplateMethod() {
            cout << "this is the template method in AbstractClass." << endl;
            PrimitiveOperation1();
            PrimitiveOperation2();
        }

        virtual void PrimitiveOperation1() = 0;
        virtual void PrimitiveOperation2() = 0;
};

/* 实现PrimitiveOperation以完成算法中与特定子类相关的步骤 */
class ConcreteClassA : public AbstractClass {
    void PrimitiveOperation1() {
        cout << "PrimitiveOperation1 from ConcreteClassA" << endl;
    }
    void PrimitiveOperation2() {
        cout << "PrimitiveOperation2 from ConcreteClassA" << endl;
    }
};

/* 实现PrimitiveOperation以完成算法中与特定子类相关的步骤 */
class ConcreteClassB : public AbstractClass {
    void PrimitiveOperation1() {
        cout << "PrimitiveOperation1 from ConcreteClassB" << endl;
    }
    void PrimitiveOperation2() {
        cout << "PrimitiveOperation2 from ConcreteClassB" << endl;
    }
};


int main() {
    AbstractClass * classA = new ConcreteClassA();
    AbstractClass * classB = new ConcreteClassB();

    classA->TemplateMethod();
    classB->TemplateMethod();

    return 0;
}
