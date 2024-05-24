class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        #check if journey possible or not
        totalGas=0
        totalCost=0

        for i in range(len(gas)):
            totalGas += gas[i]
            totalCost += cost[i]
        
        if totalGas < totalCost:
            return -1
        
        #check if we can start from any gas station or not
        remainingGas=0
        startingIndex=0
        for i in range(len(gas)):
            remainingGas += gas[i] - cost[i]
            if remainingGas<0:
                startingIndex = i+1
                remainingGas=0
        
        return startingIndex
