class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        prevIndex=0
        currentIndex=0
        currentRange=""
        n = len(nums)

        ans=[]

        for i in range(1, n + 1):
            if i<len(nums) and nums[i] == nums[i-1] + 1:
                continue
            else:
                currentIndex = i-1
                
                if prevIndex == currentIndex:
                    currentRange = str(nums[prevIndex])
                    ans.append(currentRange)
                else:
                    currentRange = str(nums[prevIndex]) + "->" + str(nums[currentIndex])
                    ans.append(currentRange)
                prevIndex = i

        return ans
