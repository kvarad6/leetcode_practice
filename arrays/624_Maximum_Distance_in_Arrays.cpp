
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxDistance = 0;
        int smallest = arrays[0][0];
        int biggest = arrays[0].back();
        for(int i=1;i<arrays.size();i++){
            maxDistance = max(maxDistance, abs(arrays[i].back() - smallest));
            maxDistance = max(maxDistance, abs(biggest - arrays[i][0]));
            smallest = min(arrays[i][0], smallest);
            biggest = max(arrays[i].back(), biggest);
        }
        return maxDistance;
    }
};
