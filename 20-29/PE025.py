nums = [1, 1]

while len(str(nums[-1])) < 1000:
    nums.append(nums[-1] + nums[len(nums) - 2])

print(len(nums))
