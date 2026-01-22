package main

import "fmt"

func topKFrequent(nums []int, k int) []int {
	// Step 1: Count frequency of each number
	var freq map[int]int = make(map[int]int)
	var num int
	for _, num = range nums {
		freq[num]++
	}

	// Step 2: Create buckets where bucket[i] holds numbers appearing i times
	// Key insight: max possible frequency is len(nums) (if all elements are same)
	// So we create len(nums)+1 buckets (index 0 to len(nums))
	var buckets [][]int = make([][]int, len(nums)+1)
	var count int
	for num, count = range freq {
		buckets[count] = append(buckets[count], num)
	}

	// Step 3: Collect top k elements by iterating from highest frequency bucket
	// Start from the end (highest frequency) and work backwards
	var result []int = make([]int, 0, k) // 0 initial length, k capacity
	var i int
	for i = len(buckets) - 1; i >= 0 && len(result) < k; i-- {
		result = append(result, buckets[i]...) // Append all elements in the bucket.
	}
	return result[:k]

}

func main() {
	fmt.Println(topKFrequent([]int{1, 1, 1, 2, 2, 3}, 2)) // [1, 2]
	fmt.Println(topKFrequent([]int{1}, 1))                // [1]
}
