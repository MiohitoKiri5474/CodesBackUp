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

int dp[maxN];
int from[maxN];
vector < int > input;

void print ( int last ) {
    if ( from[last] != -1 )
        print ( from[last] );
    cout << input[last] << '\n';
}

signed main() {
    gura;

    int tms, ans, last;
    bool fk = false;
    string str;
    cin >> tms;
    getline ( cin, str );
    getline ( cin, str );
    while ( tms-- ) {
        input.clear();
        while ( getline ( cin, str ) ) {
            if ( str == "" )
                break;
            input.pb ( stoi ( str ) );
        }

        ans = last = 0;
        for ( int i = 0 ; i < input.size() ; i++ ) {
            dp[i] = 1;
            from[i] = -1;
            for ( int j = i - 1 ; j >= 0 ; j-- )
                if ( input[i] > input[j] && dp[j] + 1 > dp[i] )
                    dp[i] = dp[j] + 1, from[i] = j;

            if ( dp[i] > ans )
                last = i, ans = dp[i];
        }

        if ( fk )
            cout << '\n';
        cout << "Max hits: " << ans << '\n';
        print ( last );
        fk = true;
    }
}
