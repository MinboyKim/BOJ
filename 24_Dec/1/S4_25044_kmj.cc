#include <bits/stdc++.h>

using namespace std;
vector<int> arr;
int main(){
    int a, b;
    cin >> a >> b;

    // 3600분 = 1일
    int curT = 0;

    int day = 0;
    int cnt = 0;
    int onCnt = 0;
    while (true)
    {
        if(cnt==0){
            curT += 60 * 15;
        }
        else if(cnt==1){
            curT += 60 * 3;
        }
        else{
            curT += 60*3;
        }

        if(curT>=1440){
            curT -= 1440;
            day++;
            if(day>a){
                break;
            }
        }

        if(day==a){
            onCnt++;
            arr.push_back(curT);
        }
        cnt++;
        if(cnt==3){
            cnt = 0;
            curT += b;
            curT+=60*3;
        }
    }
    cout<<onCnt<<'\n';
    for(auto curT: arr){
        if(curT/60<10){
            cout<<"0";
        }
        cout << curT / 60 << ":";
        if (curT % 60 < 10)
        {
            cout << "0";
        }
        cout << curT % 60 << '\n';
    }
}