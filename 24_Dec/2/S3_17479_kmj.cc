#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
map<string, pii> menu;

int main()
{
    int a, b, c, cost;
    cin >> a >> b >> c;
    string s;
    for (int i = 0; i < a; i++)
    {
        cin >> s >> cost;
        menu[s] = {1, cost};
    }
    for (int i = 0; i < b; i++)
    {
        cin >> s >> cost;
        menu[s] = {2, cost};
    }
    for (int i = 0; i < c; i++)
    {
        cin >> s;
        menu[s] = {3, 0};
    }

    int n;
    long long normalCost = 0;
    long long specialCost = 0;
    int isService = 0;
    cin >> n;
    while(n--){
        cin >> s;
        if(menu[s].first==1){
            normalCost += menu[s].second;
        }
        else if(menu[s].first==2){
            specialCost += menu[s].second;
        }
        else{
            isService++;
        }
    }
    int isAbled = 1;

    if(normalCost<20000 && specialCost>0){
        isAbled = 0;
    }
    else if(normalCost+specialCost<50000 && isService>0){
        isAbled = 0;
    }
    else if(isService>1){
        isAbled = 0;
    }

    if(isAbled){
        cout<<"Okay";
    }
    else{
        cout<<"No";
    }
}