// SPFA
// basic on Bellman-Ford
// by. MiohitoKiri5474
#include<bits/stdc++.h>

using namespace std;

#define maxN 100005
#define pb push_back
typedef pair < int, int > pii;

vector < pii > edges[maxN];
int dis[maxN];
bool inQueue[maxN]; // 紀錄是否已經在queue中

inline void SPFA ( int start ){
	memset ( dis, 0x3f3f3f, sizeof dis );
	queue < int > q;
	q.push ( start );
	dis[start] = 0;
	inQueue[start] = true;
	while ( !q.empty() ){
		int now = q.front();
		q.pop();
		inQueue[now] = false; // 紀錄已經取出
		// random_shuffle ( edges[now].begin(), edges[now].end() );
		for ( auto [to, w]: edges[now] ){ // 跑過所有可以被now連結到的點
			if ( dis[to] > dis[now] + w ){
				dis[to] = dis[now] + w;
				if ( !inQueue[to] ){
					// 如果點沒有在queue中，再加入queue，並記錄已經在queue中
					inQueue[to] = true;
					q.push ( to );
				}
			}
		}
	}
}
