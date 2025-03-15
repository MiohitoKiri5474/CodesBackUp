// by. MiohitoKiri5474
#include <bits/stdc++.h>
#include <cstddef>

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
    node *next;
    int value;
    node ( int _val ): next ( nullptr ), value ( _val ) {}
};

inline int delete_member ( node *head, int target ) {
    int res = -1;
    node *it = head;
    while ( it && target != it -> value )
        it = it -> next;

    if ( it && it -> next ) {
        res = it -> next -> value;
        it -> next = it -> next -> next;
    }

    return res;
}

signed main() {
    gura;

    int n, m, in;
    node *head = new node ( 1 ), *tmp = head;

    cin >> n >> m;
    // building list
    for ( int i = 2 ; i <= n ; i++ ) {
        tmp -> next = new node ( i );
        tmp = tmp -> next;
    }

    while ( m-- ) {
        cin >> in;
        n = delete_member ( head, in );
        if ( ~n )
            cout << n << '\n';
        else
            cout << "0u0 ...... ?\n";
    }
}

// 1 1 5 4
// 1 2 3 4 5
