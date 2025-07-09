class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans = []
        d1 = {}
        nums.sort()
        res = set()
        i= 0 
        n = len(nums)
        for i in range(len(nums)-2):
            j = i+1
            k = n-1
            while j<k:
                # print(i,j,k)
                tsum = nums[i] + nums[j] + nums[k]
                if tsum == 0 :
                    temp = (nums[i],nums[j],nums[k])
                    res.add(temp)
                    
                    while j<n-1 and nums[j] == nums[j+1]: 
                        j += 1
                    while k > 0 and nums[k] == nums[k-1]:
                        k -= 1

                    j += 1
                    k -= 1
                    
                elif tsum > 0:
                    k -= 1 
                else :
                    j += 1 
        
        for i in res:
            ans.append(list(i))
        return ans


        