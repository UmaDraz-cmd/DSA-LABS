#include<iostream>
#include<stack>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;
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

// In this task you are going to write a program to implement the algorithm (that we have seen in class) 
// for evaluating postfix expressions which involves the four basic arithmetic operators: +, –, *, and 
// /, and the unary minus operator (~ will be used to indicate the unary minus operator, in order to 
// distinguish it from the subtraction operator). 
algo for  evaluating postfix expressions which involves the four basic arithmetic operators: +, –, *, and /, and the unary minus operator (~ will be used to indicate the unary minus operator, in order to distinguish it from the subtraction operator).

// Since, this algorithm uses a stack; therefore, firstly you will have to implement a Stack class for 
// storing double values (during lecture we have already implemented a stack of integers). 
// Once, you have implemented the Stack class, you need to get the postfix expression from the user 
// and store it in a null-terminated char array (c-string). After that you would implement the following 
// function, which takes the postfix expression present in the null-terminated char array (input) and 
// evaluates it using the algorithm that we have discussed in the lecture: 
// void evaluatePostfixExpression ( char* input ) 
// To trace the actions of the algorithm, this function should also display each token as it is encountered, 
// and the actions (stack operations) that it is performing. For example, the output of your program 
// should resemble the following (text shown in Red is entered by the user): 
// Enter the postfix expression: 12 3 ~ 1 - / 4.6 ~ * 

 
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
    cout<<postfix("73+1-");
}

    

// Note that in the above example, input provided by the user actually correspon
ds to the following infix expression: 12 / (3 - 1) * (-4.6). 
// You can test your program with other postfix expressions as well.        
return 0;
}