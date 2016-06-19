/**
 * author : zhaohua
 * date : June 18th, 2016
 * discription : 《大话设计模式》，（程杰）。组合模式模型， page191
 * **/

#include <iostream>
#include <vector>

using namespace std;

class Component {
    protected :
        string name;
    public :
        Component(string pName) {
            this -> name = pName;
        }

        virtual void Add(Component * pComponent) = 0;
        virtual void Remove(Component * pComponent) = 0;
        virtual void Display(int depth) = 0;
        virtual string GetName() {
            return this->name;
        }
};


class Leaf : public Component {
    public :
        Leaf(string pName) : Component(pName) {
        }

        void Add(Component * pComponent) {
            cout << "this is a leaf component, cannot add child.";
        }

        void Remove(Component * pComponent) {
            cout << "this is a leaf component, cannot remove child.";
        }

        void Display(int depth) {
            string pre(depth, '-');
            cout << pre << this -> name << endl;
        }

};


class Composite : public Component {
    private :
        vector<Component * > * children ;
    public :
        Composite(string pName) : Component(pName) {
            children = new vector<Component*>();
        }

        void Add(Component * component) {
            children -> push_back(component);
        }

        void Remove(Component * component) {
            vector<Component *>::iterator itComponent = children->begin();
            for(itComponent = children->begin(); itComponent != children->end(); itComponent++) {
                if ((*itComponent)->GetName() == component->GetName()) {
                    children->erase(itComponent);
                    break;
                }
            }
        }

        void Display(int depth) {
            string pre(depth, '-');
            cout << pre << this->name << endl;
            vector<Component *>::iterator itComponent = children->begin();
            for(itComponent = children->begin(); itComponent != children->end(); itComponent++) {
                (*itComponent)->Display(depth + 2) ;
            }
        }
};

int main() {
    cout << "____START____" << endl;
    Composite * root = new Composite("root");
    root->Add(new Leaf("Leaf A"));
    root->Add(new Leaf("Leaf B"));

    Composite * comp = new Composite("Composite X");
    comp->Add(new Leaf("Leaf XA"));
    comp->Add(new Leaf("Leaf XB"));

    Composite * comp2 = new Composite("Composite XY");
    comp2->Add(new Leaf("Leaf XYA"));
    comp2->Add(new Leaf("Leaf XYB"));

    comp->Add(comp2);

    root->Add(comp);

    root->Add(new Leaf("Leaf C"));

    Leaf * leafD = new Leaf("Leaf D");
    root->Add(leafD);
    root->Remove(leafD);

    cout << "Display" << endl;
    root->Display(1);
    cout << "____END____" << endl;

    return 0;
}
