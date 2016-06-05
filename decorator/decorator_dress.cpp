/**
 * author: zhaohua
 * date: June 5th, 2016
 * discription: 《大话设计模式》（程杰），page53，小菜扮靓
 * **/

#include <iostream>
using namespace std;

class Person {
    private:
        string name;
    public :
        Person(string pName) {
            this->name = pName;
        }

        Person() {
            ;
        }
        virtual void Show() {
            cout << "Dressed person : " << this->name  << endl;
        }
};

class Finery : public Person {
    protected:
        Person * person;
    public :
        void Decorate(Person * pPerson) {
            this->person = pPerson;
        }

        void Show() {
            if (person != NULL) {
                person->Show();
            }
        }
};

class TShirts : public Finery {
    public :
        void Show() {
            Finery::Show();
            this->DressTShirts();
        }

    private :
        void DressTShirts() {
            cout << "TShirt." << endl;
        }
};

class Suit : public Finery {
    private :
        void DressSuit() {
            cout << "Suit." << endl;
        }

    public :
        void Show() {
            Finery::Show();
            this->DressSuit();
        }
};

class Tie : public Finery {
    private :
        void DressTie () {
            cout << "Tie." << endl;
        }

    public :
        void Show() {
            Finery::Show();
            this->DressTie();
        }
};


int main()  {
    Person * xiaocai = new Person("xiaocai");
    Finery * suit = new Suit;
    Finery * tie = new Tie;
    Finery * tshirt = new TShirts;

    suit->Decorate(xiaocai);
    tie->Decorate(suit);
    tshirt->Decorate(tie);

    tshirt->Show();

    return 0;
}
