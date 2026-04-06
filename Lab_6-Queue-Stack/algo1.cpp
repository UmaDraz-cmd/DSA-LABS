#include<iostream>
#include<stack>
using namespace std;

// 1. Changed to accept and return 'int'. 
// We removed the -'0' and +'0' logic because we are now dealing with pure integers.
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

int fullyParan(string s)
{
    int i = 0;
    // 2. Upgraded stack to int to handle large intermediate results safely
    stack<int> st;
    int res;
    
    while(s[i] != '\0')
    {
        // Added a check to prevent reading past the end of the string
        while(s[i] != ')' && s[i] != '\0')
        {
            // 3. NEW: If we hit a number, parse all its digits before pushing
            if (isdigit(s[i])) 
            {
                int num = 0;
                while (isdigit(s[i])) 
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                st.push(num); 
            }
            else 
            {
                st.push(s[i]); // Pushes '(', '+', etc., as their ASCII integer values
                i++;
            }
        }                
        
        // This is your exact same pop and calculate logic
        if (s[i] == ')')
        {
            int val2 = st.top(); //second operand
            st.pop();
            int temp = st.top(); //operator 
            st.pop();
            int val1 = st.top();      //first operand
            st.pop();
            
            res = cal(val1, temp, val2); // Calculate the result of the sub-expression
            st.pop(); // pops the '(' 
            st.push(res); // Push the result back onto the stack
            
            i++; // Move past the ')'
        }
   }
   
   return st.top(); // Removed -'0' because the stack holds the final integer
}

int main()
{
//    Test multi-digit numbers
  
   
   // Test large intermediate calculations
   cout << "Result of ((9*9)*2): " << fullyParan("((9*9)*2)") << endl;

   return 0;
}