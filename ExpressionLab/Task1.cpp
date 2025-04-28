#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

class ExpressionConverter
{
public:
    static int precedence(char op)
    {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        if (op == '^')
            return 3;
        return 0;
    }

    static bool isOperator(char c)
    {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }

    static bool isOperand(char c)
    {
        return isalnum(c);
    }

    static string infixToPostfix(const string &expression)
    {
        stack<char> stack;
        string postfix;

        for (char c : expression)
        {
            if (isOperand(c))
            {
                postfix += c;
            }
            else if (c == '(')
            {
                stack.push(c);
            }
            else if (c == ')')
            {
                while (!stack.empty() && stack.top() != '(')
                {
                    postfix += stack.top();
                    stack.pop();
                }
                stack.pop();
            }
            else if (isOperator(c))
            {
                while (!stack.empty() && precedence(stack.top()) >= precedence(c))
                {
                    postfix += stack.top();
                    stack.pop();
                }
                stack.push(c);
            }
        }

        while (!stack.empty())
        {
            postfix += stack.top();
            stack.pop();
        }

        return postfix;
    }

    static string infixToPrefix(const string &expression)
    {
        string reversedExpr = expression;
        reverse(reversedExpr.begin(), reversedExpr.end());

        for (char &c : reversedExpr)
        {
            if (c == '(')
                c = ')';
            else if (c == ')')
                c = '(';
        }

        string postfix = infixToPostfix(reversedExpr);

        reverse(postfix.begin(), postfix.end());
        return postfix;
    }

    static string postfixToInfix(const string &postfix)
    {
        stack<string> stack;

        for (char c : postfix)
        {
            if (isOperand(c))
            {
                stack.push(string(1, c));
            }
            else
            {

                string op1 = stack.top();
                stack.pop();
                string op2 = stack.top();
                stack.pop();
                string expr = "(" + op2 + c + op1 + ")";
                stack.push(expr);
            }
        }

        return stack.top();
    }

    static string prefixToInfix(const string &prefix)
    {
        stack<string> stack;

        for (auto it = prefix.rbegin(); it != prefix.rend(); ++it)
        {
            char c = *it;
            if (isOperand(c))
            {
                stack.push(string(1, c));
            }
            else
            {
                string op1 = stack.top();
                stack.pop();
                string op2 = stack.top();
                stack.pop();
                string expr = "(" + op1 + c + op2 + ")";
                stack.push(expr);
            }
        }

        return stack.top();
    }
};

int main()
{
    std::string expression = "(a+((b*(c+(d-e)))/f))*g";

    std::cout << "Infix Expression: " << expression << std::endl;

    // Convert to Postfix
    std::string postfix = ExpressionConverter::infixToPostfix(expression);
    std::cout << "Postfix Expression: " << postfix << std::endl;

    // Convert to Prefix
    std::string prefix = ExpressionConverter::infixToPrefix(expression);
    std::cout << "Prefix Expression: " << prefix << std::endl;

    // Convert back to Infix from Postfix
    std::cout << "Converted back to Infix from Postfix: "
              << ExpressionConverter::postfixToInfix(postfix) << std::endl;

    // Convert back to Infix from Prefix
    std::cout << "Converted back to Infix from Prefix: "
              << ExpressionConverter::prefixToInfix(prefix) << std::endl;

    return 0;
}
