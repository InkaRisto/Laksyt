import random


class Car:
    cars = 0

    def __init__(self, number, max_speed):
        self.register_num = number
        self.top = max_speed
        self.speed = 0
        self.driven = 0
        Car.cars += 1

    def print_data(self):
        print(f'Auton rekisterinumero on {self.register_num} ja huippunopeus on {self.top}. '
              f'Matkustettu {self.driven} km ja nopeus nyt on {self.speed} km/h.')

    def speed_up(self, change):
        if 0 < self.speed + change <= self.top:
            self.speed += change
        elif self.speed + change > self.top:
            self.speed = self.top
        elif self.speed + change < 0:
            self.speed = 0

    def drive(self, hours):
        self.driven += self.speed * hours


def print_result():
    for c in range(len(racers)):
        the_car = racers[c]
        the_car.print_data()


racers = []

for i in range(10):
    register = 'ABC-' + str(i+1)
    top_speed = random.randint(100, 200)
    racers.append(Car(register, top_speed))

finished = False
while not finished:
    move = 0
    for move in range(Car.cars):
        car = racers[move]
        if car.driven < 10000:
            speed_change = random.randint(-10, 15)
            car.speed_up(speed_change)
            car.drive(1)
            move += 1
        elif car.driven >= 10000:
            print_result()
            finished = True
            break

