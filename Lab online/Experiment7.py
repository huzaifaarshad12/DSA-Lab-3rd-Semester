class Tower:
    def __init__(self):
        self.terminate = 1

    def printMove(self, source, destination):
        print(f"Move disk from {source} to {destination}")

    def move(self, disc, source, destination, auxiliary):
        if disc == self.terminate:
            self.printMove(source, destination)
        else:
            self.move(disc - 1, source, auxiliary, destination)
            self.move(1, source, destination, auxiliary)
            self.move(disc - 1, auxiliary, destination, source)

def main():
    n = int(input("Enter the number of disks: "))
    print("\nSequence of moves:")
    tower = Tower()
    tower.move(n, 'A', 'C', 'B')

if __name__ == "__main__":
    main()

#Enter the number of disks: 3
#Sequence of moves:
#Move disk from A to C
#Move disk from A to B
#Move disk from C to B
#Move disk from A to C
#Move disk from B to A
#Move disk from B to C
#Move disk from A to C
