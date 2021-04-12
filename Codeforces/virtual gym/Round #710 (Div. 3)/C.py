from sys import stdin, stdout

def solve(a, b):
  ans = float('inf')
  subSetsA, subSetsB = [''], ['']

  for i in range(len(a)):
    for j in range(i+1, len(a)+1):
      subSetsA.append( a[i:j] )
  
  for i in range(len(b)):
    for j in range(i+1, len(b)+1):
      subSetsB.append( b[i:j] )
  
  for sA in subSetsA:
    for sB in subSetsB:
      if sA == sB:
        ans = min(ans, (len(a)-len(sA))+(len(b)-len(sB)) )
  
  stdout.write('{}\n'.format(ans))

def main():
  lines = stdin.readlines()
  i = 1
  while i < len(lines):
    a = lines[i].strip()
    i += 1
    b = lines[i].strip()
    i += 1
    solve(a, b)


main()