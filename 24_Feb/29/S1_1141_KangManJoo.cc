#include <bits/stdc++.h>

using namespace std;

typedef pair<string, int> psi;

psi strs[51];
string str;

bool cmp(psi a, psi b) { return a.second > b.second; }
string results[51];
int cnt;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        strs[i].first = str;
        strs[i].second = str.length();
    }

    sort(strs, strs + n, cmp);

    for (auto s: strs){
        int exist = 0;
        string next = s.first;
        for (int i = 0; i < cnt; i++) {
            int flag = 1;
            for (int c = 0; c < next.length(); c++) {
                if(next[c]!=results[i][c]){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                exist = 1;
                break;
            }
        }
        if(!exist){
            results[cnt] = s.first;
            cnt++;
        }
    }
    cout << cnt;
}