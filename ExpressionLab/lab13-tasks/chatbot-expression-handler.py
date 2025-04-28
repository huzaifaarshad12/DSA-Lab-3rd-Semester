def chatbot_response(query):
   expression = query.replace("What is ", "").strip("?")
   postfix = ExpressionEvaluator.infix_to_postfix(expression)
   result = ExpressionEvaluator.evaluate_postfix(postfix)
   return f"The result is {result}"

# Example
query = "What is (10+5)*2?"
response = chatbot_response(query)
print(response)