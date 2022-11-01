class Lift:
    def __init__(self, bottom, top):
        self.bottom_floor = bottom
        self.top_floor = top
        self.target = 0
        self.at = 0

    def floor_up(self):
        self.at = self.at + 1

    def floor_down(self):
        self.at = self.at - 1

    def move_floors(self, floor):
        while self.at != floor:
            if self.at > floor:
                Lift.floor_down(self)
            elif self.at < floor:
                Lift.floor_up(self)

            if floor != self.at:
                print(f'Hissi kerroksessa {self.at}')

        if self.at == self.target:
            print(f'Olet perillä! Kerros: {floor}.')


class Building:
    def __init__(self, bottom, top, many_lifts):
        self.bottom_floor = bottom
        self.top_floor = top
        self.lifts = []
        for i in range(many_lifts):
            list_lift = Lift(bottom, top)
            self.lifts.append(list_lift)

    def move_lift(self, index, floor):
        the_lift = self.lifts[index-1]
        print(f'Hissi {index} liikkuu:')
        the_lift.move_floors(floor)

    def fire_alarm(self):
        for i in range(len(self.lifts)):
            build_a.move_lift(i+1, 0)


build_a = Building(1, 7, 2)
build_b = Building(0, 4, 1)

build_a.move_lift(2, 7)
build_b.move_lift(1, 4)
build_a.fire_alarm()

