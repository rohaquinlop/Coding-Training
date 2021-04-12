from sys import stdin, stdout
from math import ceil, sqrt

def main():
  lines = stdin.readlines()
  for line in lines:
    a = int(line.strip())

    root = int(ceil(sqrt(a)))

    stdout.write('{}\n'.format(root))

main()