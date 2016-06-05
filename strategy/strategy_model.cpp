/**
 * author:zhaohua
 * date:June 5th, 2016
 * 策略模式的基本模型
 * 《大话设计模式》，程杰 page23
 **/

#include <iostream>
using namespace std;

/**
 * 策略类，定义所有支持的算法的公共接口
 **/
class Strategy {
    public:
        virtual void AlgorithmInterface() {
            cout << "this is the base strategy!" << endl;
        }
};


/**
 * 具体策略类，封装了具体的算法或行为， 继承于Strategy
 **/
class ConcreteStrategyA : public Strategy{
    void AlgorithmInterface() {
        cout << "this is the function of StrategyA!" << endl;
    }
};

class ConcreteStrategyB : public Strategy{
    void AlgorithmInterface() {
        cout << "this is the function of StrategyB!" << endl;
    }
};

/*
 * 上下文， 用一个ConcreteStrategy来配置，维护一个对Strategy对象的引用
 **/
class Context {
    public :
        Strategy * strategy;
        Context(Strategy * pStrategy) {
            this->strategy = pStrategy;
        }

        // 上下文接口
        void ContextInterface() {
            if (strategy != NULL) {
                strategy->AlgorithmInterface();
            }
        }
};

int main() {
    Context * contextA = new Context(new ConcreteStrategyA());
    contextA->ContextInterface();

    Context * contextB = new Context(new ConcreteStrategyB());
    contextB->ContextInterface();

    return 0;
}


