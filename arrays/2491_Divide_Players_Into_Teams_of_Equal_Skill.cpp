//----------- Approach 1 ----------//
/*
-> Bruite force 
Step 1: Sort the original aray
Step 2: Use two pointers, transverse the array till middle, check for curresponding second half element (i and n-1-i) 
Step 3: Move the increment start pointer

TC: Sorting | O(nlogn) + transversing the array | O(n/2) ~ O(nlogn)
SC: O(1)
*/
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        if (n % 2 != 0) return -1;

        //sorting the original array
        sort(skill.begin(), skill.end());

        //two pointers 
        long long chemistry = skill[0]*skill[n-1];
        int skillsSum = skill[0]+skill[n-1];

        if (n == 2) return chemistry;

        for(int i=1;i<n/2;i++){
            int j = n-1-i;
            int currentSum = skill[i]+skill[j];
            if(skillsSum!=currentSum){
                return -1;
            }
            //(long)(long) -> prevents integer overload
             chemistry += (long long)skill[i]*skill[j];
        }

        return chemistry;
    }
};
