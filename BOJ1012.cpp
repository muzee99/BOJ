// BOJ1012_유기농 배추
#include <iostream>
#include <queue>

using namespace std;

int T;
int M,N,K;
int a, b;
int count = 0;
int check[51][51];
int map[51][51];
int step[4][2] = {{-1,0}, {0,-1}, {0,1}, {1,0}};

int isInside(pair<int, int> locate) {
    if(locate.first>=0 && locate.first<N && locate.second>=0 && locate.second<M) return 1;
    else return 0;
}

void findIsland(int x, int y) {
    queue <pair<int, int>> q;
    q.push(pair<int, int>(x,y));
    check[x][y] = true;
    while(!q.empty()) {
        pair<int, int> land = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            pair<int, int> next_land(land.first+step[i][0], land.second+step[i][1]);
            if(isInside(next_land) && map[next_land.first][next_land.second] && !check[next_land.first][next_land.second]) {
                q.push(next_land);
                check[next_land.first][next_land.second] = true;
            }
        }
    }
    count++;
}

int main() {
    cin >> T;

    for(int i=0; i<T; i++) {
        cin >> N >> M >> K;
        for(int i=0; i<51; i++) {
            for(int j=0; j<51; j++) {
                check[i][j] = 0;
                map[i][j] = 0;
            }
        }
        for(int j=0; j<K; j++) {
            cin >> a >> b;
            map[a][b] = 1;
        }
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(map[i][j] && !check[i][j]) {
                    findIsland(i, j);
                }
            }
        }
        cout << count << '\n';
        count = 0;
    }
    return 0;
}