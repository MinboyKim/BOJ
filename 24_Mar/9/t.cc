#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9; // 무한대 값

// 그래프의 간선 정보를 저장하는 구조체
struct Edge {
    int to;   // 도착 도시 번호
    int cost; // 버스 비용
};

int main() {
    int N, M;
    cin >> N >> M;

    // 그래프를 인접 리스트로 표현
    vector<vector<Edge>> graph(N + 1);

    for (int i = 0; i < M; ++i) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
    }

    int start, end;
    cin >> start >> end;

    // 최단 거리를 저장하는 배열
    vector<int> dist(N + 1, INF);
    dist[start] = 0;

    // 우선순위 큐를 사용한 다익스트라 알고리즘
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cur_dist = pq.top().first;
        pq.pop();

        if (dist[cur] < cur_dist)
            continue;

        for (const Edge &e : graph[cur]) {
            int next = e.to;
            int next_dist = cur_dist + e.cost;

            if (next_dist < dist[next]) {
                dist[next] = next_dist;
                pq.push({next_dist, next});
            }
        }
    }

    cout << dist[end]
         << endl; // 출발 도시에서 도착 도시까지 가는데 드는 최소 비용 출력

    return 0;
}
