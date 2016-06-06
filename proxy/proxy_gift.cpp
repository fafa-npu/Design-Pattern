/**
 * author : zhaohua
 * date : June 6th, 2016
 * discription: 《大话设计模式》（程杰）， 代理模式应用示例， page61
 * **/

#include <iostream>

using namespace std;

class IGiveGift {
    virtual void GiveDolls() = 0;
    virtual void GiveFlowers() = 0;
    virtual void GiveChocolate() = 0;
};

/* 追求者类 */
class Pursuit : public IGiveGift {
    private :
        string _name;
    public :
        Pursuit(string pName) {
            this->_name = pName;
        }

        void GiveDolls() {
            cout << _name << " gives dolls ";
        }

        void GiveFlowers() {
            cout << _name << " gives flowers " ;
        }

        void GiveChocolate() {
            cout << _name << " gives chocolate ";
        }
};

/* 代理者 */
class Proxy : public IGiveGift {
    private :
        string _name;
        Pursuit * _pursuit;
        string _receiver;
    public :
        Proxy(string pName) {
            this->_name = pName;
        }

        void SetPursuit(Pursuit * pPursuit) {
            this->_pursuit = pPursuit;
        }

        void SetReceiver(string pReceiverName) {
            this->_receiver = pReceiverName;
        }

        void GiveFlowers() {
            _pursuit->GiveFlowers();
            cout << " to " << _receiver;
            cout << " Proxy by " << _name << endl;
        }

        void GiveDolls() {
            _pursuit->GiveDolls();
            cout << " to " << _receiver;
            cout << " Proxy by " << _name << endl;
        }

        void GiveChocolate() {
            _pursuit->GiveChocolate();
            cout << " to " << _receiver;
            cout << " Proxy by " << _name << endl;
        }
};


int main() {
    Pursuit * zhuojiayi = new Pursuit("zhuojiayi");
    Proxy * daili = new Proxy("daili");

    daili->SetPursuit(zhuojiayi);
    daili->SetReceiver("jiaojiao");

    daili->GiveDolls();
    daili->GiveChocolate();
    daili->GiveFlowers();

    return 0;
}
