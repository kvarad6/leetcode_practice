class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {\
        int missingObservationSum = 0;
        int m = rolls.size();
        int availableObservationSum = 0;
        for(int i=0; i<m;i++){
            availableObservationSum += rolls[i];
        }
        missingObservationSum = mean*(n+m)-availableObservationSum;
        
        //sum of missing observations should be in the range: (n*1 - n*6), as the digits to be filled are between 1-6 only
        if(missingObservationSum<n || missingObservationSum>6*n){
            return {};
        }

        //take reminder using the modulus and distribute the same evenly in the missingObservations array
        int rem = missingObservationSum%n;

        //count avg and distribute it equally in the missingObservations array (to be distributed evenly)
        int q = missingObservationSum/n;
        vector<int> missingObservations(n, q);
        //start filling the same in circular way, missingObservations array
        for(int i=1;i<=rem;i++){
            missingObservations[i]++;
        }
        return missingObservations; 
    }
};
