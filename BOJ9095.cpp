// BOJ9095_1, 2, 3 더하기
#include <iostream>
using namespace std;
int T, n, cnt;
int mem[11];
void fx(int N) {
    if(!N) {
        cnt++;
        return;
    }
    if(N>=3) fx(N-3);
    if(N>=2) fx(N-2);
    if(N>=1) fx(N-1);
}
int main() {
    cin >> T;
    for(int i=0; i<T; i++) {
        cin >> n;
        cnt = 0;
        fx(n);
        cout << cnt << endl;
    }
}