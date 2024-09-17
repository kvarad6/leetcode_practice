from collections import Counter
class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        s1List = s1.split()
        s2List = s2.split()
        allWords = s1List + s2List

        wordFreq = Counter(allWords)

        result = []

        for word, freq in wordFreq.items():
            if freq == 1:
                result.append(word)
        return result
