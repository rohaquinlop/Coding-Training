from sys import stdin, stdout

def main():
  lines = stdin.readlines()
  ans = 0
  accum = 0
  
  for i in range(1, len(lines)):
    line = lines[i].strip()
    line = line.replace('$', '')
    
    line = line.split('.')
    
    Y = line[1]
    
    accum += int(Y)
    
    accum %= 100
    
    if i != 1 and accum != 0:
      ans += 1
  print(ans)

main()