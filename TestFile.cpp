//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//string solution(string s) {
//    string answer = "";
//    answer = s;
//
//    if (answer.length() % 2 == 0) {//Â¦¼ö
//        answer = answer[(answer.length() / 2) - 1] + answer[answer.length() / 2];
//    }
//    else {//È¦¼ö
//        answer = answer[answer.length() / 2];
//    }
//    return answer;
//}
//
//int main() {
//    string s,answer;
//    cin >> s;
//    //answer = solution(s);
//    answer = s[s.length() / 2 -1];
//    answer += s[s.length() / 2];
//    cout << answer;
//}