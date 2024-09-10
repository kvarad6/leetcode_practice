/*
observation:
-> whenever we go towards east or west direction, steps value will be incremented by 1
-> no change in the step count whenever we go towards south or north direction

For east -> (0,1) to be added in current co-ordinates
For south -> (1,0) to be added in the current co-ordinates
For west -> (0,-1) to be added in the current co-ordinates
For north -> (-1,0) to be added in the current co-ordinates 

Movement is happening in the direction: East->South->West->North
Directions = {{0,1}, {1,0}, {0,-1}, {-1,0}}
In the direction, post north, we are again moving back to the east.
So, this can be handled using: dir = (dir+1)%4, where 'dir'->index in the direction array

*/

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {

        //creating a direction array to change and track the direction
        vector<vector<int>> directions = {
                                    {0,1}, //East
                                    {1,0}, //South
                                    {0,-1}, //West
                                    {-1,0} //North
                                };

        //declare a 2d vector to store the co-ordinates
        vector<vector<int>> result;

        int steps = 0; //how much steps to take
        int dir = 0; //in dir direction | index in the directions vector

        //Adding the starting position to the result vector
        result.push_back({rStart, cStart});

        //running the loop till we cover all the grids and store them in "result"

        //Move in the current direction for the current number of steps
        while(result.size()<rows*cols){
            //if direction is east/west, we'll increment the steps
            if(dir==0 || dir==2){
                steps++;
            }
            //covering all steps
            for(int count=0; count<steps; count++){
                //updating new start of current row and column
                rStart += directions[dir][0];
                cStart += directions[dir][1];

                //checking the valid cells | considering cells present in the boundary
                //If the current position is within the matrix bounds, add it to the result
                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){
                    result.push_back({rStart, cStart});
                }
            }
            //After completing all the steps in the current direction, updating the direction
            //Change direction (clockwise: East -> South -> West -> North -> East)
            dir = (dir+1)%4;
        }
        return result;
    }
};
