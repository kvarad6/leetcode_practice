class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        #creating a copy of the original array and storing it in temp
        temp = arr.copy()

        temp.sort()

        rankDict = {}
        rank = 1

        for num in temp:
            if num not in rankDict:
                rankDict[num] = rank
                rank = rank+1

        #way 1 | inserting rank in ans list:

        #initialising an ans array
        #can't directly use "ans[i] = rankDict[arr[i]]" without initialisation as in Python, you can't assign values to indices that don't exist yet. 
        ans = [0]*len(arr)

        for i in range(0, len(arr)):
            ans[i] = rankDict[arr[i]]
        
        #way 2 | inserting rank in ans list:
        #another way:
        ans = []
        for num in arr:
            ans.append(rankDict[num])
        
        return ans



