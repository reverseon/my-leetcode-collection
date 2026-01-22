package main

import "fmt"

func groupAnagrams(strs []string) [][]string {
	var mapping map[[26]int][]string = make(map[[26]int][]string)

	var s string
	for _, s = range strs {
		var freq [26]int
		var ch rune
		for _, ch = range s {
			freq[ch-'a']++
		}
		mapping[freq] = append(mapping[freq], s)
	}

	var result [][]string = make([][]string, 0, len(mapping))
	var group []string
	for _, group = range mapping {
		result = append(result, group)
	}
	return result
}

func main() {
	fmt.Println(groupAnagrams([]string{"eat", "tea", "tan", "ate", "nat", "bat"}))
	// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
	fmt.Println(groupAnagrams([]string{""}))
	// Output: [[""]]
	fmt.Println(groupAnagrams([]string{"a"}))
	// Output: [["a"]]
}
