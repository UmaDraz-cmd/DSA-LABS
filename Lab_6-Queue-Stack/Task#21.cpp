#include<iostream>
#include<stack>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
//these are the operators which would be returned to the functions called in postfix programm logic
int cal(int val1, int temp, int val2)
{
    if(temp == '+')
    {
        return val1 + val2;
    }
    else if(temp == '-')
    {
        return val1 - val2;
    }
    else if(temp == '*')
    {
        return val1 * val2;
    }
    else 
    {
        return val1 / val2;
    }
}
//this is the code part of postfix function which recieves operators indirectly and it's call directly from  the 
// operators functionn defined above 
int postfix(string s)
{
    int i=0;
    stack<int>st;
    char res;
    while(s[i]!='\0')
    {
        while(s[i]!='+'  && s[i]!='-' && s[i]!='/' && s[i]!='*')
        {
        st.push(s[i]-'0');
        i++;
        }
        int temp=s[i];
        i++;
        int val2=st.top();  //7
        st.pop();
        int val1=st.top(); //3
        st.pop();
        st.push(cal(val1,temp,val2));    
    }
    return st.top();
    
}


 
// Token = 12  Push 12 
// Token = 3  Push 3 
// Token = ~  Pop 3  Push -3 
// Token = 1  Push 1 
// Token = -  Pop 1  Pop -3 Push -4 
// Token = /  Pop -4 Pop 12 Push -3 
// Token = 4.6  Push 4.6 
// Token = ~  Pop 4.6 Push -4.6 
// Token = *  Pop -4.6 Pop -3 Push 13.8 
// End of input 
 
// Answer = 13.8 

int main()
{
    int a,b;
 //using referernce variables to access the pushed data  over the stack to get the real understanding of the object orienkted model of the system    
    cout<<postfix("73+1-");
    //here the function call invoked after the precision point has been decided to get the right point to point understanding 
}

    

// Note that in the above example, input provided by the user actually correspon
ds to the following infix expression: 12 / (3 - 1) * (-4.6). 
// You can test your program with other postfix expressions as well.        
return 0;
}