#include <bits/stdc++.h>

using namespace std;

vector<long long> atks;
int main()
{
    int t;
    cin >> t;
    long long atk,oth;
    cin >> atk;
    t--;
    while (t--)
    {
        cin >> oth;
        atks.push_back(oth);
    }
    sort(atks.begin(), atks.end());

    for(auto i: atks){
        if(atk>i){
            atk+=i;
        }
        else{
            cout << "No";
            exit(0);
        }
    }
    cout << "Yes";
}