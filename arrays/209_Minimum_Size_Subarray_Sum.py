import sys
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        i=0
        j=0
        sum=0
        minimalLength=sys.maxsize

        while j<len(nums):
            sum += nums[j]
            while(sum>=target):
                currentLength = j-i+1
                minimalLength = min(currentLength, minimalLength)
                sum -= nums[i]
                i += 1
            
            j += 1
        
        if minimalLength == sys.maxsize:
            return 0
        return minimalLength
