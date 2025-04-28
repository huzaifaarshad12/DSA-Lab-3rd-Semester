from financial_calculator import ExpressionEvaluator
def logical_to_postfix(expression):
   return ExpressionEvaluator.infix_to_postfix(expression)

# Example
query = "(a AND b) OR c"
postfix_query = logical_to_postfix(query.replace("AND", "&").replace("OR", "|"))
print("Postfix Logical Query:", postfix_query)