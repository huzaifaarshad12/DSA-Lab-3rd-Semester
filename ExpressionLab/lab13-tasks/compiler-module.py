
def infix_to_prefix(expression):
   # Reverse the expression and swap parentheses
   reversed_expr = expression[::-1]
   reversed_expr = reversed_expr.replace('(', ')temp').replace(')', '(').replace('temp', ')')
   postfix = ExpressionEvaluator.infix_to_postfix(reversed_expr)
   return postfix[::-1]

# Example
infix_expr = "(a+b)*c"
prefix_expr = infix_to_prefix(infix_expr)
print("Prefix:", prefix_expr)