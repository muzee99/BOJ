// BOJ12865_평범한 배낭
#include <iostream>

using namespace std;

int N, K;
pair<int, int> goods[100];

int main() {
    cin >> N >> K;
    for(int i=0; i<N; i++) {
        int W, V;
        cin >> W >> V;
        goods[i] = pair<int, int> (W, V);
    }
    
}