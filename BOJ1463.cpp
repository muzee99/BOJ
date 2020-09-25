// BOJ1463_1로 만들기
#include <iostream>
using namespace std;
int N, cnt=0;
int main() {
    cin >> N;
    while(1){
        if(!(N%3)) {
            N = N/3;
            cnt++;
        }
        else if(!(N%2)) {
            N = N/2;
            cnt++;
        }
        else {
            N--;
            cnt++;
        }
        if(N==1) break;
    }
    cout << cnt;
}