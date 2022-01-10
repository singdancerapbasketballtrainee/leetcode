package solution

func lengthOfLongestSubstring(s string) int {
	charPos := make(map[int32]int)
	if len(s) < 2 {
		return len(s)
	}
	ret := 0
	for i, char := range s {
		if pos, ok := charPos[char]; ok {
			if ret < len(charPos) {
				ret = len(charPos)
			}
			l := i - pos
			if l > ret {
				ret = l
			}
			charPos = make(map[int32]int)
		}
		charPos[char] = i
	}
	if ret < len(charPos) {
		return len(charPos)
	}
	return ret
}
