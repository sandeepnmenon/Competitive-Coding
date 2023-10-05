#!/bin/bash

# Check if problem key is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <problem_key>"
    exit 1
fi

# Convert problem key to snake_case (if it's kebab-case)
problem_key=$(echo $1 | sed 's/-/_/g')

# Create directory and files
mkdir -p src/$problem_key
echo "pub struct Solution;

impl Solution {
    pub fn $problem_key() {
        // Your solution here
    }
}

pub fn run() {
    // Example usage of the solution
    let result = Solution::$problem_key();
    println!(\"Result: {:?}\", result);
}" > src/$problem_key/mod.rs

echo "Module $problem_key created!"
