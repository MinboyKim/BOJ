#include <iostream>
#include <string>

using namespace std;

int N, lArm, rArm, lLeg, rLeg, spine;
char Arr[1111][1111];
int rHeart, cHeart;
int rSpine, cSpine;

void find() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (Arr[i][j] == '*') {
                rHeart = i + 1;
                cHeart = j;
                return;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) {
            Arr[i][j] = s[j];
        }
    }

    find();

    for (int i = cHeart - 1; i >= 0; i--) {
        if (Arr[rHeart][i] == '*')
            lArm++;
        else
            break;
    }

    for (int i = cHeart + 1; i < N; i++) {
        if (Arr[rHeart][i] == '*')
            rArm++;
        else
            break;
    }

    for (int i = rHeart + 1; i < N; i++) {
        if (Arr[i][cHeart] == '*')
            spine++;
        else {
            rSpine = i - 1;
            cSpine = cHeart;
            break;
        }
    }

    for (int i = rSpine + 1; i < N; i++) {
        if (Arr[i][cSpine - 1] == '*')
            lLeg++;
        else
            break;
    }

    for (int i = rSpine + 1; i < N; i++) {
        if (Arr[i][cSpine + 1] == '*')
            rLeg++;
        else
            break;
    }

    cout << rHeart + 1 << " " << cHeart + 1 << "\n";

    cout << lArm << " " << rArm << " " << spine << " " << lLeg << " " << rLeg << "\n ";

    return 0;
}