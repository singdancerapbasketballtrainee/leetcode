package solution

import "sort"

func fourSum(nums []int, target int) [][]int {
	sort.Ints(nums)
	length := len(nums)
	if length < 4 {
		return nil
	}
	ret := make([][]int, 0)
	for left := 0; left < length-3; left++ {
		if left != 0 && nums[left] == nums[left-1] {
			continue
		}
		for right := length - 1; right > left+2; right-- {
			if right != length-1 && nums[right] == nums[right+1] {
				continue
			}
			midLeft, midRight := left+1, right-1
			for midLeft < midRight {
				if nums[left]+nums[midLeft]+nums[midRight]+nums[right] < target {
					midLeft++
				} else if nums[left]+nums[midLeft]+nums[midRight]+nums[right] > target {
					midRight--
				} else {
					ret = append(ret, []int{nums[left], nums[midLeft], nums[midRight], nums[right]})
					for nums[midLeft] == nums[midLeft+1] && midLeft < midRight {
						midLeft++
					}
					for nums[midRight] == nums[midRight-1] && midLeft < midRight {
						midRight--
					}
					midLeft++
					midRight--
				}
			}
		}
	}
	return ret
}
