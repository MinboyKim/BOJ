#include <bits/stdc++.h>

using namespace std;

int main(){
    double d,h,w;
    cin>>d>>h>>w;
    double tmp=sqrt(pow(w,2)+pow(h,2));
    cout<<int((d/tmp) *h)<<" "<<int((d/tmp)*w);
}