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

int main()
{
    cout<<postfix("73+1-");
}
