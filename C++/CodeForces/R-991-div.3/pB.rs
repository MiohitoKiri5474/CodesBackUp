use std::io::stdin;
fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).expect("Input error.");
    let t = input.trim().parse::<i64>().expect("Input type error.");
    for _rd in 0..t {
        input = String::new();
        stdin().read_line(&mut input).expect("Imput error.");
        let parses: Vec<&str> = input.trim().split_whitespace().collect();
        let n = parses[0].parse::<i64>().expect("Input type error.");

        input = String::new();
        stdin().read_line(&mut input).expect("Imput error.");
        let nums: Vec<&str> = input.trim().split_whitespace().collect();
        let mut odd: i64 = 0;
        let mut even: i64 = 0;

        for i in 0..n {
            if i % 2 == 0 {
                odd += nums[i as usize].trim().parse::<i64>().expect("Type error");
            } else {
                even += nums[i as usize].trim().parse::<i64>().expect("Type error");
            }
        }
        if odd % ((n + 1) / 2) == 0 && even % (n / 2) == 0 && odd / ((n + 1) / 2) == even / (n / 2)
        {
            println!("Yes");
        } else {
            println!("No");
        }
    }
}
