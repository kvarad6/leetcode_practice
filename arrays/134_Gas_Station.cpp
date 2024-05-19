//------------ Approach 1 ------------//
//Using kadane's alg | Greedy
//first step: check for total gas and total cost of the journey
//if total gas >= total cost -> journey possible

//second step -> to identify starting point, just check if [gas at that station - cost] required at that station,
//if its positive, can start from that station, otherwise go to next station

//TC: O(N)
//SC:O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //step 1
        int totalGas = 0, totalCost=0;
        for(int i=0;i<gas.size();i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if(totalGas<totalCost){
            return -1;
        }

        //step 2

        int startingPoint = 0, currentGas=0;

        for(int i=0; i<gas.size();i++){
            currentGas += gas[i] - cost[i];
            if(currentGas < 0){
                currentGas = 0;
                startingPoint = i+1;
            }
        }

        return startingPoint;
    }
};
