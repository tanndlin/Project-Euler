def factorial(num):
    if num == 1:
        return 1
    return num * factorial(num - 1)


bigNumber = factorial(100)
numAsString = str(bigNumber)

print(sum([int(i) for i in numAsString]))
