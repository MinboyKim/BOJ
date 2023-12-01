#include <bits/stdc++.h>

using namespace std;

int arr[1333][10];
int invalid[10];
int m[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};


int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<10; j++)
            cin>>arr[i][j];
    }


    for (int i = 0; i < n; i++) {
        int cnt=0;
        for (int j = 0; j < 10; j++){
            if(arr[i][j]) invalid[j]=1;
            else invalid[j]=0;
        }

        string s1,s2;
        for(int month=1; month<=12; month++){
            for(int day=1; day<=m[month]; day++){
                s1 = to_string(month);
                s2= to_string(day);
                s1=s1+s2;
                for(auto s: s1){
                    if(invalid[s-48]){
                        cnt--;
                        break;
                    }
                }
                cnt++;
            }
        }
        cout<<cnt<<'\n';
        
    }

    

}