class stack:
    def __init__(self):
        self.data = list()

    def push(self, value):
        self.data.append(value)
        return self
    
    def pop(self, n = -1):
        self.data.pop(n)
        return self

    def print(self):
        for i in self.data:
            print(i)
        return self

tumpukan1 = stack()
tumpukan1.push(1).push(2).push(3).pop()
tumpukan1.print()
