// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

// Note:
// You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional
//  elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
void merge(int* nums1, int m, int* nums2, int n) {
    int nums[m];
    int i,j,k;
    for (i = 0; i < m; ++i)
    	nums[i]=nums1[i];
    i=0,j=0,k=0;
    while(i<m&&j<n)
    {
    	if(nums[i]>nums2[j])
    	{
    		nums1[k]=nums2[j];
    		k++;
    		j++;
    	}
    	else
    	{
    		nums1[k]=nums[i];
    		i++;
    		k++;
    	}
    }
    while(i<m)
    {
    	nums1[k]=nums[i];
		i++;
		k++;
    }
    while(j<n)
    {
    	nums1[k]=nums2[j];
		k++;
		j++;
    }
}



void merge(int* nums1, int m, int* nums2, int n) {
    
      int len1=m-1;
      int len2=n-1;
      int len3=m+n-1;
    
      while(len1>=0 && len2>=0)
      {
          if(nums1[len1]>nums2[len2])
            nums1[len3--]=nums1[len1--];
          else
            nums1[len3--]=nums2[len2--];
          
      }
    
       while(len1>=0) nums1[len3--]=nums1[len1--];
       while(len2>=0) nums1[len3--]=nums2[len2--];
          
}