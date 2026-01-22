package main

import "fmt"

func isAnagram(s string, t string) bool {
	// If it is an anagram, both strings must be of equal length
	if len(s) != len(t) {
		return false
	}
	var fr map[rune]int = make(map[rune]int)
	// Count frequency of each character in string s. fr by default returns 0 for missing keys
	var c rune // Rune is an alias for int32, represents a Unicode code point. a.k.a. character

	// Build frequency map for string s
	for _, c = range s {
		fr[c]++
	}

	for _, c = range t {
		if fr[c] <= 0 { // Character in t not found in s or excess occurrence
			return false
		}
		fr[c]-- // Decrement count for character found in t
	}
	return true
}

func main() {
	fmt.Println(isAnagram("anagram", "nagaram")) // true
	fmt.Println(isAnagram("rat", "car"))         // false
	fmt.Println(isAnagram("listen", "silent"))   // true
}
