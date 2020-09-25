// BOJ1780_종이의 개수
#include <iostream>
#include <vector>

using namespace std;

int N;
int M[2200][2200];
int cnt[3];

int isPaper(int k, int m[2]) {
    int key = M[m[0]][m[1]];
    for(int i=0; i<k; i++) {
        for(int j=0; j<k; j++) {
            if(M[i+m[0]][j+m[1]]!=key) return 0;
        }
    }
    return 1;
}

void fx(int n, int m[2]) {
    int key = M[m[0]][m[1]];
    if(n==1) cnt[key+1]++;
    else if(isPaper(n, m)) cnt[key+1]++;
    else {
        int ix[2];
        for(int i=0; i<3; i++) {
            ix[0] = m[0] + i*n/3;
            for(int j=0; j<3; j++) {
                ix[1] = m[1] + j*n/3;
                fx(n/3, ix);
            }
        }
    }
}

int main() {
    int m[2] = {0,0};
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> M[i][j];
        }
    }

    fx(N, m);

    for(int i=0; i<3; i++) {
        cout << cnt[i] << "\n";
    }

    return 0;
}