// Prim
// by. MiohitoKiri5474
#include <bits/stdc++.h>
#include <queue>

using namespace std;

#define pb push_back
#define F first
#define S second
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
const int maxN = 100005;

int dis[maxN], sz[maxN];

inline void init(void) {
	for (int i = 0; i < maxN; i++)
		dis[i] = i, sz[i] = 1;
}

int find(int n) { return dis[n] == n ? n : dis[n] = find(dis[n]); }

inline void Union(int a, int b) {
	a = find(a), b = find(b);
	dis[a] = b;
	sz[b] += sz[a];
}

inline bool same(int a, int b) { return find(a) == find(b); }

vector<pii> edges[maxN], mst[maxN];
bool pushed[maxN];

struct node {
	int u, v, w;
	inline bool operator<(const node &b) const { return w < b.w; }
	inline bool operator>(const node &b) const { return w > b.w; }
};

inline void Pirm(int n) {
	priority_queue<node, vector<node>, greater<node>> pq;
	for (auto [i, dist] : edges[0])
		pq.push(node{0, i, dist});
	pushed[0] = true;
	init();
	while (sz[find(0)] != n) {
		auto [u, v, w] = pq.top();
		pq.pop();
		while (!pq.empty() && same(u, v)) {
			u = pq.top().u, v = pq.top().v, w = pq.top().w;
			pq.pop();
		}

		mst[u].pb(pii(v, w));
		mst[v].pb(pii(u, w));
		Union(u, v);

		if (!pushed[u]) {
			for (auto [i, dist] : edges[u])
				pq.push(node{u, i, dist});
			pushed[u] = true;
		}
		if (!pushed[v]) {
			for (auto [i, dist] : edges[v])
				pq.push(node{v, i, dist});
			pushed[v] = true;
		}
	}
}
