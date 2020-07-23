//#include<iostream>
//#include<cstring>
//#pragma warning (disable : 4996)
//using namespace std;
//
//class Data{
//private:
//    char* name;
//    char* phone;
//    int age;
//public:
//    Data(const char* _name, const char* _phone, int _age) {            //생성자는 char* 자료형만 받는다.
//        name = new char[strlen(_name) + 1];
//        strcpy(name, _name);
//        phone = new char[strlen(_phone) + 1];
//        strcpy(phone, _phone);
//        age = _age;
//    }
//    Data(const Data& object) {
//        name = new char[strlen(object.name) + 1];
//        strcpy(name, object.name);
//        phone = new char[strlen(object.phone) + 1];
//        strcpy(phone, object.phone);
//
//        age = object.age;
//    }
//    void output() {
//        cout << name << endl;
//        cout << phone << endl;
//        cout << age << endl;
//    }
//    void modify(const char* val) {
//        strcpy(name, val);
//    }
//    ~Data() {
//        delete[]name;
//        delete[] phone;
//    }
//};
//
//int main() {
//    Data* a = new Data("Shin", "010", 21);
//    Data b(*a);
//
//    a->output();
//    a->modify("aaa");
//    b.output();
//    delete a;
//    b.output();
//    return 0;
//}