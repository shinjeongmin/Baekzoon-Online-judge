//#include<iostream>
//#include<vector>
//#define NODE 4
//using namespace std;
//
///* int graph[NODE][NODE] = {
//   {0, 1, 1, 0},
//   {0, 0, 1, 0},
//   {1, 0, 0, 1},
//   {0, 0, 0, 0}
//}; */
//
//int graph[NODE][NODE] = {
//   {1, 0, 1, 0},
//   {1, 0, 0, 1},
//   {0, 1, 1, 0},
//   {0, 1, 0, 0}
//};
//
//int result[NODE][NODE];
//
//void transClosure() {
//    for (int i = 0; i < NODE; i++)
//        for (int j = 0; j < NODE; j++)
//            result[i][j] = graph[i][j];    //initially copy the graph to the result matrix
//    for (int k = 0; k < NODE; k++)
//        for (int i = 0; i < NODE; i++)
//            for (int j = 0; j < NODE; j++)
//                result[i][j] = result[i][j] || (result[i][k] && result[k][j]);
//    for (int i = 0; i < NODE; i++) {          //print the result matrix
//        for (int j = 0; j < NODE; j++)
//            cout << result[i][j] << " ";
//        cout << endl;
//    }
//}
//
//int main() {
//    transClosure();
//}