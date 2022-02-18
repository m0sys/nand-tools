def stackoverflow(i):
    ##if (i == 0):
    ##    return i
    i = stackoverflow(i-1);
    return i;

if __name__ == "__main__":
    stackoverflow(5)
