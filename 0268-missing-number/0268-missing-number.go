func missingNumber(nums []int) int {
    s := len(nums) * (len(nums)+1) / 2

    for _, n := range nums {
        s-=n
    }

    return s
}
