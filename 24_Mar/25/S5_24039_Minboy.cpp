#include <iostream>
#include <vector>

using namespace std;

int N;
bool Arr[222];
vector<int> prime;

void make_prime() {
    for (int i = 2; i <= 200; i++) {
        if (!Arr[i]) {
            for (int j = 2 * i; j <= 200; j += i) {
                Arr[j] = true;
            }
        }
    }
    for (int i = 2; i <= 200; i++)
        if (!Arr[i]) prime.push_back(i);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    make_prime();

    for (int i = 0; i < prime.size(); i++) {
        if (prime[i] * prime[i + 1] > N) {
            cout << prime[i] * prime[i + 1] << "\n";
            return 0;
        }
    }

    return 0;
}