/**
 * author : zhaohua
 * date : June 5th, 2016
 * discription: 代理模式（Proxy）模型，为其他对象提供一种代理以控制对这个对象的访问
 *  《大话设计模式》（程杰）， page63.
 *  **/

#include <iostream>

using namespace std;

/* Subject 类， 定义了RealSubject和Proxy的公用接口，这样就可以在任何使用了RealSubject的地方使用Proxy替代 */
class Subject {
    public :
        virtual void Request() = 0;
};


/* RealSubject 类， 定义Proxy代表的真实实体 */
class RealSubject : public Subject {
    public:
        void Request () {
            cout << "Request from RealSubject. " << endl;
        }
};


/* Proxy代理类， 保存一个引用是的代理可以访问实体，并提供一个与Subject的接口相同的接口，这样就可以用代理来代替实体 */
class Proxy : public Subject {
    public :
        RealSubject * realSubject;
        void Request() {
            cout << "This is a proxy request." << endl;
            if (realSubject == NULL) {
                realSubject = new RealSubject;
            }
            realSubject->Request();
        }
};


int main() {
    Proxy * proxy = new Proxy;
    proxy->Request();


    return 0;
}
