// 1. Dijkstra: Returns path and total distance
json shortestPathDijkstra(const Graph& graph, int src, int dest) {
    int vertices = graph.n;
    vector<double> distance(vertices, numeric_limits<double>::infinity());
    vector<int> parent(vertices, -1);

    priority_queue<pair<double, int>,
                   vector<pair<double, int>>,
                   greater<pair<double, int>>> minHeap;

    distance[src] = 0.0;
    minHeap.push({0.0, src});

    while (!minHeap.empty()) {
        auto [currDist, node] = minHeap.top();
        minHeap.pop();

        if (currDist > distance[node]) continue;

        for (const auto &edge : graph.adj[node]) {
            double nextDist = distance[node] + edge.weight;

            if (nextDist < distance[edge.to]) {
                distance[edge.to] = nextDist;
                parent[edge.to] = node;
                minHeap.push({nextDist, edge.to});
            }
        }
    }

    json ans;

    if (!isfinite(distance[dest])) {
        ans["found"] = false;
        return ans;
    }

    ans["found"] = true;
    ans["distance"] = distance[dest];

    vector<int> path;
    for (int v = dest; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());
    ans["path"] = path;

    return ans;
}

// 2. Dinic: Helper BFS/DFS needed
bool bfs(Graph& g, int s, int t, vector<int>& level) {
    fill(level.begin(), level.end(), -1);

    queue<int> q;
    level[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (const auto &e : g.adj[u]) {
            if (level[e.to] == -1 && (e.cap - e.flow) > 0) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }

    return level[t] != -1;
}

long long dfs(Graph& g, int u, int t, long long pushed,
              vector<int>& level, vector<int>& ptr) {

    if (u == t || pushed == 0)
        return pushed;

    for (int &i = ptr[u]; i < (int)g.adj[u].size(); i++) {

        auto &e = g.adj[u][i];

        if (level[e.to] != level[u] + 1)
            continue;

        if ((e.cap - e.flow) == 0)
            continue;

        long long flowSent = dfs(g, e.to, t,
                                 min(pushed, e.cap - e.flow),
                                 level, ptr);

        if (flowSent == 0)
            continue;

        e.flow += flowSent;
        g.adj[e.to][e.rev].flow -= flowSent;

        return flowSent;
    }

    return 0;
}

json runDinic(Graph& g, int source, int target) {

    long long maxFlow = 0;
    vector<int> level(g.n);

    while (bfs(g, source, target, level)) {

        vector<int> ptr(g.n, 0);

        while (true) {
            long long pushed = dfs(g, source, target,
                                   (long long)1e18,
                                   level, ptr);

            if (pushed == 0)
                break;

            maxFlow += pushed;
        }
    }

    json result;
    result["found"] = (maxFlow != 0);
    result["max_flow"] = maxFlow;

    return result;
}

// 3. Min-Cut: Perform a reachable BFS from source in the residual graph
json runMinCut(Graph& g, int source, int target) {

    runDinic(g, source, target);

    vector<bool> reachable(g.n, false);
    queue<int> q;

    reachable[source] = true;
    q.push(source);

    while (!q.empty()) {

        int u = q.front();
        q.pop();

        for (const auto &e : g.adj[u]) {

            if (!reachable[e.to] && (e.cap - e.flow) > 0) {
                reachable[e.to] = true;
                q.push(e.to);
            }
        }
    }

    json cutEdges = json::array();

    for (int u = 0; u < g.n; u++) {

        if (!reachable[u])
            continue;

        for (const auto &e : g.adj[u]) {

            if (e.cap > 0 && !reachable[e.to]) {
                cutEdges.push_back({
                    {"from", u},
                    {"to", e.to}
                });
            }
        }
    }

    json result;
    result["found"] = true;
    result["cut_edges"] = cutEdges;

    return result;
}
