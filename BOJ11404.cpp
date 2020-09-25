// BOJ11404_플로이드
#include <iostream>

using namespace std;

int n, m;
int route[100][100];
int NaN = 100000000;

int main() {
    cin >> n >> m;
    int minCost[n][n];
    for(int i=0; i<m; i++) {
        int begin, end, cost;
        cin >> begin >> end >> cost;
        if(!route[begin-1][end-1] || cost < route[begin-1][end-1]) 
            route[begin-1][end-1] = cost;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i!=j && !route[i][j]) route[i][j] = NaN;
        }
    }
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(route[i][j] > route[i][k]+route[k][j]) 
                    route[i][j] = route[i][k]+route[k][j];
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(route[i][j]==NaN) route[i][j] = 0;
            cout << route[i][j] << " ";
        }
        cout << "\n";
    }
}