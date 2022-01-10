package solution

import "bytes"

func intToRoman(num int) string {
	nums := []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
	romans := []string{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}
	ans := bytes.Buffer{}
	for i := range nums {
		for num >= nums[i] {
			num -= nums[i]
			ans.WriteString(romans[i])
		}
	}
	return ans.String()
}
