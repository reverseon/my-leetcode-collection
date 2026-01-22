package main

import "fmt"

func twoSum(nums []int, target int) []int {
	var pair map[int]int // Remaining is in -> (index+1) # because default is 0
	pair = make(map[int]int, len(nums))
	var idx int
	var val int
	for idx, val = range nums {
		if pair[val] != 0 {
			return []int{pair[val] - 1, idx} // Subtract 1 to get original index
		}
		pair[target-val] = idx + 1 // Tell presence by storing (index+1)
	}
	return []int{}
}

func main() {
	fmt.Println(twoSum([]int{2, 7, 11, 15}, 9)) // [0, 1]
	fmt.Println(twoSum([]int{3, 2, 4}, 6))      // [1, 2]
	fmt.Println(twoSum([]int{3, 3}, 6))         // [0, 1]
}
