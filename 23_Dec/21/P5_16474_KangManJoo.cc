#include <bits/stdc++.h>

using namespace std;

int Left[2002];
int Right[2002];
int lis[202002];
vector<int> arr[2002];
int n,m,k,loc,leftBot,rightBot,leftReal,rightReal;
int len;

int binarySearch(int x) {
    int left = 1;
    int right = len;
    int mid;

    while (left < right) {
        mid = (left + right) / 2;
        if (lis[mid] < x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return right;
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>loc;
        Left[loc] = i;
    }
    for(int i=1; i<=m; i++){
        cin>>loc;
        Right[loc] = i;
    }
    cin>>k;
    for(int i=0; i<k; i++){
        cin>>leftBot>>rightBot;
        leftReal=Left[leftBot];
        rightReal=Right[rightBot];
        arr[leftReal].push_back(rightReal);
    }

    for(int i=1; i<=n; i++){
        sort(arr[i].begin(),arr[i].end());
        for(auto dest: arr[i]){
            if(lis[len]<dest){
                len++;
                lis[len] = dest;
                break;
            }
            else if(lis[len]==dest){
                continue;
            }
            else{
                int idx = binarySearch(dest);
                lis[idx] = dest;
            }
        }
    }
    cout<<k-len;

}