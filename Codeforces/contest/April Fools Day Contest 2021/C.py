from sys import stdin, stdout

def solve(s):
  a = ord('A')
  for c in s:
    print("{0:b} ".format(ord(c)-a), end="")
  
  print()

def main():
  s = stdin.readline().strip()
  solve(s)

main()