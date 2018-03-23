// Majority Element
// Given an array of size n, find the majority element. 
// The majority element is the element that appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always exist in the array.
// 思路：为一个数据添加count值，如果下一个数据和该值相等，count++，如果不等，Count--，如果count等于0，即表示
// 该数据以前必不存在主元素，重新开始
// 初始化
// 如果
int majorityElement(int* nums, int numsSize) {
    int count[2];
    for (int i = 0; i < numsSize; ++i)
    {
    	if(count[1]==0) 
		{
			count[0]=nums[i];
			count[1]=1;
		}
    	else
    	{
    		if(count[0]==nums[i]) count[1]++;
    		else count[1]--;
    	}
    }
    return count[0];
}