func scoreOfString(s string) int {
    n := len(s)
    ans := 0
    for i:=0;i<n-1;i++{
        // diff := 1
        charA := int('a')
        t1 := int(s[i])
        t1 -=charA
        t2 := int(s[i+1])
        t2 -=charA
        l1 := t1-t2
        diff := 0
        if l1>0{
            diff += l1
        }else{
            diff += -1*l1
        }
        
        // fmt.Println(diff)
        ans+= diff
    }
    return ans
}