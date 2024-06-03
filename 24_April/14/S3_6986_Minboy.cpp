#include <algorithm>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int N, K;
double Arr[100'100];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> Arr[i];
    }

    sort(Arr, Arr + N);

    double sum = 0;
    for (int i = K; i < N - K; i++) {
        sum += Arr[i];
    }

    double ans1 = sum / (N - K - K);
    double ans2 = (sum + (Arr[K] * K) + (Arr[N - K - 1] * K)) / N;

    cout << fixed << setprecision(2) << round(ans1 * 100.0) / 100.0 << "\n";
    cout << fixed << setprecision(2) << round(ans2 * 100.0) / 100.0 << "\n";

    return 0;
}