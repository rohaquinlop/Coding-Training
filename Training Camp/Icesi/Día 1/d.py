from sys import stdin

def f(n, m):
  res = 0
  acucm = n

  while( n >= 8 and n%8 == 0):
    n/=8
    res += 1
    acucm *= 8
  
  while( n >= 4 and n%4 == 0):
    n /= 4
    res+= 1
    acucm *= 4
  
  while( n >= 2 and n%2 == 0):
    n /= 2
    res += 1
    acucm *= 2
  
  if acucm == m:
    return res
  else:
    return -1

def main():
  lines = stdin.readlines()
  out = ""

  for i in range(1, len(lines)):
    line = list(map(int, lines[i].strip().split()))
    n, m = max(line[0], line[1]), min(line[0], line[1])

    if n == m:
      out += "0\n"
    else:
      if (n/m)%2 == 0:
        out += str(f(n/m, n)) + "\n"
      else:
        out += "-1\n"
  
  print(out.strip())

main()