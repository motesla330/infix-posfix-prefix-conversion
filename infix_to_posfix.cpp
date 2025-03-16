#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<char> st;
string infix, postfix;

int pariority(char c)
{
    if(c == '^')
    {
        return 3;
    }
    else if(c == '*' || c == '/')
    {
        return 2;
    }
    else if(c == '+' || c == '-')
    {
        return 1;
    }
    else if(c == '(' || c == ')')
    {
        return 0;
    }
    else return -1;
}

int main()
{
    cout << "Enter the infix expression: ";
    cin >> infix;

    size_t n = infix.length();

    for (long long unsigned  i = 0; i < n; i++)
    {
        // if the character is an operand
        if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= '0' && infix[i] <= '9'))
        {
            if (i>0 && (infix[i-1] >= 'a' && infix[i-1] <= 'z') || (infix[i-1] >= 'A' && infix[i-1] <= 'Z') || (infix[i-1] >= '0' && infix[i-1] <= '9'))
            {
                postfix += infix[i]; // add it to the postfix expression
            }
            else
            {
                postfix += " ";
                postfix += infix[i]; // add it to the postfix expression
            }
            
          

        }
        else if(infix[i] == '(')
        {
            st.push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // pop the '(' from the stack
        }
        else
        {
            while(!st.empty() && pariority(st.top()) >= pariority(infix[i]))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }

    while(!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    cout << "The postfix expression is: " << postfix << endl;

    return 0;
}
