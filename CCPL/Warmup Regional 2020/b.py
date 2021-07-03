from sys import stdin, stdout


def main():
    lines = stdin.readlines()
    i = 0
    out = ""
    while i < len(lines):
        N = int(lines[i].strip())
        S = set()
        i += 1
        for j in range(N):
            s = lines[i].strip()
            i += 1

            s = s.split('@')
            s[0] = s[0].replace('.', '')

            pos = s[0].find('+')

            if pos != -1:
                s[0] = s[0][:pos]
            aux = '@'.join(s)

            S.add(aux)
        out += "{}\n".format(len(S))

    stdout.write(out)


main()
