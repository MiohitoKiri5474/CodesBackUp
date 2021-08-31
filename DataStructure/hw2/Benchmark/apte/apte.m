axis equal;
hold on
grid on

% area range
block_x = [ 0 0 6885 6885 0 ];
block_y = [ 0 6951 6951 0 0 ];
fill ( block_x, block_y, 'w', 'Edgecolor', 'r' );

% cc_11
block_x = [ 0 0 1582 1582 0 ];
block_y = [ 3318 6949 6949 3318 3318 ];
fill ( block_x, block_y, 'c' );
text ( 791, 5133.5, 'cc_11' );

% cc_12
block_x = [ 0 0 1731 1731 0 ];
block_y = [ 0 3318 3318 0 0 ];
fill ( block_x, block_y, 'c' );
text ( 865.5, 1659, 'cc_12' );

% cc_13
block_x = [ 1731 1731 5882 5882 1731 ];
block_y = [ 0 1383 1383 0 0 ];
fill ( block_x, block_y, 'c' );
text ( 3806.5, 691.5, 'cc_13' );

% cc_14
block_x = [ 3760 3760 6883 6883 3760 ];
block_y = [ 1383 3222 3222 1383 1383 ];
fill ( block_x, block_y, 'c' );
text ( 5321.5, 2302.5, 'cc_14' );

% cc_21
block_x = [ 1731 1731 3760 3760 1731 ];
block_y = [ 1383 4259 4259 1383 1383 ];
fill ( block_x, block_y, 'c' );
text ( 2745.5, 2821, 'cc_21' );

% cc_22
block_x = [ 3760 3760 6883 6883 3760 ];
block_y = [ 3222 5090 5090 3222 3222 ];
fill ( block_x, block_y, 'c' );
text ( 5321.5, 4156, 'cc_22' );

% cc_23
block_x = [ 1582 1582 3750 3750 1582 ];
block_y = [ 4259 6951 6951 4259 4259 ];
fill ( block_x, block_y, 'c' );
text ( 2666, 5605, 'cc_23' );

% cc_24
block_x = [ 3750 3750 6885 6885 3750 ];
block_y = [ 5090 6951 6951 5090 5090 ];
fill ( block_x, block_y, 'c' );
text ( 5317.5, 6020.5, 'cc_24' );

% clk
block_x = [ 5882 5882 6162 6162 5882 ];
block_y = [ 0 843 843 0 0 ];
fill ( block_x, block_y, 'c' );
text ( 6022, 421.5, 'clk' );
