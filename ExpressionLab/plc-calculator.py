variables = {'X': 10, 'Y': 5, 'Z': 2}

def evaluate_postfix_with_vars(expression, variables):
   stack = []
   for char in expression:
      if char.isalnum():
         stack.append(variables.get(char, int(char)))
      else:
         b = stack.pop()
         a = stack.pop()
         if char == '+':
            stack.append(a + b)
         elif char == '-':
            stack.append(a-b)
         elif char == '*':
            stack.append(a*b)
         elif char == '/':
            stack.append(a/b)
   return stack[0]

# Example
postfix_expr = "XY+Z*"
result = evaluate_postfix_with_vars(postfix_expr, variables)
print("Result:", result)