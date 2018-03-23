/*
So we want to quickly find out how often a word, i.e., 
a given string, occurs in a text. More formally: 
given the alphabet {'A', 'B', 'C', …, 'Z'} and two finite strings over that alphabet, 
a word W and a text T, count the number of occurrences of W in T. 
All the consecutive characters of W must exactly match consecutive characters of T. 
Occurrences may overlap.

Input:
The first line of the input file contains a single number: 
the number of test cases to follow. Each test case has the following format:

One line with the word W, a string over {'A', 'B', 'C', …, 'Z'}, with 1 ≤ |W| ≤ 10,000 (
here |W| denotes the length of the string W).
One line with the text T, a string over {'A', 'B', 'C', …, 'Z'}, with |W| ≤ |T| ≤ 1,000,000.
Output

For every test case in the input file, the output should contain a single number,
on a single line: the number of occurrences of the word W in the text T.

Sample Input

3
BAPC
BAPC
AZA
AZAZAZA
VERDI
AVERDXIVYERDIAN

Sample Output
1
3
0
*/
// 使用kmp算法，进行快速字符串匹配，每次匹配完，count++
// 算法时间复杂度O(n)
#include<stdio.h>
// 生成next数组 数组长度为strlen(str)
// next数组内的数据均与实际字符下标小于1
// 1代表从第一个开始匹配
void next_creat(int *next,int num,char *str){
	 next[0]=0;   //第一个匹配失败为目标字符串指针往后移一个
	 next[1]=1;   //第二个匹配失败从第一个重新开始匹配
	 for (int i = 1; i < num-1; ++i)
	 {
	 	int k=next[i];
	 	while(k!=0)
	 	{
	 		if(str[k-1]==str[i]||k==0)
		 	{
		 		i++;
		 		k++;
		 		next[i]=k;
		 	}
		 	else
		 		k=next[k-1];
	 	}
	 	if(k==0)
	 		next[i+1]=1;
	 }
}


// 把下标与next数组内的数据一一对应
void next_creat(int *next,int num,char *str){
	 next[0]=-1;   //第一个匹配失败为目标字符串指针往后移一个
	 next[1]=0;   //第二个匹配失败从第一个重新开始匹配
	 for (int i = 1; i < num-1;)
	 {
	 	int k=next[i];
	 	while(k!=-1)
	 	{
	 		if(k==-1||tr[k]==str[i])
		 	{
		 		i++;
		 		k++;
		 		next[i]=k;
		 	}
		 	else
		 		k=next[k];
	 	}
	 	// if(k==-1)
	 	// 	next[i+1]=0;
	 }
}

// 进行模式匹配  返回目标字符串中含有模式串的个数
// 算法时间复杂度为O(n)
int KMP(int *next,char *object,char *str ){
	int num=strlen(str);
	int i,j=0;
	int count=0;  //包含模式串的个数
	// 从开始遍历到结束
	for ( i = 0; i < strlen(object);)
	{
		if(j==-1)
		{
			i++;
			j=0;
		}
		if(object[i]==str[j])
		{
			i++;
			j++;
			if(j>num-1) count++;
		}
		else
			j=next[j];
	}
	return count;
}
int main()
{
	char str[20];
	int next[20];
	scanf("%s",str);
	next_creat(next,20,str);
	for (int i = 0; i < strlen(str); ++i)
		printf("%d\n", next[i]);
	return 0;
}