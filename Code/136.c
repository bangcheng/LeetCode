// Given an array of integers, every element appears twice except for one. Find that single one.
// 通过异或运算来实现
// 0^m=m
// m^m=0
int singleNumber(int* nums, int numsSize) {
    int num=0;
    for (int i = 0; i < numsSize; ++i)
    	num=num^nums[i];
    return num;
}