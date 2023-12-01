#include <bits/stdc++.h>

using namespace std;

int minSize;
int maxSize;
int q, maxBurger, minCola, burger, cola, curt;

int main() {
    int n, m, t;
    cin >> n >> m >> t;

    minSize = min(n, m);
    maxSize = max(n, m);

    maxBurger = t / minSize;
    minCola = t % minSize;

    for (int i = maxBurger; i >= 0; i--) {
        curt = t - i * minSize;
        burger = i + curt / maxSize;
        cola = curt % maxSize;
        if (cola < minCola) {
            minCola = cola;
            maxBurger = burger;
        }
    }

    cout << maxBurger << " " << minCola;
}