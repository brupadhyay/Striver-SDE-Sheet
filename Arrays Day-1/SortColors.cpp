class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        //Dutch National flag Algorithm 
        // Time complexity O(N)
        // space complexity O(1)
        
        int low  = 0;
        int high = nums.size() - 1;
        int mid  = 0;
        while(mid <= high)
        {
            switch(nums[mid])
            {
                case 0:
                       swap(nums[mid],nums[low]);
                       mid++;
                       low++;
                    break;

                    
                case 1:
                    mid++;
                    break;
                    
                    
                case 2 :
                    swap(nums[mid],nums[high]);
                    high--;
                    break;
                   
            }
        }
      
      }
};
      
 Better approach ->
   
   
 class Solution {
public:
    void sortColors(vector<int>& nums) {
  int count_0=0,count_1=0,count_2=0;
	for(int i=0; i<nums.size(); i++){
		switch(nums[i])
		{
			case 0 :count_0++;
				   break;
				
			case 1 :count_1++;
				  break;
				
			case 2 : count_2++;
				 break;
				
		}
        
    }
        
        for(int i=0; i<nums.size();i++){
		while(count_0){
			nums[i] = 0;
			count_0--;
			i++;
		}
		while(count_1){
			nums[i] = 1;
			count_1--;
			i++;
		}
		while(count_2){
			nums[i] = 2;
			count_2--;
			i++;
		}
	}
    
    }
};
