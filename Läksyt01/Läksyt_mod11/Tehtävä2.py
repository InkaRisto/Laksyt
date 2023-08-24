class Car:
    def __init__(self, number, max_speed):
        self.register_num = number
        self.top = max_speed
        self.speed = 0
        self.odometer = 0

    def speed_up(self, change):
        if 0 < self.speed + change <= self.top:
            self.speed += change
        elif self.speed + change > self.top:
            self.speed = self.top
        elif self.speed + change < 0:
            self.speed = 0

    def drive(self, hours):
        self.odometer += self.speed * hours

    def print_driven(self):
        print(f'Autolla {self.register_num} ajettu {self.odometer} kilometriä.')


class Electric(Car):
    def __init__(self, register, max_speed, kwh):
        super().__init__(register, max_speed)
        self.battery = kwh


class Petrol(Car):
    def __init__(self, register, max_speed, gas):
        super().__init__(register, max_speed)
        self.tank = gas


car1 = Electric('ABC-15', 180, 52.5)
car2 = Petrol('ACD-123', 165, 32.3)

car1.speed_up(60)
car2.speed_up(75)

car1.drive(3)
car2.drive(3)

car1.print_driven()
car2.print_driven()
