class Solution {
public:
    bool isValid(string s) {
        stack <char> check;
        int i;
        for (i = 0; i < s.length(); i++) {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[')
                check.push(s[i]);
            if (s[i] == '}' || s[i] == ')' || s[i] == ']') {
                if (check.empty() == true)
                    return false;
                else if (s[i] == '}' && check.top() != '{') 
                    return false;    
                else if (s[i] == ')' && check.top() != '(') 
                    return false;
                else if (s[i] == ']' && check.top() != '[') 
                    return false;
                check.pop();
            }
        }
        return check.empty();
    }
};
