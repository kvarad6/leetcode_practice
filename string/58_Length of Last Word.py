#-------- Method 1 ---------#
# to remove trailing spaces and traverse from back
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


#-------------- Method 2 -----------#
# strip -> split in words -> if there is not word, return 0, else return last word length 
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        words = s.strip().split()

        if not words:
            return 0

        return len(words[len(words)-1]) # can write len(words[-1]) instead


        
