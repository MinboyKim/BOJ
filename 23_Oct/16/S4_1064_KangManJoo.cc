#include <bits/stdc++.h>

using namespace std;

double MAX;
double MIN = INT32_MAX;
double ax, ay, bx, by, cx, cy;
double ab, ac, bc;
void solve() {
    if (ab * 2 + bc * 2 > MAX)
        MAX = ab * 2 + bc * 2;
    if (ab * 2 + bc * 2 < MIN)
        MIN = ab * 2 + bc * 2;
    if (ab * 2 + ac * 2 > MAX)
        MAX = ab * 2 + ac * 2;
    if (ab * 2 + ac * 2 < MIN)
        MIN = ab * 2 + ac * 2;
    if (ac * 2 + bc * 2 > MAX)
        MAX = ac * 2 + bc * 2;
    if (ac * 2 + bc * 2 < MIN)
        MIN = ac * 2 + bc * 2;

    cout << fixed;
    cout.precision(15);
    cout << MAX - MIN;
}

int main() {

    cin >> ax >> ay >> bx >> by >> cx >> cy;

    ab = sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
    ac = sqrt(pow(ax - cx, 2) + pow(ay - cy, 2));
    bc = sqrt(pow(bx - cx, 2) + pow(by - cy, 2));

    if (ay == by && by == cy) {
        cout << -1;
    }
    else if (ay == by || by == cy || ay == cy) {
        solve();
    }
    else if (((ax - bx) / (ay - by)) == ((bx - cx) / (by - cy))) {
        cout << -1;
    }
    else {
        solve();
    }
}