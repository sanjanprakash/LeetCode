class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int i, ans = 0;
        int a, b;
        stack<int> nums;
        for (i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                b = nums.top();
                nums.pop();
                a = nums.top();
                nums.pop();
                if (tokens[i] == "+")
                    nums.push(a+b);
                else if (tokens[i] == "-")
                    nums.push(a-b);
                else if (tokens[i] == "*")
                    nums.push(a*b);
                else
                    nums.push(a/b);
            }
            else 
                  nums.push(stoi(tokens[i]));
        }
        return nums.top();
    }
};
