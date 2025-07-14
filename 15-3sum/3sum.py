class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        nlist = nums.sort()
        print(nlist)
        i =0
        result_set = set()
        while i < n :
            j = i+1
            k = n-1
            while j<k:
                s1 = nums[i] + nums[j] + nums[k]
                if s1 == 0:
                    result_set.add((nums[i] , nums[j] ,nums[k]))
                    
                    while j<k and nums[j] == nums[j+1]:
                        j += 1
                    while j<k and nums[k] == nums[k-1]:
                        k -= 1

                    j += 1
                    k -=1
                elif s1 > 0 :
                    k-=1
                else :
                    j+=1
            i+=1

        return [i for i in list(result_set)]