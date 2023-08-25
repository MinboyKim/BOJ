#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main(){
    int n,m;
    cin>>n>>m;

    while(m<=100){
        if(m%2==0){
            if((n%m)==(m/2) && (n/m-m/2+1)>=0){
                int l=n/m;
                int r=n/m+1;
                for(int i=0; i<m/2; i++){
                    v.push_back(l);
                    v.push_back(r);
                    l--;
                    r++;               
                } 
                break;
            }
        }
        else{
            if(n%m==0 && (n/m-(m/2))>=0){
                v.push_back(n/m);
                int l = (n / m)-1;
                int r = (n / m) + 1;
                for (int i = 0; i < m / 2; i++) {
                    v.push_back(l);
                    v.push_back(r);
                    l--;
                    r++;
                }
                break;
            }

        }
        m++;
    }
    sort(v.begin(),v.end());
    if(v.empty()) cout<<-1;
    else{
        for(auto i:v){
            cout<< i<<" ";
        }
    }
}