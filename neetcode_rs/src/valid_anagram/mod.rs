pub struct Solution;
use std::collections::HashMap;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut s_map = HashMap::new();
        let mut t_map = HashMap::new();

        for c in s.chars() {
            let count = s_map.entry(c).or_insert(0);
            *count += 1;
        }

        for c in t.chars() {
            let count = t_map.entry(c).or_insert(0);
            *count += 1;
        }

        s_map == t_map
    }
}

pub fn run() {
    let s = String::from("anagram");
    let t = String::from("nagaram");
    let result = Solution::is_anagram(s, t);
    println!("Result: {:?}", result);
}
