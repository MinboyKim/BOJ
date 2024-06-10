#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string Name;
    int Korean;
    int English;
    int Math;
};

Student Arr[101'010];
int N;

bool compare(Student A, Student B) {
    if (A.Korean == B.Korean && A.English == B.English && A.Math == B.Math) return A.Name < B.Name;
    if (A.Korean == B.Korean && A.English == B.English) return A.Math > B.Math;
    if (A.Korean == B.Korean) return A.English < B.English;
    return A.Korean > B.Korean;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> Arr[i].Name >> Arr[i].Korean >> Arr[i].English >> Arr[i].Math;
    }

    sort(Arr, Arr + N, compare);

    for (int i = 0; i < N; i++) {
        cout << Arr[i].Name << "\n";
    }

    return 0;
}