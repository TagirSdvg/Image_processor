#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int v, vector<int> &vis, vector<vector<int>> &graph, vector<int> &tout) {
    vis[v] = 1;
    for (auto to : graph[v]) {
        if (vis[to] == 0) {
            dfs(to, vis, graph, tout);
        }
    }
    tout.push_back(v);
}

void floyd(vector<vector<int>> &matrix, const int n) {
    for (int v = 1; v <= n; ++v) {
        for (int vir = 1; vir <= v; ++vir) {
            for (int from = 1; from <= v; ++from) {
                for (int to = 1; to <= v; ++to) {
                    if (matrix[from][vir] + matrix[vir][to] < matrix[from][to]) {
                        matrix[from][to] = matrix[from][vir] + matrix[vir][to];
                    }
                }
            }
        }
    }
}

void bfs(int v, vector<int> &vis, vector<vector<int>> &graph, queue<int> &pq) {
//смежность
//    int n;
//    cin >> n;
//    vector<vector<int>> graph(n + 1);
//    vector<int> vis(n + 1, -1);
//    queue<int> pq;
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= n; ++j) {
//            int a;
//            cin >> a;
//            if (a == 1) {
//                graph[i].push_back(j);
//            }
//        }
//    }
//    int a, b;
//    cin >> a >> b;
    pq.push(v);
    while (!pq.empty()) {
        int cur = pq.front();
        pq.pop();
        for (auto to : graph[cur]) {
            if (vis[to] == -1) {
                vis[to] = vis[cur] + 1;
                pq.push(to);
            }
        }
    }
}

void deik(int v, vector<vector<pair<int, int>>> &graph, vector<int> &fin, vector<int> &way, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> &pq, vector<int> &parents) {
//ввод
//    int64_t n, k;
//    cin >> n >> k;
//    vector<vector<pair<int64_t, int64_t>>> graph(n + 1);
//    priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, greater<>> pq;
//    vector<int64_t> way(n + 1, 10000000000000000000000);
//    vector<int64_t> fin(n + 1);
//    vector<int64_t> parents(n + 1);
//
//    for (int i = 1; i <= k; i++) {
//        int64_t a, b, c;
//        cin >> a >> b >> c;
//        graph[a].push_back({b, c});
//        graph[b].push_back({a, c});
//    }
//    int64_t s, f;
//    cin >> s >> f;
    way[v] = 0;
    pq.push({0, v});
    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        if (fin[cur] == 0) {
            for (auto to : graph[cur]) {
                if (fin[to.first] == 0) {
                    if (way[to.first] > way[cur] + to.second) {
                        way[to.first] = way[cur] + to.second;
                        parents[to.first] = cur;
                        pq.push({way[to.first], to.first});
                    }
                }
            }
            fin[cur] = 1;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> vis(n + 1, -1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
}
