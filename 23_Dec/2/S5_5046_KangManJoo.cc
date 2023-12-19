#include <bits/stdc++.h>

using namespace std;
int MAX=INT_MAX;

int main() {
    int valid[20][1001];
    int pay[20];

    int n, credit, hotel, w;

    cin >> n >> credit >> hotel >> w;

    int p, a;
    for (int i = 0; i < hotel; i++) {
        cin >> p;
        pay[i] = p;
        int can=0;
        for (int j = 0; j < w; j++) {
            cin >> a;
            valid[i][j] = a;
            if(a>=n) can=1;
        }
        if(!can) continue;
        if(p*n<MAX) MAX=p*n;
    }
    if(MAX>credit) cout<<"stay home";
    else cout<<MAX;

    
}