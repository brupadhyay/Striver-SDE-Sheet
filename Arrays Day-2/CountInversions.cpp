Time complexity -> O(nlogn) //merge sort time complexity

Space Complexity -> O(n)  as we are using auxiliary space for the temp array to avoid distortion



Codestudio Edge cases (imp problem)
#include <bits/stdc++.h> 
long long merge(long long arr[],long long temp[], long long int left,long long int mid, long long int right){
    long long int i = left;
    long long int j = mid;
    long long int k = left;
    long long int inv_cnt = 0;
    
    while( (i<=mid-1) && (j<=right) )
    {
        if( arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        } else{
            temp[k++] = arr[j++];
            inv_cnt += (mid-i);
        }
    }
    while( i<=mid-1){
        temp[k++] = arr[i++];
    }
    while(j<=right){
        temp[k++] = arr[j++];
    }
    for(int i=left;i<=right;i++){
        arr[i] = temp[i];
    }
    
    
    return inv_cnt;
    
}
long long mergeSort( long long *arr,long long *temp, long long left, long long right)
{
    long long int inv_cnt= 0 ;
    long long int mid;
   if( right > left) {
        mid = left + (right-left)/2;
        inv_cnt += mergeSort(arr,temp,left,mid);
        inv_cnt += mergeSort(arr,temp,mid+1,right);
        inv_cnt += merge(arr,temp,left,mid+1,right);
        
   }
    return inv_cnt;
}
long long getInversions(long long *arr, int n){
    long long temp[n];
    long long int ans = mergeSort(arr,temp,0,n-1);
    return ans;
}
