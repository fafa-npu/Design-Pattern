/**
 * author : zhaohua
 * date : June 15th, 2016
 * discription : 《大话设计模式》，（程杰）。抽象工厂模式，访问数据库实例。page147
 * **/

#include <iostream>

using namespace std;

class IUser {
    public :
        virtual void Insert() {
            cout << "Insert a user into db." << endl;
        }

       virtual void GetUser() {
           cout << "Get a user from DB." << endl;
       }
};

class IDepartment {
    public :
        virtual void Insert() {
            cout << "Insert a department into DB." << endl;
        }

        virtual void GetDepartment() {
            cout << "Get a department from DB." << endl;
        }
};


class SQLServerUser : public IUser {
    public :
        virtual void Insert() {
            cout << "Insert a user into SQLServer." << endl;
        }

       virtual void GetUser() {
           cout << "Get a user from SQLServer." << endl;
       }

};


class AccessUser : public IUser {
    public :
        virtual void Insert() {
            cout << "Insert a user into Access." << endl;
        }

       virtual void GetUser() {
           cout << "Get a user from Access." << endl;
       }
};

class SQLServerDepartment : public IDepartment {
    public :
        virtual void Insert() {
            cout << "Insert a department into SQLServer." << endl;
        }

       virtual void GetDepartment() {
           cout << "Get a department from SQLServer." << endl;
       }
};

class AccessDepartment : public IDepartment {
    public :
        virtual void Insert() {
            cout << "Insert a department into Access." << endl;
        }

       virtual void GetDepartment() {
           cout << "Get a department from Access." << endl;
       }
};


class IFactory {
    public :
        virtual IUser * CreateUser() = 0;
        virtual IDepartment * CreateDepartment() = 0;
};

class SQLServerFactory : public IFactory {
    public :
        IUser * CreateUser() {
            return new SQLServerUser();
        }

        IDepartment * CreateDepartment() {
            return new SQLServerDepartment();
        }
};

class AccessFactory : public IFactory {
    public :
        IUser * CreateUser() {
            return new AccessUser();
        }

        IDepartment * CreateDepartment() {
            return new AccessDepartment();
        }
};


int main() {
    IFactory * factory = new SQLServerFactory();
    IUser * user = factory->CreateUser();
    IDepartment * department = factory->CreateDepartment();


    user->Insert();
    user->GetUser();

    department->Insert();
    department->GetDepartment();

    factory = new AccessFactory();
    user = factory->CreateUser();
    department = factory->CreateDepartment();


    user->Insert();
    user->GetUser();

    department->Insert();
    department->GetDepartment();



    return 0;
}
