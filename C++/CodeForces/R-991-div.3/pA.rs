use std::io::stdin;
fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).expect("Input error.");
    let t = input.trim().parse::<i32>().expect("Input type error.");
    for _rd in 0..t {
        let mut str;
        let mut ans: i32 = 0;
        let mut lib: Vec<String> = Vec::<String>::new();

        input = String::new();
        stdin().read_line(&mut input).expect("Imput error.");
        let parses: Vec<&str> = input.trim().split_whitespace().collect();
        let n = parses[0].parse::<i32>().expect("Input type error.");
        let mut m = parses[1].parse::<i32>().expect("Input type error.");

        for _i in 0..n {
            str = String::new();
            stdin().read_line(&mut str).expect("Input error.");
            lib.push(str.trim().parse::<String>().expect("Input type error."));
        }

        for i in 0..n {
            let str_len = lib[i as usize].len() as i32;
            if m < str_len {
                break;
            }
            m -= str_len;
            ans += 1;
        }

        println!("{}", ans);
    }
}
