/*
Concept:
-> Can use XOR to detect the bits that need to be flipped
-> if bits are equal —> their XOR would be 0
-> if bits are not equal —> their XOR would be 1
-> After finding the XOR, count the set bits (1s') -> return
 Method 1:
    -> To find the count of set bits, first AND between XOR result and '1'
    -> Then right shift (>>) by 1 and AND between resultant and '1'
    -> Do the same till XOR reaches to '0', till we right shift all the bits
    -> Calculate the count of set bits on the go
 Method 2:
    -> Till all the XOR bits becomes '0', Find the AND between XOR and XOR-1
    -> update the count (count++)
*/
//----------- Approach 1 -------------//
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorResult = start ^ goal;
        int count = 0;
        while(xorResult>0){
           count += xorResult & 1;
           xorResult = xorResult>>1;
        }
        return count;
    }
};

//---------- Appraoch 2 ----------//
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorResult = start ^ goal;
        int count = 0;
        while(xorResult>0){
            xorResult = xorResult & (xorResult-1);
            count++;
        }
        return count;
    }
};
