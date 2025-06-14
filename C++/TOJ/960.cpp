// by. MiohitoKiri5474
#include <bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

// type and pair definition
using LL = long long;
using pii = pair < LL, LL >;
using sstr = stringstream;
#define F first
#define S second
#define mp make_pair

// general definition
#define pb push_back
#define ep emplace_back
#define GL(n) getline ( cin, n )
#define gura ios::sync_with_stdio(false);cin.tie(0)

// define heap
template < class T > using MaxHeap = priority_queue < T, vector < T >, less < T > >;
template < class T > using MinHeap = priority_queue < T, vector < T >, greater < T > >;

// number definition
#define INF 0x3f3f3f3f

// some defiine for programing contest
// #define int LL
inline void print_ans ( bool flag ) {
    cout << ( flag ? "YES\n" : "NO\n" );
}
const int maxN = 2000005;

struct node {
    int mi, ma, tag;
    bool updated;
} seg[maxN << 2];

void build (int l, int r, int n) {
    if (l == r) {
        cin >> seg[n].mi;
        seg[n].ma = seg[n].mi;
    }
    else {
        int mid = (l + r) >> 1, ls = n << 1, rs = ls | 1;
        build(l, mid, ls);
        build(mid + 1, r, rs);
        seg[n].mi = min(seg[ls].mi, seg[rs].mi);
        seg[n].ma = max(seg[ls].ma, seg[rs].ma);
    }
}

void update (int l, int r, int nowL, int nowR, int value, int n) {
    if (l <= nowL && nowR <= r)
        seg[n].ma = seg[n].mi = seg[n].tag = value, seg[n].updated = true;
    else {
        int mid = (nowL + nowR) >> 1, ls = n << 1, rs = ls | 1;
        if (seg[n].updated) {
            seg[ls] = seg[rs] = seg[n];
            seg[n].updated = 0;
        }
        if (r <= mid)
            update(l, r, nowL, mid, value, ls);
        else if (mid < l)
            update(l, r, mid + 1, nowR, value, rs);
        else {
            update(l, r, nowL, mid, value, ls);
            update(l, r, mid + 1, nowR, value, rs);
        }
        seg[n].mi = min(seg[ls].mi, seg[rs].mi);
        seg[n].ma = max(seg[ls].ma, seg[rs].ma);
    }
}

pii query (int l, int r, int nowL, int nowR, int n) {
    if (l <= nowL && nowR <= r)
        return {seg[n].mi, seg[n].ma};
    else {
        int mid = (nowL + nowR) >> 1, ls = n << 1, rs = ls | 1;
        if (seg[n].updated) {
            seg[ls] = seg[rs] = seg[n];
            seg[n].updated = 0;
        }
        if (r <= mid)
            return query(l, r, nowL, mid, ls);
        if (mid < l)
            return query(l, r, mid + 1, nowR, rs);
        pii lRes = query(l, r, nowL, mid, ls),
            rRes = query(l, r, mid + 1, nowR, rs);
        return {min(lRes.F, rRes.F), max(lRes.S, rRes.S)};
    }
}

inline void print_ans (pii res) {
    cout << (res.F == res.S ? "YES\n" : "NO\n");
}

signed main() {
    gura;

    int n, m, t, l, r, v;
    cin >> n >> m;
    build(1, n, 1);
    while (m--) {
        cin >> t >> l >> r;
        if (t == 1)
            print_ans(query(l, r, 1, n, 1));
        else {
            cin >> v;
            update(l, r, 1, n, v, 1);
        }
    }
}
