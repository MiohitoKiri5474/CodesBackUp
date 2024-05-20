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
    cout << ( flag ? "Yes\n" : "No\n" );
}
const int maxN = 100005;

inline void solved ( void ) {
    string str;
    cin >> str;
    int len = str.size();
    bool flag = false;
    for ( int i = 1 ; i < len && !flag ; i++ )
        if ( str[i] < str[i - 1] )
            flag = true;

    if ( !flag ) {
        cout << "1\n";
        return;
    }

    int ans = 1;
    flag = false;
    for ( int i = 1 ; i < len ; i++ ) {
        if ( str[i - 1] != str[i] ) {
            if ( !flag && str[i - 1] == '0' && str[i] == '1' )
                flag = true;
            else
                ans++;
        }
    }
    cout << ans << '\n';
}

signed main() {
    gura;

    int t;
    cin >> t;
    while ( t-- ) {
        solved();
    }
}
