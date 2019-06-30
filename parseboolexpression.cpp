class Solution {
public:
    int findEnd(int start, string exp) {
        int j = start, open = 0;
        bool first = true;
        while (j < exp.length() && (open || first)) {
            if (exp[j] == '(')
                open++;
            else if (exp[j] == ')')
                open--;
            first = false;
            j++;
        }
        return j;
    }
    
    bool and_gate(string exp) {
        int i, j;
        int start;
        bool res;
        for (i = 0; i < exp.length(); i++) {
            if (exp[i] == ',' || exp[i] == 't')
                continue;
            else if (exp[i] == 'f')
                return false;
            else {
                start = i+1;
                j = findEnd(start,exp);
                if (exp[start-1] == '&')
                    res = and_gate(exp.substr(start+1,j-start-2));
                else if (exp[start-1] == '|')
                    res = or_gate(exp.substr(start+1,j-start-2));
                else
                    res = !parseBoolExpr(exp.substr(start+1,j-start-2));
                if (!res)
                    return false;
                i = j;
            }
        }
        return true;
    }
    
    bool or_gate(string exp) {
        int i, j;
        int start;
        bool res;
        for (i = 0; i < exp.length(); i++) {
            if (exp[i] == ',' || exp[i] == 'f')
                continue;
            else if (exp[i] == 't')
                return true;
            else {
                start = i+1;
                j = findEnd(start,exp);
                if (exp[start-1] == '&')
                    res = and_gate(exp.substr(start+1,j-start-2));
                else if (exp[start-1] == '|')
                    res = or_gate(exp.substr(start+1,j-start-2));
                else
                    res = !parseBoolExpr(exp.substr(start+1,j-start-2));
                if (res)
                    return true;
                i = j;
            }
        }
        return false;
    }
    
    bool parseBoolExpr(string expression) {
        int i, j;
        bool first = true;
        if (expression == "t" || expression == "(t)")
            return true;
        else if (expression == "f" || expression == "(f)")
            return false;
        if (expression[0] == '!') {
            j = findEnd(1,expression);
            return !parseBoolExpr(expression.substr(2,j-3));
        }
        else if (expression[0] == '&') {
            j = findEnd(1,expression);
            return and_gate(expression.substr(2,j-3));
        }
        else {
            j = findEnd(1,expression);
            return or_gate(expression.substr(2,j-3));
        }        
    }
};
