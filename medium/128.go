package main

import "fmt"

func longestConsecutive(nums []int) int {
	// Create a hash set to store all numbers for lookup.
	// This allows us to quickly check if a number exists in the input.
	var numSet map[int]bool = make(map[int]bool)
	var num int
	for _, num = range nums {
		numSet[num] = true
	}

	var longest int = 0

	// Iterate through each unique number in the set.
	// Note: Go maps do NOT iterate in sorted order - the order is randomized.
	// This means we might encounter numbers in any order (e.g., 200, 1, 100, 4, 3, 2).
	for num = range numSet {
		// Check if this number is the START of a sequence.
		// A number is a sequence start only if (num - 1) does NOT exist in the set.
		// For example: if we have [1, 2, 3, 4], only 1 is a sequence start because 0 doesn't exist.
		// We skip 2, 3, 4 because their predecessors (1, 2, 3) exist in the set.
		// This check is crucial because:
		// 1. It prevents redundant counting (we don't want to count 2->3->4, 3->4, 4 separately)
		// 2. It ensures we always count a sequence from its true beginning
		if !numSet[num-1] {
			// Found a sequence start! Now count how long this sequence is.
			var length int = 1

			// Keep extending the sequence as long as the next consecutive number exists.
			// For example: starting at 1, check if 2 exists, then 3, then 4, etc.
			for numSet[num+length] {
				length++
			}

			// Update longest if this sequence is longer than any we've seen before.
			// We do NOT break here because there may be multiple separate sequences
			// in the input (e.g., [1,2,3,4] and [100] and [200] are three sequences).
			// We must check ALL sequences to find the truly longest one.
			if length > longest {
				longest = length
			}
		}
	}
	return longest
}

func main() {
	fmt.Println(longestConsecutive([]int{100, 4, 200, 1, 3, 2})) // 4
	fmt.Println(longestConsecutive([]int{0, -1}))                // 2
}
