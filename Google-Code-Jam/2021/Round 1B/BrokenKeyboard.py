from sys import stdin

const = 1e-10

def convert(ticks):
  global const
  return (ticks/12)*const

def solve(vals):
  ans = ""

  h = round(vals[0]/30)
  m = round((vals[1]/30)*5)
  s = round((vals[2]/30)*5)
  n = int((vals[2]/30*5)*1e9)

  print("{} {} {} {}".format(h, m, s, n))

def main():
  lines = stdin.readlines()

  i = 1

  while i < len(lines):
    print("Case #{}: ".format(i), end="")
    line = lines[i].strip().split()
    i += 1

    vals = list(map(int, line))

    minVal = min(vals)

    vals = list(map(lambda x: x-minVal, vals))
    vals.sort(reverse=True)

    vals = list(map(convert, vals))
    solve(vals)


main()