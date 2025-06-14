// by. MiohitoKiri5474
#include <bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

// type and pair definition
using LL = long long;
using pii = pair < int, int >;
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
    cout << ( flag ? "Yes\n" : "No\n" );
}
const int maxN = 2000005;

pii seg[maxN << 1];

inline void init (int n, vector<int> &v) {
    for (int i = 0; i < n; ++i)
        seg[i + n] = {v[i], v[i]};
    for (int i = n - 1; i > 0; --i)
        seg[i] = {min(seg[i << 1].F, seg[i << 1 | 1].F), max(seg[i << 1].S, seg[i << 1 | 1].S)};
}

inline bool query (int l, int r, int n) {
    int ma = -2147483648, mi = 2147483647;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            ma = max(ma, seg[l].S);
            mi = min(mi, seg[l].F);
            l++;
        }
        if (r & 1) {
            r--;
            ma = max(ma, seg[r].S);
            mi = min(mi, seg[r].F);
        }
    }
    return ma == mi;
}

signed main() {
    gura;

    int n, m, l, r;
    vector<int> v;
    cin >> n >> m;
    v.resize(n);
    for (auto &i : v)
        cin >> i;

    init (n--, v);
    while (m--) {
        cin >> l >> r;
        print_ans (query (l, r + 1, n));
    }
}
