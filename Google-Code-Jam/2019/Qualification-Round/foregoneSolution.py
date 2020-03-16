from sys import stdin

def main():
  lines = stdin.readlines()
  i = 1
  out = ""
  while i < len(lines):
    num = lines[i].strip()
    a, b = [], []
    j = len(num)-1
    k = 1

    while j >= 0:
      n = num[j]
      j -= 1
      if n == '4':
        a.append( [2, k] )
        b.append( [2, k] )
      else:
        if len(a) > len(b):
          b.append( [int(n), k] )
        else:
          a.append( [int(n), k] )
      k *= 10
    
    resA = 0
    resB = 0
    
    for x in a:
      resA += x[0]*x[1]
    
    for x in b:
      resB += x[0]*x[1]
    
    out += "Case #" + str(i) + ": " + str(resA) + " " + str(resB) + "\n"
    i += 1
  
  print(out.strip())


main()