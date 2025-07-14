class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        new_list = []
        n = len(nums)
        for i in range(n):
            temp = [nums[i],i]
            new_list.append(temp)

        new_l = sorted(new_list , key =lambda x : x[0])
        print(new_l)
        i = 0 
        j = n-1
        while i<j:
            sum1 = new_l[i][0] + new_l[j][0]
            if sum1 == target :
                return [new_l[i][1] , new_l[j][1]]
            elif sum1 > target :
                j-=1
            else:
                i+=1
        return -1    
