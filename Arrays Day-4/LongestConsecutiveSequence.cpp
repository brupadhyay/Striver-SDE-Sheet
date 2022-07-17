Solution 1: (Brute force)
Approach: We can simply sort the array and run a for loop to find the longest consecutive sequence.
  
Time Complexity: We are first sorting the array which will take O(N * log(N)) time and then we are running a for loop which will take O(N) time. 
Hence, the overall time complexity will be O(N * log(N)).
Space Complexity: The space complexity for the above approach is O(1) because we are not using any auxiliary space  


Solution 2: (Optimal Approach)

int longestConsecutive(vector < int > & nums) {
  set < int > hashSet;
  for (int num: nums) {
    hashSet.insert(num);
  }

  int longestStreak = 0;

  for (int num: nums) {
    if (!hashSet.count(num - 1)) {
      int currentNum = num;
      int currentStreak = 1;

      while (hashSet.count(currentNum + 1)) {
        currentNum += 1;
        currentStreak += 1;
      }

      longestStreak = max(longestStreak, currentStreak);
    }
  }

  return longestStreak;
}

Time Complexity -> O(N)
Space Complexity -> O(N)  
