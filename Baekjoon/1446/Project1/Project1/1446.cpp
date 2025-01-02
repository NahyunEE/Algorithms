#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

struct shortcut {
    int start, end, length;
};


int main() {
     
    vector<shortcut> shortcuts;
    
    int N = 0;
    int D = 0;
    cin >> N >> D;


    vector<vector<pair<int, int>>> graph(D + 1);

    for (int i = 0; i < N; ++i) {

        int temp_x = 0;
        int temp_y = 0;
        int temp_dist = 0;

        cin >> temp_x >> temp_y >> temp_dist;

        if (temp_y <= D) {
            shortcuts.push_back({ temp_x, temp_y, temp_dist });
        }
    }


    for (int i = 0; i < D; ++i) {
        graph[i].push_back({ i + 1, 1 });
    }


    for (const auto& shortcut : shortcuts) {
        if (shortcut.start < shortcut.end && shortcut.end <= D) {
            graph[shortcut.start].push_back({ shortcut.end, shortcut.length });
        }
    }


    vector<int> distances(D + 1, INF);


    distances[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, 0 });

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (current_distance > distances[current_node]) continue;

        for (const auto& neighbor : graph[current_node]) {
            int next_node = neighbor.first;
            int weight = neighbor.second;
            int new_distance = current_distance + weight;

            if (new_distance < distances[next_node]) {
                distances[next_node] = new_distance;
                pq.push({ new_distance, next_node });
            }
        }
    }


    int result = distances[D];
    cout << result;

    return 0;
}
