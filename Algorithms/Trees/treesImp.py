"""
Sea T un árbol, T será representado de la siguiente manera:
T = []
T = [Node, leftT, rightT]

Example:
T = [1, [2, [], []], [3, [], []]]

"""

def preorder(T):
  if T != []:
    print(T[0])
    preorder(T[1])
    preorder(T[2])

def inorder(T):
  if T != []:
    inorder(T[1])
    print(T[0])
    inorder(T[2])

def postorder(T):
  if T != []:
    postorder(T[1])
    postorder(T[2])
    print(T[0])

farest = (int(), float("-inf"))

def getDiameter(t):
  ## This dfs return the farest node
  u = dfs(t, 0)
  ## This dfs return the farest node since the u node

def main():
  T = []

main()