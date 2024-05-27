class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:

        if len(points)==0:
            return 0

        #sort the points list
        points.sort()

        arrowsRequired = 1
        prevBallonEnd = points[0][1]

        for i in range(1, len(points)):
            currentXstart = points[i][0]
            currentXend = points[i][1]

            if currentXstart > prevBallonEnd:
                arrowsRequired += 1
                prevBallonEnd = currentXend
            else:
                prevBallonEnd = min(prevBallonEnd, currentXend)
            
        return arrowsRequired


