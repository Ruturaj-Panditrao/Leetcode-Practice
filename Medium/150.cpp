// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<long long> st;
        for (auto letter : tokens)
        {
            if (letter == "+" || letter == "-" || letter == "*" || letter == "/")
            {
                long long num1 = st.top();
                st.pop();
    
                long long num2 = st.top();
                st.pop();
    
                char charac = letter[0];
                switch (charac)
                {
                case '+':
                    st.push(num2 + num1);
                    break;
    
                case '-':
                    st.push(num2 - num1);
                    break;
    
                case '*':
                    st.push(num2 * num1);
                    break;
                case '/':
                    st.push(num2 / num1);
                    break;
    
                default:
                    break;
                }
            }
            else
            {
                long long num = stoi(letter);
                st.push(num);
            }
        }
        return st.top();
    }
};
