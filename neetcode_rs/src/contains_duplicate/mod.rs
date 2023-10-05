pub struct Solution;
use std::collections::HashMap;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut number_map = HashMap::new();
        for n in nums {
            if number_map.contains_key(&n) {
                return true;
            } else {
                number_map.insert(n, 1);
            }
        }
        false
    }
}

pub fn run() {
    // Example usage of the solution
    let nums = vec![1, 2, 3, 1];
    let result = Solution::contains_duplicate(nums);
    println!("Result: {:?}", result);
}
