# Date: 2021/11/2021
# Author: m0sys

# NOTE: requires root install of keyboard.
import keyboard

while True:
    if keyboard.read_key() != "":
        print("Black Screen")
    else:
        print("White Screen")

