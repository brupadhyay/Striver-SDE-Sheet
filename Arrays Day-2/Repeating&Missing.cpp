for both the approaches below:
Time Complexity : O(N) 
  
Space Complexity : O(1)  As we are NOT USING EXTRA SPACE



First Approach ->

#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	  long long int len = n;
    long long int S = ( len*(len+1) )/ 2;
    long long int P = ( len*(len+1)*(2*len+1))/6;
    
    long long int missingNumber = 0, repeatingNumber = 0;
    pair<int,int> ans;
    for(int i: arr){
        S = S - (long long int)i;
        P = P - (long long int)i*(long long int)i;
    }
    
    missingNumber = ( S + P/S)/2;
    repeatingNumber = missingNumber - S;
    
    ans.first = missingNumber ;
    ans.second = repeatingNumber;
    return ans;
    
    
}

Second Approach->

#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int xor1 = arr[0];
//     pair<int,int> ans;
    int x = 0; //missing
    int y = 0; //repeating
    
    for(int i=1;i<n;i++){
        xor1 ^= arr[i];
    }
    for(int i=1; i<=n;i++){
        xor1 ^= i;
    }
    
    int rightmost = xor1 & ~(xor1-1);
    for(int i:arr)
    {
        if( rightmost & i)
            x = x^i;
        
        else y = y^i;
    }
    
    for(int i=1;i<=n;i++){
        if( i&rightmost){
            x = x^i;
        }
        else y = y^i;
    }
    
    int x_count = 0;
    for(int i=0;i<n;i++){
        if( x == arr[i]){
            x_count++;
        }
    }
    
    if( x_count == 0 ){
        return {x,y};
    }
    else return {y,x};
    
    
}

