// LC150 Evaluate Reverse Polish notation
class Solution {
public:
    int Operation(const string& t)
    {
        if (t == "+") return 1;
        if (t == "-") return 2;
        if (t == "*") return 3;
        if (t == "/") return 4;
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for(auto &t : tokens)
        {
            int op = Operation(t);
            if(!op)
            {
                numbers.push(stoi(t));
            } 
            else
            {
                int num1 = numbers.top();
                numbers.pop();
                int num2 = numbers.top();
                numbers.pop();
                int res = 0;
                if(op == 1)
                {
                    res = num2+num1;
                }
                else if (op == 2)
                {
                   res = num2-num1;
                }
                else if (op == 3)
                {
                    res = num2*num1;
                }
                else
                {
                    res=num2/num1;
                }
                numbers.push(res);
            }
        }
        return numbers.top();
    }
};
