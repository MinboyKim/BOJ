#include <iostream>

using namespace std;

int Arr[111][111], Copy[111][111], N, Q, a;

void func1() {
    cin >> a;
    int temp = Arr[a][N];
    for (int i = N; i >= 2; i--)
        Arr[a][i] = Arr[a][i - 1];
    Arr[a][1] = temp;
}

void func2() {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            Copy[j][N - i + 1] = Arr[i][j];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            Arr[i][j] = Copy[i][j];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> Arr[i][j];

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> a;
        if (a == 1)
            func1();
        else if (a == 2)
            func2();
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cout << Arr[i][j] << " ";
        cout << "\n";
    }

    return 0;
}