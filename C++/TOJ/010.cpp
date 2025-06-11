// by. MiohitoKiri5474
#include <bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

typedef long long LL;
#define pb push_back
#define INF 0x3f3f3f3f
#define NEG_INF 0x8f8f8f8f
#define maxN 200010

vector<int> edges[maxN];
int where[maxN], value[maxN], TLink[maxN], pa[maxN], D[maxN], cnt,
		seg[maxN << 1], siz[maxN], maxSon[maxN], N;

inline void init(void) {
	for (auto &i : edges)
		i.clear();
	memset(where, -1, sizeof where);
	memset(value, NEG_INF, sizeof value);
	memset(D, 0, sizeof D);
	memset(maxSon, -1, sizeof maxSon);
	cnt = 0;
}

void findMaxSon(int u) {
	siz[u] = 1;
	maxSon[u] = -1;
	for (auto i : edges[u]) {
		if (i == pa[u])
			continue;
		pa[i] = u;
		D[i] = D[u] + 1;
		findMaxSon(i);
		if (maxSon[u] == -1 || siz[i] > siz[maxSon[u]])
			maxSon[u] = i;
		siz[u] += siz[i];
	}
}

void dfs(int n, int p) {
	TLink[n] = p;
	where[n] = ++cnt;
	if (maxSon[n] == -1)
		return;
	dfs(maxSon[n], p);
	for (auto i : edges[n]) {
		if (i == maxSon[n] || i == pa[n])
			continue;
		dfs(i, i);
	}
}

inline void update(int pos, int value) {
	for (seg[pos += N] = value, pos >>= 1; pos > 1; pos >>= 1)
		seg[pos] = max(seg[pos << 1], seg[pos << 1 | 1]);
}

inline int query(int l, int r) {
	int res = NEG_INF;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1)
			res = max(res, seg[l++]);
		if (r & 1)
			res = max(res, seg[--r]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, n, u, v, ma;
	string type;
	cin >> t;
	while (t--) {
		cin >> n;
		N = (n << 1) - 1;
		init();
		for (int i = 1; i < n; i++) {
			cin >> u >> v >> value[n + i];
			edges[u].pb(n + i);
			edges[n + i].pb(u);
			edges[n + i].pb(v);
			edges[v].pb(n + i);
		}

		pa[1] = 1;
		findMaxSon(1);
		dfs(1, 1);

		for (int i = 1; i <= N; i++)
			seg[where[i] + N - 1] = value[i];
		for (int i = --N; i > 0; i--)
			seg[i] = max(seg[i << 1], seg[i << 1 | 1]);

		while (cin >> type) {
			if (type == "DONE")
				break;
			cin >> u >> v;
			if (type == "QUERY") {
				ma = -1;

				while (TLink[v] != TLink[u]) {
                    if(D[TLink[v]] < D[TLink[u]])
                        swap(u, v);
                    ma = max(ma, query(where[TLink[v]], where[v]));
                    v = pa[TLink[v]];
				}

				if (D[u] > D[v])
					swap(u, v);
				cout << max(ma, query(where[u], where[v])) << '\n';
			} else
				update(where[n + u], v);
		}
	}
}
