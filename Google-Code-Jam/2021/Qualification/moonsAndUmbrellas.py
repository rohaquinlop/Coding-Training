from sys import stdin

def solve(x, y, S):
  if S.count("?") == 0:
    return x*S.count("CJ") + y*S.count("JC")
  else:
    auxStart, auxEnd = 0, len(S)-1
    for i in range(len(S)):
      if S[i] != '?':
        break
      auxStart += 1
    
    for i in range(len(S)-1, -1, -1):
      if S[i] != '?':
        break
      auxEnd -= 1
    
    if auxEnd <= auxStart:
      return 0
    else:
      S = S[auxStart:auxEnd+1]

      for i in range(len(S)):
        if S[i] == '?':
            S = S[:i] + S[i-1] + S[i+1:]
      
      return x*S.count("CJ") + y*S.count("JC")

def main():
  t = int(stdin.readline().strip())
  case = 0
  out = ""
  while t > 0:
    t -= 1
    case += 1

    line = stdin.readline().strip().split()
    x, y, S = int(line[0]), int(line[1]), line[2]

    ans = solve(x, y, S)

    out += "Case #{}: {}\n".format(case, ans)
  print(out, end="")

main()