class Node:
   def __init__(self, value):
      self.value = value
      self.left = None
      self.right = None
   
def prefix_to_tree(expression):
   stack = []
   for char in reversed (expression):
      if char.isalnum():
         stack.append(Node(char))
      else:
         node = Node(char)
         node.left = stack.pop()
         node.right = stack.pop()
         stack.append(node)
   return stack[0]

def inorder_traversal (node):
   if not node:
      return ""
   return f"({inorder_traversal (node.left)}{node.value} {inorder_traversal(node.right)})"

# Example
prefix_expr = "-+a*bc"
root = prefix_to_tree(prefix_expr)
print("Infix from Prefix Tree:", inorder_traversal (root))