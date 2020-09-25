// BOJ2447_별 찍기 - 10
#include <iostream>
#include <cstring>
using namespace std;
int N;
char S[2200][2200];
void fx(int n, int X, int Y) {
    if(n==1) return;
    else {
        for(int i=0; i<n/3; i++) {
            for(int j=0; j<n/3; j++) {
                S[X+n/3+i][Y+n/3+j] = ' ';
            }
        }
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                fx(n/3, X+i*n/3, Y+j*n/3);
            }
        }
    }
}
int main() {
    cin >> N;
    memset(S, '*', sizeof(S));
    fx(N, 0, 0);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << S[i][j];
        }
        cout << "\n";
    }
}