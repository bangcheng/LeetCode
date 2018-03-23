/*
53. Maximum Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/
// 分治求解
// 把问题分解为数组[left,mid]与[mid+1,right],该最大子数组位于这两个数组中或包含了mid值
// 位于这两个数组这个问题，可以再分解为子问题
// 最后只比较上述三种情况的大小,选择最大的一个 
// 该算法的时间复杂度为0(nlogn)

// 求包含mid值的最大子数组数据
int mid_value(){
}

int maxSubArray(int* nums, int left,int right) {
    if(left==right)
    	return nums[left];
    else
    {
    	mid=(left+right)/2;
    	value1=maxSubArray(nums,left,mid);  //递归求解最左边情况
    	value2=maxSubArray(nums,mid+1,right); //递归求解右边情况
    	value3=mid_value(nums,mid);            //求解包含mid值的情况

    	// 比较三个value的值选择最大的那个数据复值给value
    }
    return value;
}

// 把问题描述为：已知一个数组array[i]内存放的是从nums[0]--nums[i]之间的最大子数组
// 那么nums[0]--nums[i+1]的最大子数组为array[i]或包含nums[i+1]的最大子数组
// 时间复杂度为o(n^2)
int maxSubArray(int* nums, int numsSize) {
	if(numsSize==0)
		return -2147483648;
    int array[numsSize];
    array[0]=nums[0];
    int max=-2147483648 ;
    int num=0;
    for (int i = 1; i < numsSize; ++i)
    {
    	for (int j = i; j >= 0; --j)
    	{
    		num+=nums[j];
    		if(num>max)
    			max=num;
    	}
    	if(max>array[i-1])
    		array[i]=max;
    	else
    		array[i]=array[i-1];
    	num=0;
    	max=-2147483648 ;
    }
    return array[numsSize-1];
}


// Kadane’s algorithm
// 时间复杂度为(n)
int maxSubArray(int* nums, int numsSize) {
    int b = 0, sum = nums[0];
    for(int i = 0; i < numsSize; i++) {
        if(b > 0) b += nums[i];
        else b = nums[i];
        if(b > sum) sum = b;
    }
    return sum;
}

// [-2,1,-3,4,-1,2,1,-5,4]
// 联想：如果数组是一个循环数组
// 思路：
// 情况分为两个：最大子数组范围包括-2，或不包括-2
// 先计算不横跨-2，在计算横跨-2的
int maxSubArray(int* nums, int numsSize) {

    int b = 0, sum = nums[0];
    
    for(int i = 0; i < numsSize; i++) {
        if(b > 0) b += nums[i];
        else b = nums[i];
        if(b > sum) sum = b;
    }

// 横跨端点值
    int sum1=0;
    int sum2=0;
    b=nums[numsSize-1];
    int i=numsSize-2;
    while(b>0)
    {
        if(b>sum1) sum1=b;  
        b+=nums[i];
        i--;
    }
    b=nums[0];
    i=1;
    while(b>0)
    {
        if(b>sum2) sum2=b;  
        b+=nums[i];
        i--;
    }

    if(sum<sum1+sum2) sum=sum1+sum2;
    return sum;
}