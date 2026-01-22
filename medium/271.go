package main

import (
	"fmt"
	"strconv"
)

type Solution struct{}

// Encode takes a list of strings and encodes them into a single string.
//
// The encoding strategy uses length-prefixing with a delimiter:
// For each string, we prepend its length followed by a '#' character.
//
// Example: ["hello", "world"] -> "5#hello5#world"
//
// Why this works:
// - We don't need to worry about escape characters or special delimiters
// - The length tells us exactly how many characters to read after the '#'
// - This handles ALL edge cases: empty strings, strings containing '#',
//   strings containing numbers, strings with newlines, etc.

func (s *Solution) Encode(strs []string) string {
	// result will accumulate our encoded string
	var result string = ""

	// Iterate through each string in the input slice
	var i int
	for i = 0; i < len(strs); i++ {
		// Get the current string
		var currentStr string = strs[i]

		// Get the length of the current string
		var length int = len(currentStr)

		// Append the length, delimiter '#', and the actual string
		// Format: <length>#<string>
		// Example: "hello" becomes "5#hello"
		result = result + fmt.Sprintf("%d", length) + "#" + currentStr
	}

	return result
}

// Decode takes an encoded string and decodes it back into a list of strings.
//
// The decoding process:
// 1. Find the position of '#' delimiter
// 2. Parse the number before '#' to get the string length
// 3. Extract exactly that many characters after '#'
// 4. Move the pointer and repeat until we've processed the entire string
//
// Example: "5#hello5#world" -> ["hello", "world"]

func (s *Solution) Decode(encoded string) []string {
	// result will hold our decoded strings
	var result []string = []string{}

	// currentIndex tracks our position in the encoded string
	var currentIndex int = 0

	// Process the encoded string until we've consumed it all
	for currentIndex < len(encoded) {
		// Find the position of the '#' delimiter starting from currentIndex
		// The number before '#' represents the length of the following string
		var delimiterIndex int = currentIndex

		// Scan forward to find the '#' character
		// The characters between currentIndex and delimiterIndex form the length number
		for encoded[delimiterIndex] != '#' {
			delimiterIndex = delimiterIndex + 1
		}

		// Extract the length substring (the digits before '#')
		var lengthStr string = encoded[currentIndex:delimiterIndex]

		// Convert the length string to an integer
		// This tells us how many characters to read after the '#'
		var length int
		var err error
		length, err = strconv.Atoi(lengthStr)
		if err != nil {
			// In a valid encoded string, this should never happen
			// But we handle it gracefully just in case
			return result
		}

		// The actual string starts right after the '#' delimiter
		var stringStart int = delimiterIndex + 1

		// The string ends at stringStart + length
		var stringEnd int = stringStart + length

		// Extract the original string using the calculated bounds
		var originalStr string = encoded[stringStart:stringEnd]

		// Add the decoded string to our result slice
		result = append(result, originalStr)

		// Move the currentIndex to the start of the next encoded segment
		// which is right after the current string ends
		currentIndex = stringEnd
	}

	return result
}

func main() {
	s := Solution{}

	// Test 1: Basic case
	encoded := s.Encode([]string{"hello", "world"})
	decoded := s.Decode(encoded)
	fmt.Println("Test 1 - Basic:")
	fmt.Println("  Encoded:", encoded)
	fmt.Println("  Decoded:", decoded)

	// Test 2: Empty strings in the list
	encoded2 := s.Encode([]string{"", ""})
	decoded2 := s.Decode(encoded2)
	fmt.Println("Test 2 - Empty strings:")
	fmt.Println("  Encoded:", encoded2)
	fmt.Println("  Decoded:", decoded2)

	// Test 3: Strings containing the delimiter '#'
	encoded3 := s.Encode([]string{"#", "##", "a#b"})
	decoded3 := s.Decode(encoded3)
	fmt.Println("Test 3 - Strings with '#':")
	fmt.Println("  Encoded:", encoded3)
	fmt.Println("  Decoded:", decoded3)

	// Test 4: Strings containing numbers
	encoded4 := s.Encode([]string{"123", "4#5"})
	decoded4 := s.Decode(encoded4)
	fmt.Println("Test 4 - Strings with numbers:")
	fmt.Println("  Encoded:", encoded4)
	fmt.Println("  Decoded:", decoded4)
}
