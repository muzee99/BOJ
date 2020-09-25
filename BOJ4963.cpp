// BOJ4963_섬의 개수
#include <iostream>
#include <queue>

using namespace std;

int w,h;
int count = 0;
int check[501][501];
int map[501][501];
int step[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

int isInside(pair<int, int> locate) {
    if(locate.first>=0 && locate.first<h && locate.second>=0 && locate.second<w) return 1;
    else return 0;
}

void findIsland(int x, int y) {
    queue <pair<int, int>> q;
    q.push(pair<int, int>(x,y));
    check[x][y] = true;
    while(!q.empty()) {
        pair<int, int> land = q.front();
        q.pop();
        for(int i=0; i<8; i++) {
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
    while(1) {
        cin >> w >> h;
        if(!w) break;
        else {
            for(int i=0; i<h; i++) {
                for(int j=0; j<w; j++) {
                    check[i][j] = 0;
                    cin >> map[i][j];
                }
            }
            for(int i=0; i<h; i++) {
                for(int j=0; j<w; j++) {
                    if(map[i][j] && !check[i][j]) {
                        findIsland(i, j);
                    }
                }
            }
            cout << count << '\n';
            count = 0;
        }
    }
    return 0;
}