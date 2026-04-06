#include <iostream>
#include <string>
#include <stack> // We use the standard stack to cleanly hold operators
#include <cctype> // REQUIRED FOR isdigit() and isalpha()

using namespace std;

// -------------------------------------------------------------
// HELPER: Operator "Power Level" Tracker
// -------------------------------------------------------------
int power(char op) 
{
    // 1. Unary Operators (Logical NOT / Bitwise NOT) are Absolute Strongest!
    if (op == '!' || op == '~') return 7;
    // 2. Exponents (Standard Math)
    if (op == '^') return 6;
    // 3. Multiplication, Division, and Modulo (Remainder)
    if (op == '*' || op == '/' || op == '%') return 5;
    // 4. Addition and Subtraction
    if (op == '+' || op == '-') return 4;
    // 5. Relational Operators (Greater than, Less than, Equal)
    if (op == '>' || op == '<' || op == '=') return 3;
    // 6. Logical AND
    if (op == '&') return 2;
    // 7. Logical OR (Absolute Weakest)
    if (op == '|') return 1;
    
    // Everything else (like Brackets) are zero
    return 0; 
}

// -------------------------------------------------------------
// CORE ALGORITHM: Infix to Postfix (Pure Simplest Logic)
// -------------------------------------------------------------
void infixToPostfix(string s) 
{
    stack<char> st;

    // Loop through the text letter by letter
    for (int i = 0; i < s.length(); i++) 
    {
        char ch = s[i];

        // Skip any blank spaces so they don't break the rules
        if (ch == ' ') 
        continue;

        // RULE 1: If it's a Number or a Letter -> Just Print It!
        if (isdigit(ch) || isalpha(ch)) 
        {
            cout << ch << " ";
        }
        
        // RULE 2: If it's an Opening Bracket -> Hide it in the Stack!
        else if (ch == '(') 
        {
            st.push(ch);
        }
        
        // RULE 3: If it's a Closing Bracket -> Dump everything out untill you find the Opening Bracket!
        else if (ch == ')') 
        {
            while (!st.empty() && st.top() != '(') 
            {
                cout << st.top() << " ";
                st.pop();
            }
            st.pop(); // Trash the '(' bracket, we don't need it anymore!
        }
        
        // RULE 4: It MUST be an Operator (+, -, *, /)
        else 
        {
            // Fight! Anyone currently in the stack with MORE or EQUAL Power gets kicked out and printed!
            while (!st.empty() && power(st.top()) >= power(ch)) 
            {
                cout << st.top() << " ";
                st.pop();
            }
            // Now that the big guys are gone, you safely take your place in the stack!
            st.push(ch);
        }
    }

    // RULE 5: Once we reach the end of the text, dump anything still trapped inside the stack!
    while (!st.empty()) 
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main() 
{
    // Test 1: Standard Math
    cout << "Test 1:   A + B * C" << endl;
    cout << "Expected: A B C * +" << endl;
    cout << "Postfix:  "; 
    infixToPostfix("A + B * C"); 
    cout << "\n\n";

    // Test 2: Complicated Brackets
    cout << "Test 2:   (A + B) * (C - D)" << endl;
    cout << "Expected: A B + C D - *" << endl;
    cout << "Postfix:  "; 
    infixToPostfix("(A + B) * (C - D)"); 
    cout << "\n\n";
    
    return 0;
}
`