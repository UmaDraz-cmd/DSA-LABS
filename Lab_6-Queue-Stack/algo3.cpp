#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<stack>
using namespace std;
int precedence(char a)
{
     if(a=='~' || a=='!')
    {
        return 8;
    }
    else if(a=='*' || a=='/' || a=='%')
    {
        return 7;
    }
    else if(a=='+' || a=='-')
    {
        return 6;
    }
    // else if(a=='(')
    // {
    //     return 0;
    // }
    return 0;
}
void infixTopPostfix(char* arr)
{
    stack<char>st;
    char* token=strtok(arr," ");
    while(token!=nullptr)
    {
        
        if(isdigit(*token))
        {
            cout<<token<<" ";
        }
        else if(st.empty())
        {
            st.push(*token);
        }
        else if(*token==')')
        {
            while(st.top()!='(')
            {
                cout<<st.top()<<" ";
                st.pop();
            }
            st.pop();
        }
        else if(*token=='(')
        {
            st.push(*token);
        }
        else
        {
            
            while(!st.empty() && precedence(st.top())>=precedence(*token))
            {
            char temp=st.top();
            st.pop();
            cout<<temp<<" ";
            }
            st.push(*token);
            
        }
        token=strtok(0," ");
    }
    while(!st.empty())
    {
      cout<<st.top()<<" ";
      st.pop();
    }
}
int main()
{
    char temp[100];
    cout<<"Enter input:";
    cin.getline(temp,100);
    infixTopPostfix(temp);
    
}