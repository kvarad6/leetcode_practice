#.strip() -> used to remove leading and treailing white spaces..
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()
        length = 0
        for i in s[::-1]:
            
            if i==' ':
                break
            length+=1
        return length


        
