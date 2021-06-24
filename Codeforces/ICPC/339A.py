# Accepted
from sys import stdin, stdout


def main():
    lines = stdin.readlines()
    out = ""
    for line in lines:
        nums = list(map(int, line.strip().split('+')))
        nums.sort()
        nums = list(map(str, nums))
        string = "+".join(nums)
        out += "{}\n".format(string)
    stdout.write(out)


main()
