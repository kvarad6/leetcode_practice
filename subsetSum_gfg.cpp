class Solution
{
public:

    void recursiveSum(int index, int sum, vector<int> &arr, int N, vector<int> &result){
        //base case
        if(index == N){
            result.push_back(sum);
            return;
        }
        
        //recursive relation
        
        //pick an element
        recursiveSum(index+1, sum + arr[index], arr, N, result);
        
        //not pick an element
        recursiveSum(index+1, sum, arr, N, result);
        
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> result;
        int index = 0;
        int sum = 0;
        recursiveSum(index, sum, arr, N, result);
        sort(result.begin(), result.end());
        return result;
    }
};
