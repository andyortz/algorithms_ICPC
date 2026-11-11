"""
For problems that needs more decimal precisition

You can try this code but in C++, 
it will not pass in this problem https://cses.fi/problemset/task/1728/
"""
from decimal import *
getcontext().prec = 200 #The decimal precisition

n = int(input())
nums = [int(x) for x in input().split(" ")]

ans = Decimal(0)
for i in range(0,len(nums)):
    for j in range(i+1,len(nums)):
        for k in range(1,nums[j]+1):
            ans += max(0,nums[i]-k)/Decimal(nums[i]*nums[j])
            # Also for reduce getcontext().prec = 100
            # You can sum integer part, then apply the decimal division

print("{:.6f}".format(ans)) #The rounding half even to six decimals
