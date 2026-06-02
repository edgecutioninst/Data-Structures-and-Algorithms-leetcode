class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(int i = 0; i < tokens.size(); i++)
        {
            string str = tokens[i]; 
            if (str == "+" || str == "-" || str == "*" || str == "/")
            {
                int num1 = s.top(); s.pop();
                int num2 = s.top(); s.pop();

                if (str == "+") s.push(num2 + num1);
                else if (str == "-") s.push(num2 - num1);
                else if (str == "*") s.push(num2 * num1);
                else if (str == "/") s.push(num2 / num1);   
            }
            else
                s.push(stoi(str));
        }
        return s.top();
    }
};