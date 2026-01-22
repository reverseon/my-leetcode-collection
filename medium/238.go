package main

import "fmt"

func productExceptSelf(nums []int) []int {
	var n int = len(nums)
	var result []int = make([]int, n)

	// First pass: calculate prefix products
	// result[i] = product of all elements to the left of i
	result[0] = 1
	var i int
	for i = 1; i < n; i++ {
		result[i] = result[i-1] * nums[i-1]
	}

	// Second pass: multiply by suffix products
	// suffix = product of all elements to the right of i
	var suffix int = 1
	for i = n - 1; i >= 0; i-- {
		result[i] *= suffix
		suffix *= nums[i]
	}

	return result
}

func main() {
	fmt.Println(productExceptSelf([]int{1, 2, 3, 4}))      // [24, 12, 8, 6]
	fmt.Println(productExceptSelf([]int{-1, 1, 0, -3, 3})) // [0, 0, 9, 0, 0]
}
