//----------- Appraoch 1 ----------//
/*
-> need to find the difference in minutes (hours*60)
-> need to convert into minutes to find the difference | reference point is 00:00
-> by considering 00:00 as the reference point, multiply hour by 60
-> e.g: [05:00] -> minutes -> 5*60 -> 300 minutes
-> [07:34] -> minutes -> 7*60+34 -> 454 minutes
-> so overall, we need to convert the original list into minutes list, and find a min difference among a pair of minutes.
-> To find the pair with minimum difference -> sort the minutes array -> find the difference between adj pairs -> record the minimum difference among all adj pairs
-> Additional case to consider:
   in case of ["23:59", "00:00"], there are two ways we can find the difference
   first way: when we convert elements into minutes,
   minutesArray would be: [1439, 0], so the min difference would be 1439
   second way: but as we know, there is difference of only 1 minute betweeen two, so, this need to be handled
   -> As we converted the hours and minutes to the minutes array by taking 00:00 as the reference point,
      so, the closet times to the 00:00 would be the first and last one
    -> another possible min difference would be -> 24*60 - lastelement + firstone
*/
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        //23:59 -> HH:MM -> minutes -> (23*60)+59 -> 1439
        //initialise an array to store curresponding converted minutes.
        vector<int> minutesArray(n);

        //transverse the timePoints array, convert in minutes on the go, and store it in the minutesArray
        //use substr concept to extract the hours and minutes from the string
        for(int i=0;i<n;i++){
            string time = timePoints[i];
            //"00:00" "HH:MM"
            cout<<time<<endl;
            string hourString = time.substr(0, 2);
            string minutesString = time.substr(3, 2);

            int minutes = stoi(hourString)*60+stoi(minutesString);
            cout<<minutes<<endl;
            minutesArray[i] = minutes;
        }

        //sort the minutesArray
        sort(minutesArray.begin(), minutesArray.end());

        //transverse the sorted array and find the min diff between adj pairs
        int minDifference = INT_MAX;
        int currDifference = 0;
        for(int i=1;i<n;i++){
            cout<<minutesArray[i]<<endl;
            currDifference = minutesArray[i]-minutesArray[i-1];
            minDifference = min(minDifference, currDifference);
        }

        return min(minDifference, 24*60-minutesArray[n-1]+minutesArray[0]);
    }
};
