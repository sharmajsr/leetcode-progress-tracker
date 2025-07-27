func findDuplicate(nums []int) int {
    var ans int
    for i:= 0 ; i<len(nums) ; i+=1{
        cur := nums[i]
        next_cur := cur-1
        if cur <0 {
            next_cur = cur*-1 - 1
        }
        if nums[next_cur] < 0 {
            ans = next_cur+1
            break
        }
        nums[next_cur] = nums[next_cur] * -1
    }
    return ans
}

