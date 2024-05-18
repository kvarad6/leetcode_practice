//------------ Approach 1 ------------//
// Hashset (to keep record of completed nums and avoid infinite loop) + Math (n%10 and n/10)
//TC: O(logN)
//SC: to be determined | Hash Table(unordered_set(set)) space

class Solution {
public:
    int nextNumber(int n){
        int newNumber = 0;
        while(n!=0){
            int num = n%10;
            newNumber += num*num;
            n = n/10;
        }
        return newNumber;
    }

    bool isHappy(int n) {
        unordered_set<int> set;
        while(n!=1 && set.count(n)==NULL){
            set.insert(n);
            n = nextNumber(n);
        }
        return n==1 ? true:false;
    }
};

//------------ Approach 2 ------------//
//Floyd's Cycle-Finding Algorithm
//using fast-slow pointer

class Solution {
public:
    int nextNumber(int n){
        int newNumber = 0;
        while(n!=0){
            int num = n%10;
            newNumber += num*num;
            n = n/10;
        }
        return newNumber;
    }

    bool isHappy(int n) {
        int fastPointer = nextNumber(n);
        int slowPointer = n;

        while(fastPointer!=1 && fastPointer!=slowPointer){
            slowPointer = nextNumber(slowPointer);
            fastPointer = nextNumber(nextNumber(fastPointer));
        }
        return fastPointer==1 ? true:false;
    }
};
