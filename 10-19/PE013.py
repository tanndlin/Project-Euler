data = open('10-19\\PE013 Data.txt').read().split('\n')
sum = sum([int(i) for i in data])
print(str(sum)[0:10])
