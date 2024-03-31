#include <bits/stdc++.h>
using namespace std;

// Segment Tree: 2n implementation with start index 1, range = [l, r)
// Example Op below
// ref: https://codeforces.com/blog/entry/18051
// ref: https://github.com/sharmaharisam/Generic_all_purpose_segtree/blob/main/Segtree.cpp
template <typename Op> struct SGTree;
template <typename T, typename U, template <typename, typename> typename Op>
struct SGTree<Op<T, U>> {
  int n;
  vector<T> t;
  vector<U> d;

  SGTree(vector<T>& a) : n(a.size()), t(2*n), d(n, Op<T,U>::id_u) {
    // build
    copy(a.begin(), a.end(), t.begin()+n);
    for (int i = n - 1; i > 0; --i) t[i] = Op<T,U>::combine(t[i<<1], t[i<<1|1]);
  }

  T query(int l, int r) {
    T resl = Op<T,U>::id_e, resr = Op<T,U>::id_e;
    push(l += n); push((r += n)-1);  // iterative impl require push from root down to this node prior to anything
    for (; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = Op<T,U>::combine(resl, t[l++]);
      if (r&1) resr = Op<T,U>::combine(t[--r], resr);
    }
    return Op<T,U>::combine(resl, resr);
  }

  void update(int p, U upd) {
    updateAll(p, p+1, upd);
  }

  void updateAll(int l, int r, U upd) {
    if (upd == Op<T,U>::id_u) return;
    push(l += n); push((r += n)-1);  // iterative impl require push from root down to this node prior to anything

    int k = 1, tl = l, tr = r-1;
    for (; l < r; l >>= 1, r >>= 1, k <<= 1) {
      if (l&1) _apply(l++, upd, k);
      if (r&1) _apply(--r, upd, k);
    }
    pull(tl);
    pull(tr);
  }

private:
  void push(int p) {
    int h = sizeof(int)*8 - __builtin_clz(n);
    int k = 1 << (h-1);
    for (int s = h; s > 0; s--, k >>= 1) {
      int i = p >> s;
      if (d[i] == Op<T,U>::id_u) continue;

      _apply(i<<1, d[i], k);
      _apply(i<<1|1, d[i], k);

      d[i] = Op<T,U>::id_u;
    }
  }
  void pull(int p) {
    for (int k = 1; p >>= 1; k <<= 1) {
      T l = t[p<<1];
      T r = t[p<<1|1];
      if (d[p] != Op<T,U>::id_u) {
        l = Op<T,U>::apply(l, d[p], k);
        r = Op<T,U>::apply(r, d[p], k);
      }
      t[p] = Op<T,U>::combine(l, r);
    }
  }
  void _apply(int p, U upd, int k) {
    t[p] = Op<T,U>::apply(t[p], upd, k);
    if (p < n) d[p] = Op<T,U>::combineUpdate(d[p], upd);
  }
};
template <class T> void _print(SGTree<T> v) {_print(v.t);cerr<<" ";_print(v.d);}

template<typename T, typename U>
struct MinAssignOp {
  static constexpr T id_e = numeric_limits<U>::max();  // identity element | combine(v, id_e) = v
  static constexpr U id_u = numeric_limits<U>::max();  // identity update  | apply(v, id_u, ...) = v
  static constexpr T combine(T a, T b) { return min(a, b); }
  static constexpr T apply(T curr, U upd, int k) { return upd; }
  static constexpr U combineUpdate(U old_upd, U new_upd) { return new_upd; }
};

int main() {
  vector<int> a = {1, 2, 3, 4, 5, 7, 6, 8};
  SGTree<MinAssignOp<int, int>> wow(a);

  // dbg(wow);
  // dbg(wow.query(1, 3));

  // wow.update(2, -5);
  // dbg(wow);
}
