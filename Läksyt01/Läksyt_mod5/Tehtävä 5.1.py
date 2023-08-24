import random

dice = int(input('Montako noppaa heitetään? '))
rollsum = 0

for i in range (dice):
    roll = random.randint(1, 6)
    rollsum = rollsum + roll

print(f'Heittojen summa on: {rollsum}')
