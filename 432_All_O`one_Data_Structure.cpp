//---------- Approach 1 ----------//
/*
-> Using map | TLE
*/
class AllOne {
private:
    map<string, int> mpp;
    int maxCount;
    string maxKey;
    string minKey;
    int minCount;
public:
    AllOne() {
        maxCount = INT_MIN;
        minCount = INT_MAX;
    }
    
    void inc(string key) {
        if(mpp.find(key)!=mpp.end()){
            mpp[key]++;
        }
        else{
            mpp[key] = 1;
        }
    }
    
    void dec(string key) {
        mpp[key]--;
        if(mpp[key]==0){
            mpp.erase(key);
        }
    }
    
    string getMaxKey() {
        string maxKey = "";
        int maxCount = 0;
       for(auto it: mpp){
            if(maxCount<it.second){
                maxCount = it.second;
                maxKey = it.first;
            }
       }
       return maxKey;
    }
    
    string getMinKey() {
        string minKey = "";
        int minCount = INT_MAX;
        for(auto it: mpp){
            if(minCount>it.second){
                minCount = it.second;
                minKey = it.first;
            }
        }
       return minKey;
    }
    
};

//---------- Approach 2 --------//
/*
-> Using two datastructure
    one -> unordered_map<string, int> -> to find the frequency/count of each key
    two -> map<int, unordered_set<string>> -> to group the keys based on their frequency/ count

*/

class AllOne {
private:
    unordered_map<string, int> keyCount;
    map<int, unordered_set<string>> countKeys;
public:
    AllOne() {
       
    }
    //TC:O(logn)
    void inc(string key) {
        //If the key exists, remove it from its old count group.
        if(keyCount.count(key)>0){
            int oldCount = keyCount[key];
            countKeys[oldCount].erase(key);
            if(countKeys[oldCount].empty()){
                countKeys.erase(oldCount);
            }
        }

        //Increment the key's count.
        keyCount[key]++;

        //Add the key to its new count group.
        countKeys[keyCount[key]].insert(key);
    }
    
    //TC:O(logn)
    void dec(string key) {
       //If the key exists, remove it from its old count group.
       if(keyCount.count(key)>0){
            int oldCount = keyCount[key];
            countKeys[oldCount].erase(key);
            if(countKeys[oldCount].empty()){
                countKeys.erase(oldCount);
            }
       }

        //Decrement the key's count.
        keyCount[key]--;

        //If the new count is 0, remove the key entirely.
        //Otherwise, add the key to its new count group.
        if(keyCount[key]==0){
            keyCount.erase(key);
        }else{
            countKeys[keyCount[key]].insert(key);
        }
    }
    
    //TC:O(1)
    string getMaxKey() {
        //Return any key from the set with the highest count.
        if(countKeys.empty()){
            return "";
        }
        /*
        countKeys.rbegin() -> gets a reverse iterator to the last (highest count) element in the map.
        ->second -> accesses the value part of this key-value pair, which is an unordered_set<string>.
        .begin() gets an iterator to the first element of this set.
        * dereferences this iterator to get the actual string.
        */
        return *countKeys.rbegin()->second.begin();
    }
    
    //TC:O(1)
    string getMinKey() {
        if(countKeys.empty()){
            return "";
        }
        return *countKeys.begin()->second.begin();
    }
    
};


//---------- Approach 3 | Pending --------//
/*
-> Using doubly-linked list and a hashmap
   (just like designing a LRU cache :))
   -> Here we are using DLL instead of vector/ array as in case of array, insertion/ deletion takes O(n) time due to shifting of elements
   -> We can't use singly LL as at any node, we need to have the access to prev node, and in DLL we have that access
   -> Insertion/ deletion in DLL takes O(1) time which is expected in this problem
*/

class AllOne {
private:
   
public:
    AllOne() {
       
    }
    
    void inc(string key) {
        
    }
    
    void dec(string key) {
       
    }
    
    string getMaxKey() {
        
    }
    
    string getMinKey() {

    }
};




/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

