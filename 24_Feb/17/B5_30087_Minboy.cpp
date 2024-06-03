#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, string> m;
int N;
string s;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    m.insert({"Algorithm", "204"});
    m.insert({"DataAnalysis", "207"});
    m.insert({"ArtificialIntelligence", "302"});
    m.insert({"CyberSecurity", "B101"});
    m.insert({"Network", "303"});
    m.insert({"Startup", "501"});
    m.insert({"TestStrategy", "105"});

    cin >> N;
    while (N--) {
        cin >> s;
        cout << m[s] << "\n";
    }

    return 0;
}