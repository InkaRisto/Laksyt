import math
import random

N = int(input('Montako pistettä kokeillaan? '))
points = 0
listed = []


while points <= N:
    points = points + 1
    x = random.randrange(-1, 1)
    y = random.randrange(-1, 1)

    xy = x, y
    test = x**2 + y**2 < 1

    if xy == test:
        listed.append(xy)

n = len(listed)
pi = 4 * n / N

print(pi)
print(math.pi)

