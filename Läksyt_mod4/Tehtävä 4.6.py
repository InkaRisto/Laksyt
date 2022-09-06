import math
import random

N = int(input('Montako pistettä kokeillaan? '))
points = 0
inside = 0


while points <= N:
    x = random.uniform(-1, 1)
    y = random.uniform(-1, 1)

    if x**2 + y**2 < 1 <= 1:
        inside += 1

    points = points + 1

pi = 4 * inside / N

print(f' Piin likiarvo on: {pi}')
print(math.pi)

