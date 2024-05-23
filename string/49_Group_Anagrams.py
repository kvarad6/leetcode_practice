class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagramsMap = defaultdict(list)

        for word in strs:
            #sort the word
            sortedWord = ".".join(sorted(word))
            #add similar words in anagramsMap
            anagramsMap[sortedWord].append(word)

        #return values form anagramsMap
        return list(anagramsMap.values())
