class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        n = len(timePoints)

        minutesArray = []

        for time in timePoints:
            hour = time[0:2]
            minute = time[3:5]

            calculatedTime = int(hour)*60+int(minute)

            minutesArray.append(calculatedTime)

        minutesArray.sort()

        minDifference = float("inf")
        for i in range(1, n):
            currDifference = minutesArray[i] - minutesArray[i-1]
            if minDifference > currDifference:
                minDifference = currDifference
        
        return min(minDifference, 24*60-minutesArray[n-1]+minutesArray[0])
