#include<bits/stdc++.h> 
  
using namespace std; 
  
int main(){ 
    ios::sync_with_stdio ( false ); 
    cin.tie ( 0 ); 
    cout.tie ( 0 ); 
  
    int n, cnt = 0; 
    while ( cin >> n && n ){ 
        cout << "Case " << ++cnt << ":\n"; 
        if ( n == 1 ){ 
            cout << "  1\n"; 
        } 
        else if ( n == 2 ){ 
            cout << "  1  2\n  3  4\n"; 
        } 
        else if ( n == 3 ){ 
            cout << "  1  2  6\n  3  5  7\n  4  8  9\n"; 
        } 
        else if ( n == 4 ){ 
            cout << "  1  2  6  7\n  3  5  8 13\n  4  9 12 14\n 10 11 15 16\n"; 
        } 
        else if ( n == 5 ){ 
            cout << "  1  2  6  7 15\n  3  5  8 14 16\n  4  9 13 17 22\n 10 12 18 21 23\n 11 19 20 24 25\n"; 
        } 
        else if ( n == 6 ){ 
            cout << "  1  2  6  7 15 16\n  3  5  8 14 17 26\n  4  9 13 18 25 27\n 10 12 19 24 28 33\n 11 20 23 29 32 34\n 21 22 30 31 35 36\n"; 
        } 
        else if ( n == 7 ){ 
            cout << "  1  2  6  7 15 16 28\n  3  5  8 14 17 27 29\n  4  9 13 18 26 30 39\n 10 12 19 25 31 38 40\n 11 20 24 32 37 41 46\n 21 23 33 36 42 45 47\n 22 34 35 43 44 48 49\n"; 
        } 
        else if ( n == 8 ){ 
            cout << "  1  2  6  7 15 16 28 29\n  3  5  8 14 17 27 30 43\n  4  9 13 18 26 31 42 44\n 10 12 19 25 32 41 45 54\n 11 20 24 33 40 46 53 55\n 21 23 34 39 47 52 56 61\n 22 35 38 48 51 57 60 62\n 36 37 49 50 58 59 63 64\n"; 
        } 
        else{ 
            cout << "  1  2  6  7 15 16 28 29 45\n  3  5  8 14 17 27 30 44 46\n  4  9 13 18 26 31 43 47 60\n 10 12 19 25 32 42 48 59 61\n 11 20 24 33 41 49 58 62 71\n 21 23 34 40 50 57 63 70 72\n 22 35 39 51 56 64 69 73 78\n 36 38 52 55 65 68 74 77 79\n 37 53 54 66 67 75 76 80 81\n"; 
        } 
    } 
}