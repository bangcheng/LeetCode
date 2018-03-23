/*
20. Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
"({[]})" return true;
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
bool isValid(char* s) {
    int n=strlen(s);
    char Fifo[n];
    int top=0;    //栈顶索引
    for (int i = 0; i < n; ++i)
    {
    	if (s[i]=='('||s[i]=='{'||s[i]=='[')
    	{
    		Fifo[top++]=s[i];
    	}
    	else
    	{
    		if(top==0)
    			return false;
    		switch(s[i])
    		{
    			case ')':
    				if (Fifo[top-1]!='(')
    					return false;
    				else
    					top--;
    				break;
    			case '}':
    			if (Fifo[top-1]!='{')
    					return false;
    				else
    					top--;
    				break;
    			case ']':
    			if (Fifo[top-1]!='[')
    					return false;
    				else
    					top--;
    				break;
    		}//switch
    	}//else
    }//for
    if(top==0)
    	return true;
    else
    	return false;
}




// 优
bool isValid(char* s) {
    int num_open = 0;
    int i = 0;
    
    while(s[i] != 0){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            s[num_open] = s[i];
            num_open++;
        } else if(s[i] == ')'){
            if(num_open == 0 || s[num_open-1] != '('){
                return(false);
            }
            num_open--;
        } else if (s[i] == ']'){
            if(num_open == 0 || s[num_open-1] != '['){
                return(false);
            }
            num_open--;
        } else if (s[i] == '}'){
            if(num_open == 0 || s[num_open-1] != '{'){
                return(false);
            }
            num_open--;
        }
        i++;
    }
    if(num_open > 0){
        return(false);
    }
    return(true);
        
    
}