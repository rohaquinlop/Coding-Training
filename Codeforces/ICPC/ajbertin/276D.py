#WA
from sys import stdin
from math import ceil, log2

def decimalToBinary(n):
	return bin(n).replace("0b", "")

def main():
    lines = stdin.readlines()

    k = 0
    while k < len(lines):
        a, b = map(int, lines[k].strip().split())
        k += 1
        r = decimalToBinary(b)
        nofill = decimalToBinary(a)
        l = nofill.zfill( len(r) )
        ans = ""
        r = list(r)
        l = list(l)
        # print(r)
        # print(l)
        for i in range( len(r) ):
            if i > 0:
                if r[i - 1] == "1" or r[i - 1] == "2" :
                    if r[i] == "0":
                        r[i] = "2"
            
            if r[i] == "2" and l[i] == "0":
                ans += "1"
            elif r[i] == "2" and l[i] == "1":
                ans += "1"
            else:
            
                if r[i] == "1" and l[i] == "0":
                    ans += "1"
                elif r[i] == "0" and l[i] == "1":
                    ans += "1"
                elif len(r) > len(nofill):
                    ans += "1"
                else:
                    ans += "0"
        # print(ans)
        print(int(ans, 2))
main()