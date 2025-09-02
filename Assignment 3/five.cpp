#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return -1;
}

bool isRightAssociative(char op)
{
    return (op == '^');
}

string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix = "";

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && st.top() != '(')
            {
                char topOp = st.top();

                if (precedence(topOp) > precedence(ch))
                {
                    postfix += topOp;
                    st.pop();
                }
                else if (precedence(topOp) == precedence(ch) && !isRightAssociative(ch))
                {
                    postfix += topOp;
                    st.pop();
                }
                else
                {
                    break;
                }
            }

            st.push(ch);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
