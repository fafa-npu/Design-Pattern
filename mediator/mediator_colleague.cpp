/**
 * author : zhaohua
 * date : June 26, 2016
 * discription : 《大话设计模式》，（程杰）。中介者模式colleague示例，page259
 * **/

#include <iostream>

using namespace std;

#define TYPE_COLLEAGUE 0
#define TYPE_COLLEAGUE_1 1
#define TYPE_COLLEAGUE_2 2


typedef int type;

class Colleague;

/* 抽象中介者 */
class Mediator {
    public :
        virtual void Send(string pMsg, type type_id) = 0;
};

/* 抽象同事类 */
class Colleague {
    protected :
        Mediator * mediator;

    public :
        Colleague(Mediator * pMediator) {
            this->mediator  = pMediator;
        }

        virtual void Send(string pMsg) = 0;
        virtual void Notify(string pMg) = 0;
};

/* 具体同事类 */
class ConcreteColleague1 : public Colleague {
    public :
        ConcreteColleague1(Mediator * pMediator) : Colleague(pMediator) {}

        void Send(string pMsg) {
            this->mediator->Send(pMsg, TYPE_COLLEAGUE_1);
        }

        void Notify(string pMsg) {
            cout << "Colleague 1 reveived : " << pMsg << endl;
        }
};

/* 具体同事类 */
class ConcreteColleague2 : public Colleague {
    public :
        ConcreteColleague2(Mediator * pMediator) : Colleague(pMediator) {}

        void Send(string pMsg) {
            this->mediator->Send(pMsg, TYPE_COLLEAGUE_2);
        }

        void Notify(string pMsg) {
            cout << "Colleague 2 reveived : " << pMsg << endl;
        }
};

class ConcreteMediator : public Mediator {
    private :
        Colleague * _colleague1;
        Colleague * _colleague2;

    public :
        void SetColleague1(Colleague * colleague) {
            this->_colleague1 = colleague;
        }

        void SetColleague2(Colleague * colleague) {
            this->_colleague2 = colleague;
        }

        void Send(string pMsg, type type_id) {
            switch (type_id) {
                case TYPE_COLLEAGUE_1 :
                    this->_colleague2->Notify(pMsg);
                    break;
                case TYPE_COLLEAGUE_2:
                    this->_colleague1->Notify(pMsg);
                    break;
                default :
                    cout << "Invalid colleague type ! " << endl;
                    break;
            }
        }
};


int main() {
    ConcreteMediator * mediator = new ConcreteMediator();

    Colleague * colleague1 = new ConcreteColleague1(mediator);
    Colleague * colleague2 = new ConcreteColleague2(mediator);

    mediator->SetColleague1(colleague1);
    mediator->SetColleague2(colleague2);

    colleague1->Send("wow! why don't you go home?");
    colleague2->Send("what? why should I go home?");


    return 0;
}
