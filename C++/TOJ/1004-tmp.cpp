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
const int maxN = 100005;

struct node {
    node *l, *r;
    vector<int> v;
    MinHeap<int> pq;

    node() {
        l = r = nullptr;
    }

    inline void prepare (void);
} *root = nullptr;

int K;
vector<int> query_tmp;
unordered_map<int, int> ans;

inline void node::prepare() {
    if (!pq.empty()) {
        while (!pq.empty()) {
            v.pb(pq.top());
            pq.pop();
        }
        reverse(v.begin(), v.end());
    }
}

inline void merge(vector<int> &parent, vector<int> &child) {
    vector<int> tmp;
    auto pIT = parent.begin(), cIT = child.begin();
    while (tmp.size() < K && pIT != parent.end() && cIT != child.end())
        tmp.pb(*pIT > *cIT ? *pIT++ : *cIT++);

    while (tmp.size() < K && pIT != parent.end())
        tmp.pb(*pIT++);

    while (tmp.size() < K && cIT != child.end())
        tmp.pb(*cIT++);

    swap(child, tmp);
}

void modify(int l, int r, int nowL, int nowR, int value, node *&n) {
    if (!n)
        n = new node();
    if (l <= nowL && nowR <= r) {
        n->pq.push(value);
        if (n->pq.size() > K)
            n->pq.pop();
        return;
    }
    int mid = (nowL + nowR) >> 1;
    if (r <= mid)
        modify(l, r, nowL, mid, value, n->l);
    else if (mid < l)
        modify(l, r, mid + 1, nowR, value, n->r);
    else {
        modify(l, r, nowL, mid, value, n->l);
        modify(l, r, mid + 1, nowR, value, n->r);
    }
}

void query(int l, int r, int index, node *n) {
    if (!n)
        return;
    if (!(n->pq.empty()))
        n->prepare();
    if (!n->v.empty())
        merge(n->v, query_tmp);
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (index <= mid)
        query(l, mid, index, n->l);
    else
        query(mid + 1, r, index, n->r);
}

signed main() {
    gura;

    int n, q, x, L = 2147483647, R = -2147483648;
    cin >> n >> q >> K;
    for (int i = 0, l, r, w; i < n; i++) {
        cin >> l >> r >> w;
        if (w < 0)
            continue;
        modify(l, r, 1, 1000000000, w, root);
        L = min(L, l);
        R = max(R, r);
    }
    while (q--) {
        cin >> x;
        if (L <= x && x <= R && ans.find(x) == ans.end()) {
            query_tmp.clear();
            query(1, 1000000000, x, root);
            ans[x] = 0;
            for (auto &v : query_tmp)
                ans[x] += v;
        }
        cout << ans[x] << ' ';
    }
    cout << '\n';
}
