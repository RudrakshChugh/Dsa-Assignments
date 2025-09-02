#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int evaluatePostfix(string expr) {
    stack<int> st;

    for (char ch : expr) {
        if (isdigit(ch)) {
            st.push(ch - '0');  
        }
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (ch) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': st.push(pow(val1, val2)); break;
                default: cout << "Invalid operator: " << ch << endl; return -1;
            }
        }
    }
    return st.top();
}

int main() {
    string expr;
    cout << "Enter Postfix Expression";
    cin >> expr;

    cout << "Result = " << evaluatePostfix(expr) << endl;

    return 0;
}
