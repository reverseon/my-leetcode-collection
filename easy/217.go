//go:build ignore

package main

import "fmt"

func containsDuplicate(nums []int) bool {
	// Using map[int]struct{} as a set - struct{} takes 0 bytes of memory
	// As opposed to map[int]bool which would use 1 byte per entry
	// Or map[int]int which would use 8 bytes per entry on 64-bit systems
	// since we only need to track existence, not store actual values
	var seen map[int]struct{} = make(map[int]struct{})
	var v int
	for _, v = range nums {
		// Comma-ok idiom: Go maps can return 1 or 2 values
		//   val := m[key]       -> returns value (or zero value if missing)
		//   val, ok := m[key]   -> ok is true if key exists, false if not
		// This distinguishes "key exists with value 0" from "key doesn't exist"
		// The compiler generates different code based on how you write the assignment
		var exists bool
		if _, exists = seen[v]; exists {
			return true
		}
		// struct{}{} is the literal value of an empty struct
		seen[v] = struct{}{}
	}
	return false
}

func main() {
	fmt.Println(containsDuplicate([]int{1, 2, 3, 1}))                   // true
	fmt.Println(containsDuplicate([]int{1, 2, 3, 4}))                   // false
	fmt.Println(containsDuplicate([]int{1, 1, 1, 3, 3, 4, 3, 2, 4, 2})) // true
}
