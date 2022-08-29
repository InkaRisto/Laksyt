# Ohjelma tulostaa kaikki 3:lla jaolliset luvut väliltä 1...1000

value = 1

while 0 < value < 1001:
    if value % 3 == 0:
        print(value)

    value = value + 1
