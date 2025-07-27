func countHillValley(nums []int) int {
    ans := 0 
    for i:=1 ;i < len(nums)-1 ; i++{
        prev :=  nums[i] 
        next := nums[i]
        if nums[i] == nums[i-1]{
            continue
        }
        for j:=i-1 ; j>=0 ;j--{
            if nums[j] != nums[i]{
                prev = nums[j]
                break
            }
        }
        for k:=i +1 ;k<len(nums);k++{

            if nums[k]!=nums[i]{
                next =nums[k]
                break
            }
        }
        if prev == nums[i] || next == nums[i]{
            continue
        }
        if prev > nums[i] && next > nums[i]{
            ans +=1 
        }else if prev < nums[i] && next < nums[i]{
            ans +=1 
        }
    }
    return ans
}