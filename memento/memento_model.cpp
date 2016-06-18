/**
 * author : zhaohua
 * date : June 18th, 2016
 * discription : 《大话设计模式》， （程杰）。备忘录模式（memento）模型代码.page 184
 * **/

#include <iostream>

using namespace std;

/* 备忘录，负责存储Originator对象的内部状态，并且可以防止Originator以外的其他对象访问 */
class Memento {
    private :
        string _state;
    public :
        Memento(string pState) {
            SetState(pState);
        }

        void SetState(string pState) {
            this->_state = pState;
        }

        string GetState() {
            return this->_state;
        }
};

/* 原始对象，通过创建备忘录来保存自己的内部状态, 并且可以使用备忘录来回复原来状态 */
class Originator {
    private :
        string _state;
    public :
        Memento * CreateMemento() {
            return new Memento(this->_state);
        }

        void SetMemento(Memento * memento) {
            this->_state = memento->GetState();
        }

        void SetState(string pState) {
            this->_state = pState;
        }

        void ShowState() {
            cout << "State : " << this->_state << endl;
        }
};

/* 保存备忘录 */
class Caretaker {
    private :
        Memento * _memento;
    public :
        void SetMemento(Memento * pMemento) {
            this->_memento = pMemento;
        }

        Memento * GetMemento() {
            return this->_memento;
        }
};


int main() {
    Originator * o = new Originator();
    o->SetState("off");
    o->ShowState();

    Caretaker * taker = new Caretaker();
    taker->SetMemento(o->CreateMemento());

    o->SetState("on");
    o->ShowState();

    o->SetMemento(taker->GetMemento());
    o->ShowState();

    return 0;
}


