mod contains_duplicate;
mod two_sum;
mod valid_anagram;

fn main() {
    let args: Vec<String> = std::env::args().collect();
    if args.len() != 2 {
        eprintln!("Usage: {} <problem_key>", args[0]);
        std::process::exit(1);
    }

    let problem_key = &args[1].replace("-", "_");
    match problem_key.as_str() {
        "contains_duplicate" => contains_duplicate::run(),
        "valid_anagram" => valid_anagram::run(),
        "two_sum" => two_sum::run(),
        _ => eprintln!("Problem {} not found", problem_key),
    }
}
