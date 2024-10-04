class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        skill.sort()

        n = len(skill)

        sumSkills = skill[0]+skill[n-1]
        chemistry = 0

        i=0
        j=n-1
        currentSum = 0
        while i<j:
            currentSum = skill[i]+skill[j]
            if currentSum!=sumSkills:
                return -1
            
            chemistry = chemistry + skill[i]*skill[j]
            i = i+1
            j = j-1
        
        return chemistry
