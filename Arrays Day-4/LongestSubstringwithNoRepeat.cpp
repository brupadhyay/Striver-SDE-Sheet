Brute Force -

int solve(string str) {
  int maxans = INT_MIN;
  for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
  {
    unordered_set < int > set;
    for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
    {
      if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
      {
        maxans = max(maxans, j - i);
        break;
      }
      set.insert(str[j]);
    }
  }
  return maxans;
}
TC - O(n^2)
  SC - O(n)


Optimised Soln 1 - 
  
int solve(string str) {
  int maxans = INT_MIN;
  unordered_set < int > set;
  int l = 0;
  for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
  {
    if (set.find(str[r]) != set.end()) //if duplicate element is found
    {
      while (l < r && set.find(str[r]) != set.end()) {
        set.erase(str[l]);
        l++;
      }
    }
    set.insert(str[r]);
    maxans = max(maxans, r - l + 1);
  }
  return maxans;
}
Time Complexity: O( 2*N ) 
Space Complexity: O(N)
  
 
  
Optimised Soln2
Approach: In this approach, we will make a map that will take care of counting 
the elements and maintaining the frequency of each and every element as a unity by taking the latest index of every element.


int lengthofLongestSubstring(string s) {
      vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
TC - O(n)
  Sc - O(n)
 


we can use freq array instead to reduce space to O(1)
  internal loop will be
  int freq[256] = 0 //256 because ascii values from 0 to 255
  freq[s[r]]++;
while(l<r && freq[s[r]] > 1){
  freq[s[l]]--;
  l++;
}
ans = max(ans, r-l+1);
r++;
