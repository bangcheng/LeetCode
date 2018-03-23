1、Two Sum
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
暴力解决
int* twoSum(int* nums, int numsSize, int target) {
    int *solution=(int*)malloc(2*sizeof(int));
    int i=0;
    int j;
    for(;i<numsSize;i++)
    {
        for(j=i;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                solution[0]=i;
                solution[1]=j;
            }
        }
    }
    return solution;
}
使用散列表
思路：创建一个数组，把一个数据i对应的凑成target的数据放到数组[i]中
该思路有问题，如果i所需的数据为负数，不能放入数组中
int* twoSum(int* nums, int numsSize, int target) {
    int *solution=(int*)malloc(2*sizeof(int));
    int num[40];  //哈希表
    int i=0;
    for (i = 0; i < 40; ++i)
    {
    	num[i]=-1;
    }
    for(i=0;i<numsSize;i++)
    {
        if (num[nums[i]]==-1)
        {
        	if (target-nums[i]>=0)
        	{
    			num[target-nums[i]]=i;
        	}
        }
        else
        {
        	solution[0]=num[nums[i]+10];
        	solution[1]=i;
        	return solution;
        }
    }
    return solution;
}


///已过
typedef struct hash 
{
	int element;
	int id;
	struct hash *next;
}hash;
//
int match(hash *ar, int tar)
{
    hash *arr=ar;
	while(arr!=NULL)
	{
		if (arr->element==tar)
		{
			return arr->id;
		}
		arr=arr->next;
	}
	return -1;
}
void push(hash **arr,int num ,int ID ,int target)
{
	int i=abs(target-num)%100;
	hash *Ha=(hash*)malloc(sizeof(hash));
	Ha->element=target-num;
	Ha->id=ID;
	Ha->next=arr[i];
	arr[i]=Ha;
}
int* twoSum(int* nums, int numsSize, int target) {
	int *solution=(int*)malloc(2*sizeof(int));
	int max=100; //存放
	int i;
	hash **Ha;
	Ha=(hash**)malloc(max*sizeof(hash *));
	for (i = 0; i < max; ++i)
	{
		Ha[i]=NULL;
	}

	for (i = 0; i < numsSize; ++i)
	{
		int k=abs(nums[i])%100;
		int Bool=match(Ha[k] ,nums[i]);
		if (Bool==-1)
		{
			push(Ha,nums[i],i,target);
		}
		else
		{
			solution[0]=Bool;
        	solution[1]=i;
        	return solution;
		}
	}
	return solution;
}




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target) {  
    int min = 2147483647;  
    int i = 0;  
    for (i = 0; i < numsSize; i++) {  
        if (nums[i] < min)  
            min = nums[i];  
    }  
    int max = target - min;  
    int len = max - min + 1;   //确定hash长度  
    int *table = (int*)malloc(len*sizeof(int));  
    int *indice = (int*)malloc(2*sizeof(int));  
    for (i = 0; i < len; i++) {  
        table[i] = -1;         //hash初值  
    }  
    for (i = 0; i < numsSize; i++) {  
        if (nums[i]-min < len) {  
            if (table[target-nums[i]-min] != -1) {        //满足相加为target  
                indice[0] = table[target-nums[i] - min];  
                indice[1] = i;  
                return indice;  
            }  
            table[nums[i]-min] = i;  
        }  
    }  
    free(table);  
    return indice;  
}  