// Dijkstra
// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
typedef pair < int, int > pii;

const int INF = 0x3f3f3f3f;
const int maxN = 10005;

vector < pii > edges[maxN];
int dis[maxN];

inline void dijkstra ( int start ) {
	memset ( dis, INF, sizeof dis );
	priority_queue < pii, vector < pii >, greater < pii > > pq; // 用自訂用vector實作、以及更改排序順序
	pq.push ( pii ( 0, start ) );
	dis[start] = 0;

	while ( !pq.empty() ) {
        auto [d, node] = pq.top(); // 取距離最短並在pq中的點
        // int d = pq.top().first, node = pq.top().second;
		pq.pop();

		if ( dis[node] < d ) // 如果目前的路徑長比丟入pq時的路徑長還要短，直接忽略不處理
			continue;

		for ( auto [to, w]: edges[node] ) // 跑過所有可以被node連結到的點
			if ( dis[to] > d + w ) // 如果有更新，丟入當前路徑長以及點編號進入pq中
				pq.push ( pii ( dis[to] = d + w, to ) );
	}
}
