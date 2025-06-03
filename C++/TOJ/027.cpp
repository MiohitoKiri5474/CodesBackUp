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

struct ZKW {
    int base;
    vector <int> seg;

    ZKW (int n): base (n) {
        seg.resize(base << 1, 0);
        base--;
    }

    ZKW (int n, vector <int> &v): base (n) {
        seg.resize(base << 1, 0);

        memcpy (&seg[base--], v.data(), n * sizeof(int));
        for (int i = base; i > 0; i--) {
            seg[i] = max (seg[i << 1], seg[i << 1 | 1]);
        }
    }

    inline void update ( int pos, int val) {
        for (seg[pos += base] = val, pos >>= 1; pos > 1; pos >>= 1)
            seg[pos] = max (seg[pos << 1], seg[pos << 1 | 1]);
    }

    inline int query (int l, int r) {
        int res = -2147483648;
        for (l += base, r += base; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max (res, seg[l++]);
            if (r & 1) res = max (res, seg[--r]);
        }
        return res;
    }
};

signed main() {
    gura;

    int n, m, l, r, res;
    char op;
    cin >> n;
    vector < int > input ( n );
    for (auto &i: input)
        cin >> i;
    ZKW seg (n, input);
    cin >> m;
    while ( m-- ) {
        cin >> op >> l >> r;
        if ( op == 'C' )
            seg.update (l, r);
        else {
            if ( l > r )
                swap ( l, r );
            cout << seg.query (l, r + 1) / 2 << '\n';
        }
    }
}
