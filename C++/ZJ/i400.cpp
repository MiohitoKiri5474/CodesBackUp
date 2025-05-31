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

vector < string > lib;

signed main() {
    gura;

    int n, m, cnt;
    string str, tmp;
    cin >> n >> m;
    lib.resize ( n );
    for ( auto &i: lib )
        cin >> i;
    cin >> str;
    reverse ( lib.begin(), lib.end() );
    for ( auto i: lib ) {
        cnt = 0;
        tmp = "";
        reverse ( i.begin(), i.end() );
        for ( auto j: i ) {
            if ( j == '0' )
                tmp = str.back() + tmp;
            else {
                cnt++;
                tmp += str.back();
                tmp = str.back() + tmp;
            }
            str.pop_back();
        }
        str = tmp;
        if ( cnt & 1 )
            for ( int j = 0 ; j < m / 2 ; j++ )
                swap ( str[j], str[m - m / 2 + j] );
    }
    cout << str << endl;
}
