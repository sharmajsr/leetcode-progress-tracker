class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        pair_nums = [] 
        for i in range(len(nums)):
            pair_nums.append([nums[i],i])


        # print(pair_nums)

        pair_nums.sort(key =lambda pair: pair[0])

        # print(pair_nums)

        i = 0 
        j = len(nums)-1
        while i<=j:
            sum1 = pair_nums[i][0] + pair_nums[j][0]
            if(sum1 == target):
                return [pair_nums[i][1],pair_nums[j][1]]
            elif sum1 > target : 
                j -=1 
            else:
                i+=1



        