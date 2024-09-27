//------------ Approach 1 -----------//
/*
Bruite Force | Accessing each and every pair of start-end, and checking triple overlap
visual representation of the overlapping condition: https://claude.site/artifacts/a75a8ad3-d1ed-4f33-89e0-92f9093ebbf5

Why the following condition will not work:
if(start<p.first && end>p.second) 
https://claude.site/artifacts/5538e5ed-e129-4b74-9ce6-df615725ddf1

*/
class MyCalendarTwo {
public:
    vector<pair<int, int>> bookings;


//checking if sub-intervals getting overlapped morethan 2 times
bool check(int newStart, int newEnd){
    int overlappingCount = 0;
    //iterating over the vector and checking overlapping condition, maintaining count
    for(auto it: bookings){
        //newStart < it.second: This ensures that the new interval starts before the existing interval ends.
        //newEnd > it.first: This ensures that the new interval ends after the existing interval starts.
        if(newStart<it.second && newEnd>it.first){
            overlappingCount++;
            if(overlappingCount==2){
                return true;
            }
        }
    }
    return false;
}

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        //transversing the bookings vector and checking for triple overlap
        for(pair<int, int> p: bookings){
            //start < p.second: This ensures that the new booking starts before an existing booking ends.
            //end > p.first: This ensures that the new booking ends after an existing booking starts.
            if(start<p.second && end>p.first){
                int newStart = max(p.first, start);
                int newEnd = min(p.second, end);
                //if overlapping count of newStart & newEnd -> 2 -> true
                if(check(newStart, newEnd)){
                    return false;
                }
            }
        }

        //if no triple overlap, then add the start-end event pair in the vector
        bookings.push_back({start, end});
        return true;
    }
};



/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
