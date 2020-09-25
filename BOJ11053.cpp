#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    vector<int> v;
    v.push_back(A[0]);
    for(int i=0; i<N; i++) {
        if(v.back() < A[i]) v.push_back(A[i]);
        else if(v.back() == A[i]) continue;
        else {
            for(int j=0; j<v.size(); j++) {
                if(v[j]>=A[i]) {
                    v[j] = A[i];
                    break;
                }
            }
        }
    }
    cout << v.size();
    return 0;
}