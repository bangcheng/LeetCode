/*35. Search Insert Position

Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/
// 二分结束后，倒数第二步肯定是i=j，然后再比较，最后插入位置一定是i
int searchInsert(int* nums, int numsSize, int target) {
    int i=0;
    int j=numsSize-1;
    while(i<=j)
    {
    	if (nums[(i+j)/2]>target)
    		i=(i+j)/2;
    	else if (nums[(i+j)/2]>target)
    		j=(i+j)/2;
    	else 
    		return (i+j)/2;
    }
    return i;
}