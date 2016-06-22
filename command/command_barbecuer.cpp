/**
 * author : zhaohua
 * date : June 22, 2016
 * discription : 《大话设计模式》，（程杰）。命令模式，烧烤实例，page241
 * **/

#include <iostream>
#include <vector>

using namespace std;

#define TYPE_COMMAND 1
#define TYPE_COMMAND_MUTTON 2
#define TYPE_COMMAND_WING 3

class Barbecuer {
    public :
        void BakeMutton() {
            cout << "Bake Mutton!" << endl;
        }

        void BakeChickenWing() {
            cout << "Bake Chicken Wing!" << endl;
        }
};

class Command {
    protected :
        Barbecuer * _barbecuer;
    public :
        Command(Barbecuer * pBarbecuer) {
            this->_barbecuer = pBarbecuer;
        }
        virtual int  GetClassType() {
            return TYPE_COMMAND;
        };
        virtual void ExcuteCommand() = 0;
};

class BakeMuttonCommand : public Command {
    public :
        BakeMuttonCommand(Barbecuer * pBarbecuer) : Command(pBarbecuer) {
        }

        void ExcuteCommand() {
            this->_barbecuer->BakeMutton();
        }

        int GetClassType() {
            return TYPE_COMMAND_MUTTON;
        }

};

class BakeChickenWingCommand : public Command {
    public :
        BakeChickenWingCommand(Barbecuer * pBarbecuer) : Command(pBarbecuer) {
        }

        void ExcuteCommand() {
            this->_barbecuer->BakeChickenWing();
        }

        int GetClassType() {
            return TYPE_COMMAND_WING;
        }

};

class Waiter {
    private :
        vector<Command *> * orders;
    public :
        Waiter() {
            orders = new vector<Command *>();
        }
        void SetOrder(Command * pCommand) {
            cout << "type : " << pCommand->GetClassType() << endl;
            if (pCommand->GetClassType() == TYPE_COMMAND_WING ) {
                cout << "Waiter : wing is null , please reorder!" << endl;
            } else {
                orders->push_back(pCommand);
            }
        }

        void CancelOrder(Command * pCommand) {
            vector<Command *>::iterator it = orders->end();
            it = find(orders->begin(), orders->end(), pCommand);
            if (it != orders->end()) {
                orders->erase(it);
            }
        }

        void Notify() {
            vector<Command *>::iterator it = orders->end();
            for(it = orders->begin(); it != orders->end(); it++) {
                (*it)->ExcuteCommand();
            }
        }
};

int main() {
    Barbecuer * boy = new Barbecuer();
    Command * bakeMuttonCommand1 = new BakeMuttonCommand(boy);
    Command * bakeMuttonCommand2 = new BakeMuttonCommand(boy);

    Command * bakeWingCommand = new BakeChickenWingCommand(boy);


    Waiter * girl = new Waiter();
    girl->SetOrder(bakeMuttonCommand1);
    girl->SetOrder(bakeMuttonCommand2);
    girl->SetOrder(bakeWingCommand);
    girl->CancelOrder(bakeMuttonCommand2);

    girl->Notify();

    return 0;
}

