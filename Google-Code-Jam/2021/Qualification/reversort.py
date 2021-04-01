from sys import stdin

def reverse(L, i, j):
  mid = L[i:j+1]
  mid.reverse()
  L = L[:i] + mid + L[j+1:]
  return L

def main():
  t = int(stdin.readline().strip())
  out = ""
  case = 0
  while t > 0:
    t -= 1
    case += 1
    n = int(stdin.readline().strip())
    L = list(map(int, stdin.readline().strip().split()))

    ans = 0

    for i in range(len(L)):
      minVal = min(L[i::])
      j = [k for k in range(len(L)) if L[k] == minVal][-1]
      ans += (j-i)+1
      L = reverse(L, i, j)

    out += "Case #{}: {}\n".format(case, ans-1)
  print(out, end="")

main()