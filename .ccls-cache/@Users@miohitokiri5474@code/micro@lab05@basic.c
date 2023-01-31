#include "xc.h"

extern unsigned int isprime ( unsigned int a );

void main ( void ) {
    volatile unsigned int res = isprime ( 19 );
    while ( 1 ) {
	}
    return;
}
