Solution 1: Brute Force

Intuition: The brute force solution is to generate all possible subarrays. For each generated subarray we get the respective XOR 
and then check if this XOR is equal to B.
If it is then we increment the count. In the end, we will get the count of all possible subarrays that have XOR equal to B.
  
class Solution{ 
    public:
    int solve(vector<int> &A, int B) {
    long long c=0;
    for(int i=0;i<A.size();i++){
        int current_xor = 0;
        for(int j=i;j<A.size();j++){
            current_xor^=A[j];
            if(current_xor==B) c++;
        }
    }
    return c;
}
};

TC - O(n^2)
SC - O(1)
  
Solution 2: Prefix xor and map

int solve(vector<int> &A, int B) {
    unordered_map<int,int>visited;
    int cpx = 0;
    long long c=0;
    for(int i=0;i<A.size();i++){
        cpx^=A[i];
        if(cpx==B) c++;
        int h = cpx^B;
        if(visited.find(h)!=visited.end()){
            c=c+visited[h];
        }
        visited[cpx]++;
    }
    return c;
}
Time Complexity: O(N)

Space Complexity: O(N)
