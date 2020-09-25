// BOJ1480_정사각형
#include <iostream>
using namespace std;
int T, Vx[4], Vy[4];
long long sd[4];
int isNaver[3];
long long distance(int x1, int x2) {
    return (Vx[x1]-Vx[x2])*(Vx[x1]-Vx[x2])+(Vy[x1]-Vy[x2])*(Vy[x1]-Vy[x2]);
}
int main() {
    cin >> T;
    for(int i=0; i<T; i++) {
        for(int j=0; j<4; j++) {
            cin >> Vx[j] >> Vy[j];
            if(j!=0) {
                sd[j] = distance(0, j);
            }
        }
        if(sd[1]==sd[2] && sd[1]==sd[3] && sd[2]==sd[3])         {cout << 0;}
        else if(sd[1]!=sd[2] && sd[1]!=sd[3] && sd[2]!=sd[3])    {cout << 0;}
        else {
            if(sd[1]==sd[2])        {isNaver[0]=3; isNaver[1]=1; isNaver[2]=2;}
            else if(sd[1]==sd[3])   {isNaver[0]=2; isNaver[1]=1; isNaver[2]=3;}
            else                    {isNaver[0]=1; isNaver[1]=2; isNaver[2]=3;}
            if(distance(isNaver[0], isNaver[1]) != distance(isNaver[0], isNaver[2])) cout << 0;
            else if(distance(isNaver[0], isNaver[1]) != sd[isNaver[1]]) return 0;
            else if(distance(isNaver[0], isNaver[2]) != sd[isNaver[2]]) return 0;
            else cout << 1;
        }
        cout << "\n";
    }
}