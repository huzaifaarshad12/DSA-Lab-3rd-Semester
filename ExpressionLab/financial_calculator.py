class ExpressionEvaluator:
   precedence = {'+': 1, '-': 1, '*': 2, '/': 2, '^': 3}

   @staticmethod
   def is_operator(c):
      return c in '+-*/'

   @staticmethod
   def infix_to_postfix(expression):
      stack = []
      postfix = []
      for char in expression:
         if char.isalnum():
            postfix.append(char)
         elif char == '(':
            stack.append(char)
         elif char == ')':
            while stack and stack[-1] != '(':
               postfix.append(stack.pop())
            stack.pop()
         else:
            while stack and stack[-1] != '(' and ExpressionEvaluator.precedence[char] <= ExpressionEvaluator.precedence.get(stack[-1], 0):
               postfix.append(stack.pop())
            stack.append(char)
      while stack:
         postfix.append(stack.pop())
      return ''.join(postfix)

   @staticmethod
   def evaluate_postfix(expression):
      stack = []
      for char in expression:
         if char.isdigit():
            stack.append(int(char))
         else:
            b = stack.pop()
            a = stack.pop()
            if char == '+':
               stack.append(a + b)
            elif char == '-':
               stack.append(a - b)
            elif char == '*':
               stack.append(a* b)
            elif char == '/':
               stack.append(a/b)
      return stack[0]


# Example
infix_expr = "(5+3)*(2-1)"
postfix_expr = ExpressionEvaluator.infix_to_postfix(infix_expr)
result = ExpressionEvaluator.evaluate_postfix(postfix_expr)
print("Postfix:", postfix_expr, "| Result:", result)