/**
 * author : zhaohua
 * date : June 16th, 2016
 * discription: 《大话设计模式》，（程杰）。状态模式（state）模型示例。
 * **/
#ifndef STATE_MODEL_H_
#define STATE_MODEL_H_

#include <string>
class State;
class Context;
class ConcreteStateA;
class ConcreteStateB;
/* 维护一个ConcreteState子类的实例，这个实例定义当前的状态 */
class Context {
    private :
        State * _state;
    public :
        Context(State * pState);

        void SetState(State * pState);

        State * GetState();

        void Request();
};


/* 抽象状态类，定义一个接口以封装与Context的一个特定状态相关的行为 */
class State {
    private :
        std::string _name;
    public :
        virtual void Handle(Context * context) = 0;

        void SetName(std::string pName);

        std::string GetName();
};


/* 具体状态，每一个子类实现一个与Context的一个状态相关的行为 */
class ConcreteStateA : public State {
    public :
        ConcreteStateA();

        void Handle(Context * context);
};

class ConcreteStateB : public State {
    public :
        ConcreteStateB();

        void Handle(Context * context);
};


#endif
