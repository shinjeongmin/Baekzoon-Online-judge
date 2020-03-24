//#include <iostream>
//#include <string>
//#include <sstream>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    string line;
//    //cin은 개행문자 전까지 읽고 처음에 나오는 개행문자는 무시
//    //getline은 개행문자까지 읽고 처음에 나오는 개행문자도 읽음
//    //그러므로 cin으로 처음값 N을 읽고 난 후 개행문자를 읽어주는 getline을 한번 호출 해 줘야 된다 
//    getline(cin, line);
//    for (int i = 0; i < n; i++) {
//        //\n이 나올 때 까지 읽기 (한줄 읽기)
//        getline(cin, line);
//        //한 줄 읽은 뒤 ' ' 을 기준으로 split
//        istringstream ss(line);
//        string buffer;
//        while (getline(ss, buffer, ' ')) {
//            //' ' 문자가 나올 때까지 읽는다.
//            int value = atoi(buffer.c_str());
//            //... 받은 value를 처리...
//        }
//    }
//}