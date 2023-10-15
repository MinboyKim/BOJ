#include <bits/stdc++.h>

using namespace std;

int calcScore(double dist) {
    if (dist > 225)
        return 0;
    else if (dist > 144)
        return 20;
    else if (dist > 81)
        return 40;
    else if (dist > 36)
        return 60;
    else if (dist > 9)
        return 80;
    else
        return 100;
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    double t, x, y;
    int nScore, mScore;
    cin>>t;
    while (t--) {
        nScore = 0;
        mScore = 0;
        for (int i = 0; i < 6; i++) {
            cin >> x >> y;
            double dist = x*x + y*y;
            if (i < 3) {
                nScore += calcScore(dist);
            } else {
                mScore += calcScore(dist);
            }
        }
        if (nScore > mScore) {
            cout << "SCORE: " << nScore << " to " << mScore
                 << ", PLAYER 1 WINS." << '\n';
        } else if (nScore < mScore) {
            cout << "SCORE: " << nScore << " to " << mScore
                 << ", PLAYER 2 WINS." << '\n';
        } else {
            cout << "SCORE: " << nScore << " to " << mScore
                 << ", TIE." << '\n';
        }
    }
}
