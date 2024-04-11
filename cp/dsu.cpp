#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union, get isConnected(a,b) in O(1) instead of O(N+E) using DFS/BFS
// With changing graphs, only union is permissible, removing edge is not supported.
template <typename T>
struct DSU {
  vector<T> sz;  // size
  vector<T> pr;  // parent

  DSU(int n) : sz(n+1, 1), pr(n+1) {
    for (int i = 1; i <= n; i++) pr[i] = i;
  }

  T parent(T a) {
    if (a == pr[a]) return a;
    return pr[a] = parent(pr[a]);
  }

  void join(T a, T b) {
    T pa = parent(a), pb = parent(b);;
    if (pa == pb) return;

    if (sz[a] < sz[b]) {
      pr[pa] = pb, sz[pb] += sz[pa];
    } else {
      pr[pb] = pa, sz[pa] += sz[pb];
    }
  }

  bool is_connected(T a, T b) {
    return parent(a) == parent(b);
  }
};

int main() {
  DSU<int> d(5);

  cout << d.is_connected(1, 5) << endl;
  d.join(2, 5);
  cout << d.is_connected(1, 5) << endl;
  d.join(1, 2);
  cout << d.is_connected(1, 5) << endl;
}
