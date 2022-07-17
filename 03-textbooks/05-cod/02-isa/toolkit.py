from riscv_assembler.utils import *

tk = Toolkit()

def to_hex(bin_str):
    group = []
    hx = ""
    for i in range(len(instr)):
        hx += instr[i]
        if ((i+1) % 4 == 0 and i  != 0):
            group.append(hx)
            hx=""
    d = {
        '0000': '0',
        '0001': '1',
        '0010': '2',
        '0011': '3',
        '0100': '4',
        '0101': '5',
        '0110': '6',
        '0111': '7',
        '1000': '8',
        '1001': '9',
        '1010': 'A',
        '1011': 'B',
        '1100': 'C',
        '1101': 'D',
        '1110': 'E',
        '1111': 'F',
    }
    res = ""
    for elem in group:
        res+= d[elem]
        print(d[elem], end='')
    return res

# translate sd x5, 32(x30)
instr = tk.S_type("sd", "x5", "x30", "32")
print("sd x5, 32(x30)")
print(to_hex(instr))
print(instr)

# translate ld x3, 4(x27)
instr = tk.I_type("ld", "x3", "3", "x27")
print("\n\nld x3, 4(x27)")
print(to_hex(instr) + "\n")
print(tk.hex(instr))
print(instr)

