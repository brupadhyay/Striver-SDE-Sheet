Brute Force - TC -> O(n)
  SC -> O(1)
  
  So on leetcode 
  class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long int power = n;
        if( power<0) power = -1*power;
        
        for(int i=0;i<power;i++){
            ans = ans*x;
        }
        if( n<0) return (double)(1/ans);
        return ans;
    }
};

this runs all the test cases but gives TLE at a edge case of int max value


TO optimise it

We used fast exponentiation because we know odd power is (a^b/2)^2 * a
and even is (a^b/2)^2

TC-> log2(n)  bcz we divide n to n/2 at an alternate step
SC-> O(1)
  
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long int power = n;
        if( power<0) power = -1*power;
        
        while(power){
            if(power&1){
                ans = ans*x;
                power -= 1;
            }
            else{
                x = x*x;
                power = power>>1;
            }
        }
        if( n<0) return (double)(1/ans);
        return ans;
    }
};
