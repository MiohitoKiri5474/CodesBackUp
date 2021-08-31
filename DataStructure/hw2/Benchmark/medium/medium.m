axis equal;
hold on
grid on

% area range
block_x = [ 0 0 110 110 0 ];
block_y = [ 0 100 100 0 0 ];
fill ( block_x, block_y, 'w', 'Edgecolor', 'r' );

% m1
block_x = [ 0 0 20 20 0 ];
block_y = [ 0 30 30 0 0 ];
fill ( block_x, block_y, 'c' );
text ( 10, 15, 'm1' );

% m10
block_x = [ 0 0 20 20 0 ];
block_y = [ 30 70 70 30 30 ];
fill ( block_x, block_y, 'c' );
text ( 10, 50, 'm10' );

% m11
block_x = [ 20 20 32 32 20 ];
block_y = [ 30 42 42 30 30 ];
fill ( block_x, block_y, 'c' );
text ( 26, 36, 'm11' );

% m12
block_x = [ 32 32 48 48 32 ];
block_y = [ 54 64 64 54 54 ];
fill ( block_x, block_y, 'c' );
text ( 40, 59, 'm12' );

% m13
block_x = [ 20 20 32 32 20 ];
block_y = [ 42 52 52 42 42 ];
fill ( block_x, block_y, 'c' );
text ( 26, 47, 'm13' );

% m14
block_x = [ 0 0 16 16 0 ];
block_y = [ 70 84 84 70 70 ];
fill ( block_x, block_y, 'c' );
text ( 8, 77, 'm14' );

% m15
block_x = [ 16 16 20 20 16 ];
block_y = [ 70 90 90 70 70 ];
fill ( block_x, block_y, 'c' );
text ( 18, 80, 'm15' );

% m16
block_x = [ 0 0 30 30 0 ];
block_y = [ 90 100 100 90 90 ];
fill ( block_x, block_y, 'c' );
text ( 15, 95, 'm16' );

% m2
block_x = [ 20 20 44 44 20 ];
block_y = [ 0 24 24 0 0 ];
fill ( block_x, block_y, 'c' );
text ( 32, 12, 'm2' );

% m3
block_x = [ 44 44 66 66 44 ];
block_y = [ 0 32 32 0 0 ];
fill ( block_x, block_y, 'c' );
text ( 55, 16, 'm3' );

% m4
block_x = [ 66 66 76 76 66 ];
block_y = [ 0 10 10 0 0 ];
fill ( block_x, block_y, 'c' );
text ( 71, 5, 'm4' );

% m5
block_x = [ 66 66 74 74 66 ];
block_y = [ 10 20 20 10 10 ];
fill ( block_x, block_y, 'c' );
text ( 70, 15, 'm5' );

% m6
block_x = [ 44 44 78 78 44 ];
block_y = [ 32 54 54 32 32 ];
fill ( block_x, block_y, 'c' );
text ( 61, 43, 'm6' );

% m7
block_x = [ 66 66 90 90 66 ];
block_y = [ 54 80 80 54 54 ];
fill ( block_x, block_y, 'c' );
text ( 78, 67, 'm7' );

% m8
block_x = [ 90 90 110 110 90 ];
block_y = [ 54 70 70 54 54 ];
fill ( block_x, block_y, 'c' );
text ( 100, 62, 'm8' );

% m9
block_x = [ 66 66 88 88 66 ];
block_y = [ 80 96 96 80 80 ];
fill ( block_x, block_y, 'c' );
text ( 77, 88, 'm9' );
