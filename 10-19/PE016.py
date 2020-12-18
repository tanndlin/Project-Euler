# Sum of the digits in 2^1000

bigBoyNumber = 2 ** 1000
numAsString = str(bigBoyNumber)

print(sum([int(i) for i in numAsString]))
