axis equal;
hold on
grid on

% area range
block_x=[ 0 0 10 10 0];
block_y=[ 0 12 12 0 0];
fill(block_x,block_y,'w','Edgecolor','r');
% block location
block_x=[ 0 0 6 6 0];
block_y=[ 0 4 4 0 0];
fill(block_x,block_y,'c');
text(3,2,'n1');
block_x=[ 6 6 10 10 6];
block_y=[ 0 6 6 0 0];
fill(block_x,block_y,'c');
text(8,3,'n2');
block_x=[ 0 0 2 2 0];
block_y=[ 4 8 8 4 4];
fill(block_x,block_y,'c');
text(1,6,'n3');
block_x=[ 2 2 4 4 2];
block_y=[ 4 7 7 4 4];
fill(block_x,block_y,'c');
text(3,5.5,'n4');
block_x=[ 4 4 8 8 4];
block_y=[ 6 10 10 6 6];
fill(block_x,block_y,'c');
text(6,8,'n5');
block_x=[ 0 0 8 8 0];
block_y=[ 10 12 12 10 10];
fill(block_x,block_y,'c');
text(4,11,'n6');
