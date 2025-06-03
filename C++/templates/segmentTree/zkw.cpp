#include <bits/stdc++.h>

using namespace std;

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
        for (int i = base; i > 0; i--)
            seg[i] = seg[i << 1] + seg[i << 1 | 1];
    }

    inline void update ( int pos, int val) {
        for (seg[pos += base] = val, pos >>= 1; pos > 1; pos >>= 1)
            seg[pos] = seg[pos << 1] + seg[pos << 1 | 1];
    }

    inline int query (int l, int r) {
        int res = 0;
        for (l += base, r += base; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += seg[l++];
            if (r & 1) res += seg[--r];
        }
        return res;
    }
};

