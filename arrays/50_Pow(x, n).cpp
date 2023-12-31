//---------- Approach 1 ------------//
//bruite force
//TLE if power is too large | x=1, n=214343564 etc.

class Solution {
public:
    double myPow(double x, int n) {
        
        double ans = 1;
        long long int power = n;
        if(n<0){
            power *= -1;
        }
        for(int i=0;i<power;i++){
            ans *= x;
        }
        if(n<0){
            ans = (double)(1.0) / (double)(ans);
        }
        return ans;
    }
};

//---------- Approach 2 ------------//
//optimised approach
//dividing power into half

//when power is even --> x*n --> n=n/2
//when power is odd --> ans = ans*x --> n=n-1

class Solution {
public:
    double myPow(double x, int n) {
        long long int power = n;
        double ans = 1.0;
        
        if(n<0){
            power *= -1;
        }
        while(power){
            //if power is odd
            if(power%2==1){
                ans = ans * x;
                power = power - 1;
            }
            //else if power is even
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
