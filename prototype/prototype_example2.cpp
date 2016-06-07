/**
 * author : zhaohua
 * date : June 7th, 2016
 * discription: 《大话设计模式》（程杰）， 原型模式示例2。
 * 相对于example1， 重写拷贝构造函数， 使其变为深拷贝
 * **/


#include <iostream>

using namespace std;

class WorkExperience {
    private :
        string _workDate;
        string _company;
    public :
        string GetWorkDate() {
            return _workDate;
        }

        void SetWorkDate(string pWorkDate) {
            this->_workDate = pWorkDate;
        }

        string GetCompany() {
            return _company;
        }

        void SetCompany(string pCompany) {
            this->_company = pCompany;
        }
};

class Resume {
    private :
        string _name;
        string _sex;
        int  _age;
        WorkExperience * work;
    public :
        Resume(string pName) {
            this->_name = pName;
            this->work = new WorkExperience;
        }

        Resume(const Resume &oldResume) {
           this->work = new WorkExperience;
           this->_sex = oldResume._sex;
           this->_age = oldResume._age;
           this->_name = oldResume._name;
        }

        void SetPersonalInfo(string pSex, int pAge) {
            this->_sex = pSex;
            this->_age = pAge;
        }

        void SetWorkExperience(string pWorkDate, string pCompany) {
            this->work->SetWorkDate(pWorkDate);
            this->work->SetCompany(pCompany);
        }

        void Display() {
            cout << _name << "," << _sex << "," << _age << endl;
            cout << "word experience : " << work->GetWorkDate() << ", " << work->GetCompany() << endl;
        }
};

int main() {
    Resume daniao =  Resume("daniao");
    daniao.SetPersonalInfo("male", 21);
    daniao.SetWorkExperience("2011-2015", "nwpu");


    Resume daniao2 = daniao;
    daniao2.SetWorkExperience("2015-2018" , "nwpu-master");

    daniao.Display();
    daniao2.Display();


    return 0;


}

