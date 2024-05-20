//最大值查詢
#include<bits/stdc++.h>

using namespace std;

int heap[105], sz = 0;
inline void push ( int x );
inline void pop ( void );

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );

	int n, stop;
	cin >> n;
	for ( int i = 0 ; i < n ; i++ ){
		cin >> stop;
		push ( stop );
	}

	for ( int i = 0 ; i < 2 * n ; i++ )
		cout << heap[i] << ' ';
	cout << '\n';

    while ( sz ) {
        cout << heap[0] << ' ';
        pop();
    }
    cout << '\n';
}

inline void push ( int x ){
    heap[sz] = x;
	int i = sz++;
    while ( true ) {
        int p = ( i - 1 ) / 2;

        if ( p < 0 || heap[i] <= heap[p] )
            break;

        swap ( heap[i], heap[p] );
        i = p;
    }
}

inline void pop ( void ){
    swap ( heap[0], heap[sz] );
    int i = 0;
    while ( true ) {
        int leftSon = i * 2 + 1, rightSon = i * 2 + 2, ma = i;
        if ( leftSon < sz && heap[leftSon] > heap[ma] )
            ma = leftSon;
        if ( rightSon < sz && heap[rightSon] > heap[ma] )
            ma = rightSon;

        if ( ma == i )
            break;

        swap ( heap[ma], heap[i] );
        i = ma;
    }
    sz--;
}
