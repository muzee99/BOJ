// BOJ2606_바이러스
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> com[105];
int search[105];
int count = 0;

int main() {
    cin >> N >> M;
    int a, b;
    for(int i=0; i<M; i++) {
        cin >> a >> b;
        com[a].push_back(b);
        com[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    search[1] = true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i=0; i<com[x].size(); i++) {
            int y = com[x][i];
            if(!search[y]) {
                search[y] = true;
                q.push(y);
                count++;
            }
        }
    }
    cout << count;
}