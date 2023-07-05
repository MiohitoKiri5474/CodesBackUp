fn main() {
    let mut l: i32 = 0;
    let mut r: i32 = 100000;
    let target: i32 = 13984;
    let mut mid: i32 = ( l + r ) / 2;
    let mut cnt: i32 = 0;
    while l < r {
        println! ( "l: {}, r: {}, mid: {}", l, r, mid );
        cnt = cnt + 1;
        if mid < target {
            l = mid;
        }
        else if target < mid {
            r = mid;
        }
        else {
            println! ( "found, cost {} times.", cnt );
            break;
        }
        mid = ( l + r ) / 2;
    }
}
