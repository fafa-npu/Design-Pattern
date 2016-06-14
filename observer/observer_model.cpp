/**
 * author : zhaohua
 * date : June 14th, 2016
 * discription : 《大话设计模式》，（程杰）。观察者（发布订阅）模式示例.page132
 * warning!!! : 交叉引用！！！编译错误！！！！
 * **/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Subject;
class Observer;
class ConcreteSubject;
/* 抽象观察者类，为所有的具体观察者定义一个借口，在得到Subject的通知时更新自己 */
class Observer {
    public :
            virtual void Update();
};

/* 具体观察者，实现抽象观察者所要求的更新接口，以便使本身的状态与Subject的状态相协调 */
class ConcreteObserver : public Observer {
    private :
        string name;
        string observerState;
        ConcreteSubject * subject;
    public :
        ConcreteObserver(ConcreteSubject * pSubject, string pName){
            this->subject = pSubject;
            this->name = pName;
        }

        void Update() {
            observerState = subject->GetState();
            cout << "New state of " << name << " is " << observerState << endl;
        }
};

/* Subject类，把所有观察者的引用保存在一个聚集里，每个Subject都可以有任何数量的观察者。抽象Subject提供一个借口，可以增加或删除观察者对象。 */
class Subject {
    private :
        vector<Observer *> observerVector;
    public :
        void Attach(Observer * observer) {
            observerVector.push_back(observer);
        }

        void Detach(Observer * observer) {
            vector<Observer *>::iterator itObserver = find(observerVector.begin(), observerVector.end(), observer);
            observerVector.erase(itObserver);
        }

        void Notify() {
            for (vector<Observer *>::iterator it = observerVector.begin(); it != observerVector.end(); it++) {
                (*it)->Update();
            }
        }

};

/* 具体Subject类，将有关状态存入具体观察者对象；在具体Subject类内部的状态改变时，给所有等级过的观察者发出通知 */
class ConcreteSubject : public Subject {
    private :
        string _state;
    public :
        string GetState() {
            return _state;
        }

        void SetState(string pState) {
            _state = pState;
        }
};





