// VMTranslator translates stack based code into Hack assembly code.
// Date: 2021/11/29
// Author: m0sys

#pragma once

/*
 * Memory Segments Mapping:
 *  The following is a brief specification of how to map Hack symbols onto RAM:
 *
 *  (SP):
 *      - address to one after the last value popped onto the stack.
 *
 *  local(LCP), argument(ARG), this(THIS), that(THAT):
 *      - push/pop [segment] i -> asm which accesses [segment_base] + i; where
 *                              [segment_base] = RAM[LCP/ARG/THIS/THAT].
 *      - LCP  -> RAM[1]
 *      - ARG  -> RAM[2]
 *      - THIS -> RAM[3]
 *      - THAT -> RAM[4]
 *      - TEMP -> RAM[5-12]
 *
 *  pointer(THIS/THAT):
 *      - push/pop pointer [0|1] acccesses RAM[3|4] respectively.
 *
 *  temp(TEMP):
 *      - push/pop temp [0-7] accesses RAM[5+i] where i = range [0, 7].
 *
 *  static:
 *      - push/pop static i -> ProgName.i symb in asm
 *      - static variables are mapped to addresses 16 to 255.
 */

class VMTranslator {
};
