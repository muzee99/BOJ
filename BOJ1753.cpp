// BOJ1753_최단 경로
#include <iostream>
#include <cstring>

using namespace std;

int INF = 1000000;
int V, E, K;
int u, v, w;
int W[20002][20002];

int main() {
    cin >> V >> E >> K;
    memset(W, INF, sizeof(W));
    for(int i=0; i<E; i++) {
        cin >> u >> v >> w;
        W[u][v] = 2;
    }

}