class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        //Using unordered set to store the obstacles (by converting it into string)
        unordered_set<string> st;
        for(auto obst: obstacles){
            string key = to_string(obst[0]) + "_" + to_string(obst[1]);
            st.insert(key);
        }

        //we are starting from the origin
        int x = 0;
        int y = 0;
        int maxDistance = 0;

        //Initially, we are pointing towards north, storing the same in the pair, will keep updating this pair on the go
        //direction.first -> x
        //direction.second -> y
        pair<int, int> direction = {0, 1};

        for(int i=0;i<commands.size();i++){
            //-2 -> 90 degree left -> {-y,x}
            if(commands[i]==-2){
                direction = {-direction.second, direction.first};
            }
            //-1 -> 90 degree right -> {y,-x}
            else if(commands[i]==-1){
                direction = {direction.second, -direction.first};
            }
            //1-9 -> update the x and y co-ordinates and check for the obstacles
            else{
                //move towards current direction step by step
                for(int step=0;step<commands[i];step++){
                    int newX = x + direction.first;
                    int newY = y + direction.second;

                    //convert the same to the string to check if its an obstacle or not (check if its present in unordered set or not)
                    string nextKey = to_string(newX) + "_" + to_string(newY);
                    if(st.find(nextKey)!=st.end()){
                        break;
                    }
                    x = newX;
                    y = newY;
                }
            }
            //compare and update the maxDistance | need to find square of euclidian distance as per the question
            maxDistance = max(maxDistance, x*x + y*y);
        }
        return maxDistance;
    }
};
