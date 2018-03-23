/*
Word Break


Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
determine if s can be segmented into a space-separated sequence of one or more dictionary words. 
You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/
char *strncpy(char *dest, char *src, int n);// 把src所指由NULL结束的字符串的前n个字节复制到dest所指的数组中


// 该问题可以转化为dp
// 假设第j的前面字符串已经可以分割，则判断从i到j是否可以分割
// 如果可以分割则代表第i+1之前都可以被字典单词分割

// 判断字符串s是否在字典wordDict里面
#include<stdio.h>
#include<limits.h>
#include<string.h>
// 比较两个字符串是否相等
int judge(char* s,char** wordDict, int wordDictSize)
{
	int k;
	for ( k = 0; k < wordDictSize; ++k)
		if(strcmp(s, wordDict[k])==0)  // strcmp如果相等，则返回0
			return 1;
	return 0;
}
int wordBreak(char* s, char** wordDict, int wordDictSize) {
    int s_len=strlen(s);
    if(s_len==0) return 0;

	int i, j;
    // 存放暂时比较数组
    char str[s_len+1];

    // dp存放到i之前能否被字典单词分割
    int dp[s_len+1];

    // 第一个应该为1
    for ( i = 0; i < s_len+1; ++i)
    	dp[i]=0;
    dp[0]=1;

    for ( i = 0; i < s_len; ++i)
    {
    	for( j=i ; j>=0 ;j--)
    	{
    		// dp数组比字符串长度大1
    		if(dp[j]==1)      //先判断前面是否可以分割，如果不可以该次判断没必要，直接跳过
    		{
    			strncpy(str, s+j, i+1-j);
    			str[i+1-j]='\0';            //需在后面加‘\0’，否则上次的字符串会影响这次的运行
    			if(judge(str,wordDict,wordDictSize)==1)
    			{
    				dp[i+1]=1;
    				break;
				}
			}  	
    	}
    }
    return dp[s_len];
}
int main()
{
	char *a="Leetcode";
	char* str[2]={"Leet","code"};   //需注意，不能用str[2][5]定义，这样str不是char**类型，会造成类型不匹配
	int i=wordBreak(a,str,2);
	printf("%d",i);
	return 0;
}