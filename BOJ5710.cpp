// BOJ5710_거의 최단 경로
#include <iostream>

using namespace std;
int N, M, S, D;
int NaN = 10000005;

int main() {
    cin >> N >> M;
    cin >> S >> D;
    int path[N][N];
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i==j) path[i][j]=0;
            else path[i][j] = NaN;
        }
    }
    for(int i=0; i<M; i++) {
        int U, V, P;
        cin >> U >> V >> P;
        path[U][V] = P;
    }
        
    return 0;
}