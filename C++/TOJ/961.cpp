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
#define int LL
inline void print_ans ( bool flag ) {
    cout << ( flag ? "Yes" : "No" ) << endl;
}
const int maxN = 2000005;
const int mod = 1000000007;

struct node {
    int sum, sum2, tag, sz;

    inline int calc_sum() {
        return (sum2 + (tag * ((tag * sz + 2 * sum) % mod)) % mod) % mod;
    }
} seg[maxN << 2];

void build (int l, int r, int n) {
    if (l == r) {
        cin >> seg[n].sum;
        seg[n].sz = 1;
        seg[n].sum2 = (seg[n].sum * seg[n].sum) % mod;
    }
    else {
        int mid = (l + r) >> 1, ls = n << 1, rs = n << 1 | 1;
        build(l, mid, ls);
        build(mid + 1, r, rs);
        seg[n].sum = (seg[ls].sum + seg[rs].sum) % mod;
        seg[n].sum2 = (seg[ls].sum2 + seg[rs].sum2) % mod;
        seg[n].sz = seg[ls].sz + seg[rs].sz;
    }
}

void modify (int l, int r, int nowL, int nowR, int value, int n) {
    if (l <= nowL && nowR <= r)
        seg[n].tag += value;
    else {
        int mid = (nowL + nowR) >> 1, ls = n << 1, rs = n << 1 | 1;
        if (seg[n].tag) {
            seg[ls].tag += seg[n].tag;
            seg[rs].tag += seg[n].tag;
            seg[n].tag = 0;
        }
        if (r <= mid)
            modify(l, r, nowL, mid, value, ls);
        else if (mid < l)
            modify(l, r, mid + 1, nowR, value, rs);
        else {
            modify(l, r, nowL, mid, value, ls);
            modify(l, r, mid + 1, nowR, value, rs);
        }
    }
}

int query (int l, int r, int nowL, int nowR, int n) {
    if (l <= nowL && nowR <= r)
        return seg[n].calc_sum();
    else {
        int mid = (nowL + nowR) >> 1, ls = n << 1, rs = n << 1 | 1;
        if (seg[n].tag) {
            seg[ls].tag += seg[n].tag;
            seg[rs].tag += seg[n].tag;
            seg[n].tag = 0;
        }
        if (r <= mid)
            return query(l, r, nowL, mid, ls);
        if (mid < l)
            return query(l, r, mid + 1, nowR, rs);
        return (query(l, mid, nowL, mid, ls) +
                query(mid + 1, r, mid + 1, nowR, rs)) % mod;
    }
}

signed main() {
    gura;

    int n, m, type, l, r, v;
    cin >> n;
    build(1, n, 1);
    cin >> m;
    while (m--) {
        cin >> type >> l >> r;
        if (type == 1) {
            cin >> v;
            modify(l, r, 1, n, v, 1);
        }
        else
            cout << query(l, r, 1, n, 1) << '\n';
    }
}
