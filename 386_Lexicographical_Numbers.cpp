//-------------- Approach 1 -------------//
/*
lexicographical order ->  an arrangement of characters, words, or numbers in alphabetical order
n -> 13
-> [1,2,3,4,5,6,7,8,9,10,11,12,13]
-> lexicographical order-> [1,10,11,12,13,2,3,...,9]

Step 1: convert the int array from [1,n] to strings
Step 2: sort string array -> sorts in lexicographical order
Step 3: convert the string array back to int

TC: O(nlogn)
SC: O(2n) ~ O(n)
Expected: TC -> O(n) | SC -> O(1)
*/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        //initialising a vector to store 1-n elements
        vector<string> elements;

        //storing elements in a range 1-n in the string vector
        for(int i=1;i<=n;i++){
            elements.push_back(to_string(i));
        }

        //sorting the vector of strings (by default lexicographical sort)
        sort(elements.begin(), elements.end());

        //converting strings array to the int array
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(stoi(elements[i]));
        }

        return ans;
    }
};

//-------------- Approach 2 -------------//
/*
-> Optimised Approach
-> Using DFS | Recursion
-> valid range: [1,n]
So, form the numbers starting with 1, append 0-9 and check range
If, the number is in range, add it in the final array
otherwise it the number is out of bound, return the recursive call.

-> TC: O(n)
-> SC: O(no. of digits in n) -> O(logn)
The space complexity consists of two main components:
a) The space used by the result vector
b) The space used by the recursive call stack
The result vector will contain all numbers from 1 to n, so it uses O(n) space.
The recursive call stack's depth is determined by the maximum number of digits in n.

For a number n, the maximum depth would be log₁₀(n) + 1.
This is because each recursive call adds one digit to the number.
The space used by the call stack is thus O(log n).
*/
class Solution {
public:
    void dfsHelper(int currNum, int n, vector<int> &result){
        //if current number exceeds limit, return the recursive call
        if(currNum>n){
            return;
        }

        //push the current number into the result vector
        result.push_back(currNum);

        //append the digit from 0-9 one by one and check if the number is in the range, if yes, continue in that direction
        for(int append=0; append<=9; append++){
            int newNumber = currNum*10+append;
            if(newNumber>n){
                return;
            }
            dfsHelper(newNumber, n, result);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> result;

        //iterate over 1 to 9 digits, call the dfs function for each digit
        for(int startNum=1;startNum<=9;startNum++){
            dfsHelper(startNum, n, result);
        }
        
        return result;
    }
};
