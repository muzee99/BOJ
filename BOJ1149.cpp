#include <iostream>

using namespace std;

long long reg[1000100];

long long fx(int n) {
    if(n==1) return 1;
    if(n==2) return 1;
    if(n==3) return 1;
    else if(reg[n]) return reg[n];
    else return reg[n] = fx(n-3) + fx(n-2);
};

int main() {
    int T;
    cin >> T;
    int N[T];
    for(int i=0; i<T; i++) {
        
        cin >> N[i];

    }
    for(int i=0; i<T; i++) cout << fx(N[i]) << "\n";
}