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
#define GL ( n ) getline ( cin, n )
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

int l;
string k;
set < string > lib;

bool dfs ( string &tmp ) {
    if ( tmp.size() == l ) {
        if ( lib.find ( tmp ) == lib.end() )
            return true;
        return false;
    }

    for ( auto i: k ) {
        tmp += i;
        if ( dfs ( tmp ) )
            return true;
        tmp.pop_back();
    }
    return false;
}

signed main() {
    gura;

    string str, tmp;
    int len;
    cin >> k >> l >> str;

    for ( int i = 0 ; i < l ; i++ )
        tmp += str[i];
    len = str.size();
    lib.insert ( tmp );
    for ( int i = l ; i < len ; i++ ) {
        tmp.erase ( tmp.begin() );
        tmp += str[i];
        lib.insert ( tmp );
    }

    tmp = "";
    dfs ( tmp );
    cout << tmp << endl;
}
