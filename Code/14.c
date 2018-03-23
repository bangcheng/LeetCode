/*
14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
*/
char* longestCommonPrefix(char** strs, int strsSize) {
    char *re;
    if(strsSize==0)
    {
        re="";
        return re;
    }
    int longest=strlen(strs[0]);
    int i;
    for (i = 1; i < strsSize; ++i)
    {
    	int length=strlen(strs[i]);
    	if(length>longest)
    		length=longest;
        int j;

    	for (j = 0 ; j < length; ++j)
    	{
    		if (strs[0][j]!=strs[i][j])
    		{
    			break;
    		}
    	}
        longest=j;

    }

    re=(char*)malloc((longest)*(sizeof(char)));
    for (i = 0; i < longest; ++i)
    {
    	re[i]=strs[0][i];
    }
    re[i]='\0';
    return re;
}



//3S
char* longestCommonPrefix(char** strs, int strsSize) {
 
    bool done = false;
    int index = -1;
    char curChar;
    int numMatch = 0;
    int s, j;
    char *result;
    
    if (strs == NULL || strsSize == 0) {
        return "";
    }
    
    if (strsSize == 1) {
        done = true;
        index = strlen(strs[0]) + 1;
    }
    
    while (! done) {
        index++;
        // For each character in the array
        
        for (s = 0; s < strsSize; s++) {
            // For each string
            if (s == 0) {
                // First string
                curChar = strs[s][index];
                continue;
            }
            
            if (curChar != strs[s][index]) {
                done = true;
                break;
            }
        } // for

    } // while
    
    result = (char *) malloc(index);
    if (result == NULL) {
        return NULL;
    }
    
    for (j = 0; j < index; j++) {
        result[j] = strs[0][j];
    }
    result[j] = '\0';
    
    return result;

}