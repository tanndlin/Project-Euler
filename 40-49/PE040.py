bigNum = '1'
index = 2
while len(bigNum) < 1000000:
    bigNum += str(index)
    index += 1

# ans = d_1 * d_10 * d_100 * ... * d_1000000
ans = 1
for i in range(7):
    print(10 ** i)
    ans *= int(bigNum[10 ** i-1])

print(ans)
