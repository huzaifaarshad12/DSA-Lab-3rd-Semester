class Position:
    def __init__(self, name):
        self.name = name

    def __str__(self):
        return self.name


class Monkey:
    def __init__(self):
        self.position = None
        self.height = 0  # On the ground

    def move(self, position):
        self.position = position
        return f"Monkey moved to {position}"

    def climb_up(self, box):
        if self.position == box.position:
            self.height = box.height
            return "Monkey climbs the box"
        return "Monkey cannot climb the box; they are not at the same position"

    def take_banana(self, banana):
        if self.position == banana.position and self.height == banana.height:
            return "Monkey takes the banana"
        return "Monkey cannot reach the banana"


class Box:
    def __init__(self, position):
        self.position = position
        self.height = 2

    def move(self, position, monkey):
        if monkey.position == self.position and monkey.height == 0:
            self.position = position
            monkey.position = position
            return f"Monkey moves the box to {position}"
        return "Monkey cannot move the box"


class Banana:
    def __init__(self, position, height):
        self.position = position
        self.height = height


def main():
    # Define positions
    position_a = Position("Position A")
    position_b = Position("Position B")
    position_c = Position("Position C")

    # Initialize objects
    monkey = Monkey()
    box = Box(position_b)
    banana = Banana(position_c, 2)

    # Monkey starts at Position A
    print(monkey.move(position_a))

    # Monkey moves to the box
    print(monkey.move(box.position))

    # Monkey moves the box to the banana's position
    print(box.move(banana.position, monkey))

    # Monkey climbs the box
    print(monkey.climb_up(box))

    # Monkey takes the banana
    print(monkey.take_banana(banana))


if __name__ == "__main__":
    main()
