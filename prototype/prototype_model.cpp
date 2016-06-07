/**
 * author : zhaohua
 * date : June 7th, 2016
 * discription : 《大话设计模式》（程杰）， 原型模式模型， page 81
 *   注：C++中有拷贝构造函数。
 * **/

#include <iostream>

using namespace std;

/* 原型类 */
class Prototype {
    private :
        string _id;

    public :
        Prototype(string pId) {
            this->_id = pId;
        }

        string GetId() {
            return this->_id;
        }
};



int main() {
    Prototype  proto("hello");
    Prototype clone = proto;

    cout << "clone : " << clone.GetId() << endl;

    return 0;
}


