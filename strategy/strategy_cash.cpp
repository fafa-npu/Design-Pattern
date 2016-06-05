/**
 * author: zhaohua
 * date : June 5th, 2016
 * discription: 《大话设计模式》，程杰 page25 收银程序的策略模式实现（结合简单工厂）
 * **/

#include <iostream>
using namespace std;

class Constant {
    public:
        const static int TYPE_NORMAL = 1;
        const static int TYPE_REBATE = 2;
        const static int TYPE_RETURN = 3;

        const static double MONEY_CONDITION = 300;
        const static double MONEY_RETURN = 100;

        const static double MONEY_REBATE = 0.8;
};

class CashSuper {
    public:
        virtual double acceptCash(double money) {
            return money;
        }
};

class CashNormal : public CashSuper {
    public:
        double acceptCash(double money) {
            return money;
        }
};

class CashRebate : public CashSuper {
    private:
        double moneyRebate;
    public :
        CashRebate (double rate) {
            this->moneyRebate= rate;
        }

        double acceptCash(double money) {
            return money * this->moneyRebate;
        }
};

class CashReturn : public CashSuper {
    private :
        double moneyCondition;
        double moneyReturn;
    public :
        CashReturn(double pMoneyCondition, double pMoneyReturn) {
            this->moneyCondition = pMoneyCondition;
            this->moneyReturn = pMoneyReturn;
        }

        double acceptCash(double money) {
            double result = money;
            if (money >= this->moneyCondition) {
                result -= (int) (money / moneyCondition) * moneyReturn;
            }
            return result;
        }
};

class CashContext {
    private :
        CashSuper * cs;
    public:
        CashContext(int type) {
           switch (type) {
               case Constant::TYPE_NORMAL:
                   cs = new CashNormal();
                   break;
               case Constant::TYPE_REBATE:
                   this->cs = new CashRebate(Constant::MONEY_REBATE);
                   break;
               case Constant::TYPE_RETURN:
                   this->cs = new CashReturn(Constant::MONEY_CONDITION, Constant::MONEY_RETURN);
                   break;
               default:
                   cout << "Invalid input !" << endl;
                   break;
           }
        }

        double getResultMoney(double money) {
            return cs->acceptCash(money);
        }
};



int main() {
    double money;
    int cashType = 0;
    cout << "请输入消费总额：" << endl;
    cin >> money;
    cout << "请输入优惠模式：" << endl << Constant::TYPE_NORMAL << " : 正常收费 " << endl
        << Constant::TYPE_REBATE << " : 八折优惠 " << endl
        << Constant::TYPE_RETURN << " : 满300减100 " << endl;
    cin >> cashType;
    CashContext * cc = new CashContext(cashType);
    cout << "收费金额为： " << cc->getResultMoney(money);

    return 0;

}
