a, b = map(int, input().split())
cnt = 0
for i in range(2, b):
    if a % i == 0:
        print('BAD '+str(i))
        exit(0)
print('GOOD')
