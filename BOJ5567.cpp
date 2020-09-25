// BOJ5567_결혼식
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, a, b;
vector<int> rel[505];
vector<int> invite;
int check[505];

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        if(a==1) invite.push_back(b);
        else if(b==1) invite.push_back(a);
        rel[a].push_back(b);
        rel[b].push_back(a);
    }
    check[1] = true;
    queue<int> q;
    for(int i=0; i<invite.size(); i++) {
        q.push(invite[i]);
        check[invite[i]] = true;
    }
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int j=0; j<rel[x].size(); j++) {
            if(!check[rel[x][j]]) {
                invite.push_back(rel[x][j]);
                check[rel[x][j]] = true;
            }
        }
    }
    cout << invite.size();
    return 0;
}