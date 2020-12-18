total = 0

for i in range(1, 1001):
    total += i ** i

asString = str(total)
print(asString[-10:])
