#------------ Approach 2 ------------
# Using two dictionaries
# dict1 -> mapping of s->t
# dict2 -> mapping of t->s
# In case of isomorphic strings, both mappings should be equal

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        dict1 = {}
        dict2 = {}

        #converting strings to char lists
        sList = list(s)
        tList = list(t)

        #transversing char list
        for i, char in enumerate(sList):
            #if key (sList[i]) found in dict1
            if sList[i] in dict1:
                #if value corresponding to key is not equal to tList[i]
                if dict1[sList[i]]!=tList[i]:
                    return False
            
            #if key (tList[i]) found in dict2
            if tList[i] in dict2:
                #if value corresponding to key is not equal to sList[i]
                if dict2[t[i]]!=sList[i]:
                    return False
        
            #map s->t | insert key-value pair
            dict1[sList[i]] = tList[i]

            #map t->s | insert key-value pair
            dict2[tList[i]] = sList[i]
        
        return True

