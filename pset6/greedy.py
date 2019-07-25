import cs50

class counter:
    def __init__(self, cents, count):
        self.cents = cents
        self.count = count
    
    def increment():
        counter.count += 1
        

def main():
    counter.count = 0
    while True:
        print("Price in dollars: ", end="")
        dollars = cs50.get_float()
        if dollars > 0:
            break
    
    counter.cents = round(dollars * 100)
    
    money(25)
    money(10)
    money(5)
    money(1)
    
    print(counter.count)
    
def money(n):
    while counter.cents >= n:
        counter.increment()
        counter.cents = counter.cents - n
    
if __name__ == "__main__":
    main()
