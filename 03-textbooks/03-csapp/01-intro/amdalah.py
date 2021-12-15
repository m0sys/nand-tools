# Amdalah's Law formulation.

# S = 1 / ([1 - a] + a/k)

def amdalah(a, k):
    return 1 / ((1 - a) + a/k)


def amdalah_k(s, a):
    return a / (1/s - (1 - a))


# Runner
if __name__ == "__main__":
    print("Truck Speed Up: ", amdalah(1500/2500, 150/100))
    print("Truck Req K: ", amdalah_k(1.67, 1500/2500))
    print("Truck Speed Up: ", amdalah(1500/2500, 301.807/100))

    print("Car Req K: ", amdalah_k(4, 0.9))
