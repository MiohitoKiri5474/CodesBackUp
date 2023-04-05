#include<stdio.h>

int main() {
    int n;
    scanf ( "%d", &n );
    for ( int i = 1 ; i < n ; i++ ) {
        for ( int j = i + 1 ; j <= n ; j++ )
            putchar ( ' ' );
        for ( int j = 1 ; j <= i * 2 - 1 ; j++ )
            putchar ( '*' );
        putchar ( '\n' );
    }
    for ( int i = n ; i > 0 ; i-- ) {
        for ( int j = i + 1 ; j <= n ; j++ )
            putchar ( ' ' );
        for ( int j = 1 ; j <= i * 2 - 1 ; j++ )
            putchar ( '*' );
        putchar ( '\n' );
    }
}
