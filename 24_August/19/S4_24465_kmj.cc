#include <bits/stdc++.h>

using namespace std;


int jari(int a, int b){
    if((a==1 && b>=20) || (a==2 && b<=18) ){
        return 1;
    }
    else if((a==2 && b>=19) || (a==3 && b<=20)){
        return 2;
    }
    else if((a==3 && b>=21) || (a==4 && b<=19)){
        return 3;
    }
    else if((a==4 && b>=20) || (a==5 && b<=20)){
        return 4;
    }
    else if((a==5 && b>=21) || (a==6 && b<=21)){
        return 5;
    }
    else if((a==6 && b>=22) || (a==7 && b<=22)){
        return 6;
    }
    else if((a==7 && b>=23) || (a==8 && b<=22)){
        return 7;
    }
    else if((a==8 && b>=23) || (a==9 && b<=22)){
        return 8;
    }
    else if((a==9 && b>=23) || (a==10 && b<=22)){
        return 9;
    }
    else if((a==10 && b>=23) || (a==11 && b<=22)){
        return 10;
    }
    else if((a==11 && b>=23) || (a==12 && b<=21)){
        return 11;
    }
    else if((a==12 && b>=22) || (a==1 && b<=19)){
        return 12;
    }
}

int check[13];

vector<pair<int, int>> v;

int main(){
    int a, b;
    for (int i = 0; i < 7; i++)
    {
        cin >> a >> b;
        check[jari(a, b)]++;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if(check[jari(a,b)]==0){
            v.push_back({a, b});
        }
    }

    sort(v.begin(), v.end());
    for(auto i:v){
        cout<<i.first<<" "<<i.second<<"\n";
    }

    if(v.size()==0){
        cout << "ALL FAILED";
    }
}