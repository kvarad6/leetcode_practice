class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        n = len(arr)
        pre = [0]*n
        pre[0] = arr[0]
        ans = []

        for i in range(1, n):
            pre[i] = pre[i-1]^arr[i]
        
        for k in range(0, len(queries)):
            i = queries[k][0]
            j = queries[k][1]

            if i==0:
                ans.append(pre[j])
            else:
                ans.append(pre[i-1]^pre[j])
        
        return ans
