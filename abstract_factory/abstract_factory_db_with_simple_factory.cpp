/**
 * author : zhaohua
 * date : June 15th, 2016
 * discription : 《大话设计模式》，（程杰）。抽象工厂模式，使用简单工厂优化过的访问数据库实例。page151
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

#define TAG_SQL_SERVER 1
#define TAG_ACCESS 2
class DataAccess {
    private :
 //       static const int db = TAG_SQL_SERVER;
        static const int db = TAG_ACCESS;
    public :
        IUser * CreateUser() {
            switch(db) {
                case TAG_SQL_SERVER :
                    return new SQLServerUser();
                case TAG_ACCESS :
                    return new AccessUser();
                default :
                    return NULL;
            }
        }

        IDepartment * CreateDepartment() {
            switch(db) {
                case TAG_SQL_SERVER :
                    return new SQLServerDepartment();
                case TAG_ACCESS :
                    return new AccessDepartment();
                default :
                    return NULL;
            }
        }
};


int main() {
    DataAccess * da = new DataAccess();
    IUser * user = da->CreateUser();
    IDepartment * department = da->CreateDepartment();


    user->Insert();
    user->GetUser();

    department->Insert();
    department->GetDepartment();

    return 0;
}
