#include <bits/stdc++.h>
using namespace std;

// Notes:
// BFS = queue (∀ 1st, ∀ 2nd, ∀ 3rd, ... as in linkedin)
// BFS + heuristic = Greedy BestFirst Search
// BFS + cost = Dijkstra
// BFS + cost + heuristic = A*

// graph[u] = [{v, weight}]
vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int start) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;q.push({0,start});vector<int>ans(graph.size(), -1);ans[start]=0;
  while (!q.empty()){
    auto [cr,u]=q.top();q.pop();for(auto[v,w]:graph[u]){if(cr>ans[u])continue;if(ans[v]==-1||ans[v]>ans[u]+w){ans[v]=ans[u]+w;q.push({ans[v],v});}}
  }
  return ans;
}

int main() {
  vector<vector<pair<int, int>>> graph(5);

  vector<vector<int>> edges = {{0, 1, 3}, {1, 3, 5}};
  for (auto &edge : edges) {
    graph[edge[0]].push_back({edge[1], edge[2]});
    graph[edge[1]].push_back({edge[0], edge[2]});
  }
  dbg(dijkstra(graph, 0));
}
