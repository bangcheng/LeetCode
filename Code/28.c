/*
28. Implement strStr()

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

*/
int strStr(char* haystack, char* needle) 
{
    int haystack_Len=strlen(haystack);
    int needle_Len=strlen(needle);
    if(haystack_Len==0&&needle_Len==0)
        return 0;
    int j=0;
    for(int i=0;i<haystack_Len;i++)
    // for(int i=0;i<haystack_Len - needle_Len + 1;i++)     //可优化  优化明显
    {
       for (j = 0; j < needle_Len; ++j)
       {
       		if (haystack[i+j]!=needle[j])
       			break;
       }
       if (j==needle_Len)
       		return i;
    }
    return -1;
}



int strStr(char* haystack, char* needle) {
    int n=strlen(needle);
    int i=strlen(haystack);
    if(i==0 && n!=0){
        return -1;
    }
    if(n==0){
        return 0;
    }
    for(int j=0;j<=i-n;++j){
        int q=0;
        int p=j;
        while(1){
            if(q==n){
                return p-n;
            }
            else if(haystack[p]!=needle[q]){
                break;
            }
            else{
                ++p;
                ++q;
            }
        }
    }
    return -1;
    
}