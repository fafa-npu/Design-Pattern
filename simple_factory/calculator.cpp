/**
 * author: zhaohua
 * date: June 4th, 2016
 * function: 实现一个简单的计算器
 * 使用简单工厂模式，代码参考自《大话设计模式》，程杰。
 **/

#include <iostream>
#include <map>

using namespace std;


class Operation {
public:
    double _valueA;
    double _valueB;
    string _operator;

    void setValueA(double valA) {
        _valueA = valA;
    }

    void setValueB(double valB) {
        _valueB = valB;
    }

    void setOperator(string opr) {
        _operator = opr;
    }

    virtual double getResult() {
        double result = 0.0;
        return result;
    }
};

class OperationAdd : public Operation {
    double getResult() {
        double result = _valueA + _valueB;
        return result;
    }
};


class OperationSub : public Operation {
    double getResult() {
        return _valueA - _valueB;
    }
};

class OperationMul : public Operation {
    double getResult() {
        return _valueA * _valueB;
    }
};

class OperationDiv : public Operation {
    double getResult() {
        if (_valueB == 0) {
            throw "invalid: a number cannot be divided by zero!";
        }
        return _valueA / _valueB;
    }
};

class OperationSimpleFactory {
    private:
        const static int STR_ADD = 1;
        const static int STR_SUB = 2;
        const static int STR_MUL = 3;
        const static int STR_DIV = 4;
    public:
        OperationSimpleFactory() {
        }
        static Operation * createOperation(string opr) {
        map<string , int > mp;
        mp["+"] = STR_ADD;
        mp["-"] = STR_SUB;
        mp["*"] = STR_MUL;
        mp["/"] = STR_DIV;
        Operation * operation;
        switch (mp[opr]) {
            case STR_ADD :
                operation = new OperationAdd();
                break;
            case STR_SUB :
                operation = new OperationSub();
                break;
            case STR_MUL :
                operation = new OperationMul();
                break;
            case STR_DIV :
                operation = new OperationDiv();
                break;
            default:
                break;

        }
        return operation;
    }
};

int main() {
    double valueA;
    double valueB;
    string opr;
    double result;

    cout << "input first value: " ;
    cin >> valueA;
    cout << "input operation symbol: ";
    cin >> opr;
    cout << "input second value:" << endl;
    cin >> valueB;

    Operation * operation = OperationSimpleFactory::createOperation(opr);
    operation->setValueA(valueA);
    operation->setValueB(valueB);

    try {
       result = operation->getResult();
    } catch (char const * exception) {
        cout <<"Get Exception: " <<  exception<< endl;
        return -1;
    }

    cout << "the result is : " << result << endl;
    return 0;

}
