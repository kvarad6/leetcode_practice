//----------- Approach 1 -----------//
//Bruite force approach
//Using the defination: if the number has only 2 divisors -> prime number
//TC: O(n^2) | TLE
class Solution {
public:
    bool checkPrime(int n){
        int countDivisors = 0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                countDivisors++;
            }
        }
        if(countDivisors==2){
            return true;
        }
        return false;
    }

    int countPrimes(int n) {
        
        int countPrimes = 0;
        
        for(int i=2;i<n;i++){
            if(checkPrime(i)==true){
                countPrimes++;
            }
        }
        return countPrimes;
    }
};

//----------- Approach 2 -----------//
/*
Optimal approach | Sieve of Eratosthenes
checking if a number is prime or not in a constant time
We need to precomputate an array 
Step 1:
-> Create a array starts from 2 -> N, initialised with 1

Step 2:
-> Mark the multiple of 2 as '0' as they are not the prime numbers

Step 3:
-> Iterate the array again, and, if the number is prime (marked as 1), then mark all its multiple as '0'

*/


class Solution {
public:
    int countPrimes(int n) {
        //precalculation of the array
        //declaring an array of size n+1, initially marking them as '0'
        vector<int> prime(n+1);

        //finding the numbers whose divisor is 2 and marking them as 1
        for(int i=2; i<n; i++){
            prime[i] = 1;
        }

        //iterating the array, checking if the number is prime and marking all its multiple as 0
        for(int i=2; i<n; i++){
            if(prime[i]==1){
                //the for loop starts with j = 2*i. This is because i itself is prime, and we don't want to mark it as non-prime. We start with its first multiple that's greater than itself.
                for(int j=2*i; j<=n; j+=i){
                    prime[j] = 0;
                }
            }
        }
        int countPrimes = 0;
        //use precomputed prime array to check the number is prime or not in the constant time
        for(int i=2; i<n; i++){
            if(prime[i]==1){
                countPrimes++;
            }
        }
        return countPrimes;

    }
};
