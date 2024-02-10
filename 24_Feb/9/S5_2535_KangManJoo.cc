#include <bits/stdc++.h>

using namespace std;

int school[1010];
tuple<int, int, int> tp[1010];
tuple<int, int, int> tmp;
int main() {
    int n, a, b, score;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> score;
        tp[i] = {a, b, score};
    }
    int MaxScore = 0;
    int cnt = 0;
    int maxI;
    while (true) {
        if (cnt == 3)
            break;
        for (int i = 0; i < n; i++) {
            if (get<2>(tp[i]) > MaxScore&&school[get<0>(tp[i])]<2) {
                tmp = tp[i];
                MaxScore = get<2>(tp[i]);
                maxI = i;
            }
        }
            cnt++;
            cout << get<0>(tmp) << " " << get<1>(tmp) << '\n';
            school[get<0>(tmp)]++;
            MaxScore = 0;
            get<2>(tp[maxI]) = 0;
        
    }
}