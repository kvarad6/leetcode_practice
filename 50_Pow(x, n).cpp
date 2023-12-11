class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long power = n;

        //if power is negative...
        if(power<0){
            power = -1 * power;
        }

        while(power){
            //if power is odd..
            if(power%2==1){
                ans = ans * x;
                power = power - 1;
            }

            //if power is even..
            else{
                x = x * x;
                power = power/2;
            }
        }

        //if n was negative, return ans in the form of 1/ans, as power was negative..
        if(n<0){
            ans = (double)(1.0) / (double)(ans);
        }

        return ans;
    }
};
