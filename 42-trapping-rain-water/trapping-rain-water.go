func trap(height []int) int {
    n := len(height)
    left :=0 
    right := n-1
    leftBar := height[left]
    rightBar := height[right]
    ans := 0 
    for ; left < right ; {
        if leftBar < rightBar{
            ans += leftBar - height[left]
            left +=1
            leftBar = max(leftBar , height[left])
        }else{
            ans += rightBar - height[right]
            right -=1
            rightBar = max(rightBar, height[right])
        }
    }
    return ans
}