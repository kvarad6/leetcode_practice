class Solution:
    def maxArea(self, height: List[int]) -> int:
        i=0
        j=len(height)-1
        maxArea=0

        while i<=j:
            currentWidth = j-i
            currentHeight = min(height[i], height[j])
            currentArea = currentWidth * currentHeight
            maxArea = max(maxArea, currentArea)

            #Always move the pointer that points to the lower line.
            if height[i]<height[j]:
                i += 1
            else:
                j-=1
        
        return maxArea

