/**
* author : zhaohua
* date : June 16th, 2016
* discription: 《大话设计模式》，（程杰）。状态模式（state）模型示例。
* **/

#include "state_model.h"
#include <iostream>

using namespace std;

Context::Context(State * pState)  {
    this->_state = pState;
}
void Context::SetState(State * pState) {
    this->_state = pState;
    cout << this->_state->GetName() << endl;
}

State * Context::GetState() {
    return this->_state;
}

void Context::Request() {
    this->_state->Handle(this);
}

void State::SetName(string pName) {
    this->_name = pName;
}

string State::GetName() {
    return this->_name;
}


ConcreteStateA::ConcreteStateA() {
    this->SetName("StateA");
}

void ConcreteStateA::Handle(Context * context) {
    free(context->GetState());
    context->SetState(new ConcreteStateB());
}

ConcreteStateB::ConcreteStateB() {
    this->SetName("StateB");
}

void ConcreteStateB::Handle(Context * context) {
    free(context->GetState());
    context->SetState(new ConcreteStateA());
}


int main() {
    State * concreteState = new ConcreteStateA();
    Context * context = new Context(concreteState);

    context->Request();
    context->Request();
    context->Request();
    context->Request();

    free(concreteState);
    free(context);
    return 0;
}


