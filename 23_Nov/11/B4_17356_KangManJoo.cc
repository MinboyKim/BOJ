#include <bits/stdc++.h>

using namespace std;

int main(){
    double n,m;
    cin>>n>>m;
    double k=(m-n)/400.0;

    double bu=1.0/(1+pow(10,k));
    cout<<bu;
}