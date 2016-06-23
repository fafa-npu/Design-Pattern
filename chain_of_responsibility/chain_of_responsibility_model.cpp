/**
 * author : zhaohua
 * date : June 23, 2016
 * discription : 《大话设计模式》，（程杰）。职责链模式模型代码，page249
 * **/

#include <iostream>
#include <list>

using namespace std;

class Handler {
    protected :
        Handler * _successor;
    public :
        void SetSuccessor(Handler * pSuccessor) {
            this->_successor = pSuccessor;
        }

        virtual void HandlerRequest(int pRequest) = 0;
};

class ConcreteHandler1 : public Handler {
    public :
        void HandlerRequest(int pRequest) {
            if (pRequest < 10) {
                cout << "handler 1 process request " << pRequest << endl;
            } else {
                this->_successor->HandlerRequest(pRequest);
            }
        }
};

class ConcreteHandler2 : public Handler {
    public :
        void HandlerRequest(int pRequest) {
            if (pRequest >= 10 && pRequest < 20) {
                cout << "handler 2 process request " << pRequest << endl;
            } else {
                this->_successor->HandlerRequest(pRequest);
            }
        }
};

class ConcreteHandler3 : public Handler {
    public :
        void HandlerRequest(int pRequest) {
            if (pRequest >= 20 && pRequest < 30) {
                cout << "handler 3 process request " << pRequest << endl;
            } else {
                cout << "request is out of limited." << endl;
            }
        }
};

int main() {
    Handler * h1 = new ConcreteHandler1();
    Handler * h2 = new ConcreteHandler2();
    Handler * h3 = new ConcreteHandler3();


    h1->SetSuccessor(h2);
    h2->SetSuccessor(h3);
    h3->SetSuccessor(NULL);

    int requestArray [] = {1, 2, 11, 24, 33, 15,26};
    size_t requestsSize = sizeof(requestArray) / sizeof(int);

    list<int> requests(requestArray, requestArray + requestsSize);

    list<int>::iterator it = requests.end();
    for(it = requests.begin(); it != requests.end(); it++) {
        h1->HandlerRequest(*it);
    }

    return 0;
}
