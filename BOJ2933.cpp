// BOJ2933_미네랄
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int R, C, N, h, grnd;
int cave[101][101];
int check[101][101];
int ceiling=0;
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
vector<pair<int, int>> neighbor;
vector<int> cluster[101];
int cur_r, cur_c, cnt;

void attack(int d, int height) {
    int i;
    if(!d) {
        for(i=0; i<C; i++) {
            if(cave[height][i]) {
                cave[height][i] = 0;
                break;
            }
        }
    }
    else {
        for(i=C; i>0; i--) {
            if(cave[height][i]) {
                cave[height][i] = 0;
                break;
            }
        }
    }
    cur_c = i;
    cur_r = height;
}
void clustering(int r, int c) {
    int 
    queue<pair<int ,int>> q;
    q.push(pair<int, int> (r,c));
    check[r][c] = true;
    while(!q.empty()) {
        pair<int, int> x = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            pair<int, int> y = make_pair(x.first+dir[i][0], x.second+dir[i][1]);
            if(!check[y.first][y.second] && cave[y.first][y.second]) {
                check[y.first][y.second] = true;
                q.push(pair<int, int> (y.first, y.second));
                cluster[y.second].push_back(y.first);
                if(y.first==grnd) 
            }
        }
    }
    cnt++;
}
void isDistrib(int r, int c) {
    for(int i=0; i<4; i++) {
        int nei_r = r+dir[i][0];
        int nei_c = c+dir[i][1];
        if(cave[nei_r][nei_c] && !check[nei_r][nei_c]) clustering(nei_r, nei_c);
    }
}
int isFalling(int n, int max) {
    if(max==grnd) return 0;
    else {
        int j;
        for(j=0; j<cluster[n].size(); j++) {
            if(cluster[n][j]==max) {
                if(cave[cluster_c[n][j]][max+1]) break;
            }
        }
        if(j==cluster[n].size()) return 1;
        else return 0;
    }
}
void printCave() {
    for (int i = 0; i < R; i++){
        for(int j=0; j<C; j++) {
            cout << cave[i][j] << " ";
        }
        cout << "\n";
    }   
}

int main() {
    memset(cave, 0, sizeof(cave));
    memset(check, 0, sizeof(check));
    cin >> R >> C;
    grnd = R-1;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            char k;
            cin >> k;
            if(k == 'x') cave[i][j] = 1;
            else cave[i][j] = 0;
        }
    }
    cin >> N;
    for(int i=0; i<N; i++) {
        cnt = 0;
        memset(check, false, sizeof(check));
        cin >> h;
        h = R-h;
        attack(i%2, h);
        isDistrib(cur_r, cur_c);
        cout << h << " " << cnt << "\n";
        printCave();
        cout << "========================\n";
        int clust;
        if(cnt==2) {
            int max;
            for(clust=0; clust<2; clust++) {
                max = *max_element(cluster[clust].begin(), cluster[clust].end());
                if(isFalling(clust, max)) break;
            }
            for(int k=1; k<100; k++) {
                if(!isFalling(clust, max+k)) break;
            }
        }
    }
}