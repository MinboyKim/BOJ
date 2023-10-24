#include <bits/stdc++.h>

using namespace std;

typedef pair<int, long long> pil;
int main(){
    map<string,pil> m;
    m.insert({"black",{0,1}});
    m.insert({"brown",{1,10}});
    m.insert({"red",{2,100}});
    m.insert({"orange",{3,1000}});
    m.insert({"yellow",{4,10000}});
    m.insert({"green",{5,100000}});
    m.insert({"blue",{6,1000000}});
    m.insert({"violet",{7,10000000}});
    m.insert({"grey",{8,100000000}});
    m.insert({"white",{9,1000000000}});

    string s1,s2,s3;

    cin>>s1>>s2>>s3;

    long long ans = (m[s1].first*10 + m[s2].first)*m[s3].second;
    cout<<ans;
}