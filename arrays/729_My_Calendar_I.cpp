/*
half-open interval [start, end) -> start has been included, end not included
So, [10,12) and [12, 14) are not conflicting, as in first, 12 is not included, and in second, 12 is included

a----b
   s----t
the conditions: a<t && s<b

Bruite Force:
Step1: Insert the initial event into the vector
Step2: Before inserting new event into the vector, 
check the same with each and every event present in the vector:
if its overlapping, insert false for it, 
if not overlapping, insert the event in the vector and insert true for it.

Optimal: 
To use ordered_set / ordered_map to insert the events in sorted fashion
set<pair<int,int>> st;
can also implement lower bound & upper bound to the pairs which are gonna inserted in the ordered_set
e.g: lowerBound({10,20}) --> find the element >=10 and the element <=20

lets say i need to add {10,20}, and {15, 25} already added in the set
then, st.lowerbound of {10,20} would be {15,25}

current event -> 10 --------- 20
                       15 ----------25

    it -> lowerbound -> {15,25}

    start -> 10
    end -> 20
    it.first -> 15
    here, it.first<end -> overlap -> return false

*/

//------------- Approach 1 -------------//
//checking every existed book for overlap
class MyCalendar {
public:
    vector<pair<int, int>> books;

    MyCalendar() {
        
    }
    
    bool book(int start, int end) {

        //iterating over the events array
        /*
        -> based on the following condition of overlapping, need to return false for the overlapped cases
        -> lets say i have [10,20] in my vector, and need to add [15,25] in the array
        -> So, while iterating, the pair would be [10,20], pair.start -> 10, pair.end -> 20
        -> condition for overlapping would be: max(first element of pair, start) < min(end, second element of the pair)
        -> so, in our case, as i want to add [15,25], 
            max(10, 15) -> 15
            min(20, 25) -> 20
            and as 15<20 ---> overlap
        */
        for(pair<int, int> p: books){
            if(max(p.first, start)<min(p.second, end)){
                return false;
            }
        }
        books.push_back({start, end});
        return true;
    }
};
//------------- Approach 2 -------------//
//Optimal Approach
class MyCalendar {
public:
    //initialising an ordered set
    set<pair<int, int>> st;

    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        //find the first event that starts after or the same time of {start, end}
        auto it = st.lower_bound({start, end});

        //check if current event overlaps with the next event
        if(it!=st.end() && it->first<end){
            return false;
        }

        //check if current event overlaps with the previous event
        if(it!=st.begin()){
            auto prevIt = prev(it);
            if(start < prevIt->second){
                return false;
            }
        }
        st.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
