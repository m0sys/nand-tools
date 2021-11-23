# Date: 2021/11/2021
# Author: m0sys
# Even better than psedocode for asm is python! Who need paper?
r0 = 3
r1 = 1
counter = 0
res = 0

while (True):
    if (counter >= r0):
        break
    counter += 1
    res += r1
print("Res: ", res)
