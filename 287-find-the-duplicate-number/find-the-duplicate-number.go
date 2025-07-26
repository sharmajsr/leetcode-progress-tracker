func findDuplicate(nums []int) int {
    ans := 0
    for i:= 0 ; i < len(nums) ; i+=1 {
        cur := nums[i]
        new_cur := cur
        if cur < 0 {
            new_cur = cur * -1
        }
        
        if nums[new_cur] < 0 {
            ans = new_cur
            break
        }
        nums[new_cur] = nums[new_cur] * -1
    }
    return ans
}

// [1,3,4,2,2]

// 1 - 1
// 3 - 1
// 4 - 1 
// 2 - 1
// TC- O(n) , SC - O(n)

//  1 , 3 ,  4 , 2 , 2
//  -1 , 3 ,  -4 , 2 , 2
// idx = 1
// cur = 3
// new_cur = abs(cur) - 1 = 2 
// 