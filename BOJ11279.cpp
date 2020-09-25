// BOJ11279_최대 힙
#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, less<int>> q;

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        if(x) q.push(x);
        else if(q.empty()) cout << "0" << "\n";
        else {
            cout << q.top() << "\n";
            q.pop();
        }
    }

    return 0;
}