#include <bits/stdc++.h>

using namespace std;

int main(){
    double a, b;

    cin >> a >> b;

    double da, db;
    double cntA = 1;
    double cntB = 1;

    da = cntA / a;
    db = cntB / b;

    while (true)
    {
        if(da<db){
            cout << 1;
            cntA++;
        }
        else if(da>db){
            cout << 2;
            cntB++;
        }
        else{
            cout << 3;
            cntA++;
            cntB++;
            if (da == 1 && db == 1)
            {
                break;
            }
        }
        da = cntA / a;
        db = cntB / b;

    }
}