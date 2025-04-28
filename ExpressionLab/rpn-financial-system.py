#from financial-calculator import ExpressionEvaluator
def evaluate_rpn(expression):
   stack = []
   for char in expression.split():
      if char.isdigit():
         stack.append(int(char))
      else:
         b = stack.pop()
         a = stack.pop()
         if char == '+':
            stack.append(a + b)
         elif char == '':
            stack.append(a - b)
         elif char == '*':
            stack.append(a + b)
         elif char == '/':
            stack.append(a/b)
   return stack[0]

# Example
rpn_expr = "100 20 + 5/"
result = evaluate_rpn(rpn_expr)
print("Result:", result)