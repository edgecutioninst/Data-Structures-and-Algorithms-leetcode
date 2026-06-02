class Solution {
public:
    bool isValid(string s) {
        stack <char> st;

        for(int i = 0 ; i < s.size(); i++)
        {
            char c = s[i];

            if (c == '(' || c == '[' || c == '{')
            st.push(c);

            else if ( c == ')')
            {   
                if (st.empty()) return false;
                if (st.top() == '(') st.pop();
                else st.push(c);
            }

            else if ( c == ']')
            {
                if (st.empty()) return false;
                if (st.top() == '[') st.pop();
                else st.push(c);
            }

            else if ( c == '}')
            {   
                if (st.empty()) return false;
                if (st.top() == '{') st.pop();
                else st.push(c);
            }
        }
        return st.empty();
    }
};