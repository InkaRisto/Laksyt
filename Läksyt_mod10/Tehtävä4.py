import random


class Car:
    def __init__(self, number, max_speed):
        self.register_num = number
        self.top = max_speed
        self.speed = 0
        self.driven = 0

    def speed_up(self, change):
        if 0 < self.speed + change <= self.top:
            self.speed += change
        elif self.speed + change > self.top:
            self.speed = self.top
        elif self.speed + change < 0:
            self.speed = 0

    def drive(self, hours):
        self.driven += self.speed * hours


class Race:
    def __init__(self, name, kms, car_list):
        self.name = name
        self.length = kms
        self.racers = car_list

    def one_hour(self):
        Car.speed_up(random.randint(-10, 15))
        Car.drive(1)
        #^^^ Vaatii lisää parametrejä???? Kaataa koko ohjelman.

    def print_current(self):
        for c in self.racers:
            the_car = racers[c]
            print(f'Auton rekisterinumero on {the_car.register_num} ja huippunopeus on {the_car.top}. '
               f'Matkustettu {the_car.driven} km ja nopeus nyt on {the_car.speed} km/h.')

    def race_over(self):
        for car in racers:
            if car.driven > self.length:
                Race.print_current(self)
                return True


racers = []
for i in range(10):
    register = 'ABC-' + str(i+1)
    top_speed = random.randint(100, 200)
    racers.append(Car(register, top_speed))

rally = Race('Suuri romuralli', 8000, racers)

finished = False
while not finished:
    for r in racers:
        rally.one_hour()
        rally.race_over()

