import time


def reverseNum(n):
    backString = ''.join(reversed(str(n)))
    return int(backString)


def isPalindrone(n):
    string = str(n)

    for i in range(int(len(string) / 2)):
        if string[i] != string[len(string) - i - 1]:
            return False

    return True


def isLychrel(n):
    i = 0
    while True:
        i += 1
        if i == 50:
            return True
        n = n + reverseNum(n)
        if isPalindrone(n):
            return False


ans = [isLychrel(i) for i in range(10000)]
print(sum(ans))
