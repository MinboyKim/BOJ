#include <bits/stdc++.h>

using namespace std;

int main() {
    double x, y, ax, ay, bx, by;
    double aMidx, aMidy, bMidx, bMidy;

    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < 4; i++) {
            cin >> x >> y;
            if (i == 0) {
                ax = x;
                ay = y;
            } else {
                if (x != ax) {
                    bx = x;
                }
                if (y != ay) {
                    by = y;
                }
            }
        }
        if (t == 0) {
            aMidx = (ax + bx) / 2;
            aMidy = (ay + by) / 2;
        } else {
            bMidx = (ax + bx) / 2;
            bMidy = (ay + by) / 2;
        }
    }
    double f = (bMidy - aMidy) / (bMidx - aMidx);
    double k = aMidy - (f * aMidx);

    double up = 1, down = 1;
    while (true) {
        double next = up / down;
        if (next == f) {
            cout << up << "/" << down << " ";
            break;
        } else if (next > f) {
            down++;
        } else if (next < f) {
            up++;
        }
    }

    up = 1, down = 1;
    while (true) {
        double next = up / down;
        if (next == k) {
            cout << up << "/" << down;
            break;
        } else if (next > k) {
            down++;
        } else if (next < k) {
            up++;
        }
    }
}