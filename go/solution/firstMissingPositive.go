package solution

// T41 缺失的第一个正数
func firstMissingPositive(nums []int) int {
	record := make([]int, len(nums))
	for _, num := range nums {
		if num > 0 && num <= len(nums) {
			record[num-1]++
		}
	}
	for ind, cnt := range record {
		if cnt == 0 {
			return ind + 1
		}
	}
	return len(nums) + 1
}

func firstMissingPositive2(nums []int) int {
	l := len(nums)
	for ind, num := range nums {
		if num <= 0 {
			nums[ind] = l + 1
		}
	}
	for _, num := range nums {
		n := intAbs(num)
		if n > 0 && n <= l {
			nums[n-1] = -intAbs(nums[n-1])
		}
	}
	for ind, num := range nums {
		if num > 0 {
			return ind + 1
		}
	}
	return l + 1
}

func intAbs(n int) int {
	if n < 0 {
		n = -n
	}
	return n
}
