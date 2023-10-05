pub struct Solution;
use std::collections::HashMap;
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut nums_hash = HashMap::new();
        for (i, &num) in nums.iter().enumerate() {
            let complement = target - num;
            if let Some(&index) = nums_hash.get(&complement) {
                return vec![index, i as i32];
            }
            nums_hash.insert(nums[i], i as i32);
        }
        vec![]
    }
}

pub fn run() {
    let nums = vec![3, 2, 4];
    let target = 6;
    let result = Solution::two_sum(nums, target);
    println!("Result: {:?}", result);
}
