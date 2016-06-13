/**
 * author : zhaohua
 * date : June 13th, 2016
 * discription : 《大话设计模式》，（程杰）。建造者模式模型示例，page119
 * **/

#include <iostream>
#include <vector>
using namespace std;

/* Product 类--产品类，由多个部件构成 */
class Product {
    private :
        vector<string>  _parts;
    public :
        Product() {
        }

        // 添加部件
        void Add(string part) {
            _parts.push_back(part);
        }

        // 显示部件
        void Show() {
            cout << "Product build." << endl;
            for (vector<string>::iterator it = _parts.begin(); it != _parts.end(); it++) {
                cout << *it << endl;
            }
        }
};

/* 抽象建造者类， 为创建Product对象的各个部件创建抽象接口 */
class Builder {
    public :
        virtual void BuildPartA() = 0;
        virtual void BuildPartB() = 0;
        virtual Product * GetResult() = 0;
};

/* 具体建造者， 实现Builder接口 */
class ConcreteBuilderA : public Builder {
    private :
         Product * _product;
    public :
        ConcreteBuilderA() {
            _product = new Product();
        }
        void BuildPartA() {
            _product->Add("Part A");
        }

        void BuildPartB() {
            _product->Add("Part B");
        }

        Product * GetResult() {
            return _product;
        }
};

/* 具体建造者， 实现Builder接口 */
class ConcreteBuilderB : public Builder {
    private :
        Product * _product;

    public :
        ConcreteBuilderB() {
            _product = new Product();
        }

        void BuildPartA() {
            _product->Add("Part X");
        }

        void BuildPartB() {
            _product->Add("Part Y");
        }

        Product * GetResult() {
            return _product;
        }
};

/* 指挥者， 构建一个使用Builder接口的对象, 用来指挥构建过程 */
class Director {
    public :
        void Construct(Builder * builder) {
            builder->BuildPartA();
            builder->BuildPartB();
        }
};


int main() {
    Director * director = new Director();

    Product *productA, *productB;
    // 实例化Builder
    Builder * builderA = new ConcreteBuilderA();
    Builder * builderB = new ConcreteBuilderB();

    director->Construct(builderA);
    productA = builderA->GetResult();
    productA->Show();

    director->Construct(builderB);
    productB = builderB->GetResult();
    productB->Show();

    return 0;
}

