//#include <iostream>
//#include <string>
//#include <sstream>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    string line;
//    //cin�� ���๮�� ������ �а� ó���� ������ ���๮�ڴ� ����
//    //getline�� ���๮�ڱ��� �а� ó���� ������ ���๮�ڵ� ����
//    //�׷��Ƿ� cin���� ó���� N�� �а� �� �� ���๮�ڸ� �о��ִ� getline�� �ѹ� ȣ�� �� ��� �ȴ� 
//    getline(cin, line);
//    for (int i = 0; i < n; i++) {
//        //\n�� ���� �� ���� �б� (���� �б�)
//        getline(cin, line);
//        //�� �� ���� �� ' ' �� �������� split
//        istringstream ss(line);
//        string buffer;
//        while (getline(ss, buffer, ' ')) {
//            //' ' ���ڰ� ���� ������ �д´�.
//            int value = atoi(buffer.c_str());
//            //... ���� value�� ó��...
//        }
//    }
//}