Using the reference by Cowgod on the Chip-8, here are the specifications as well as machine states and their correct CPP counterparts.

SPECIFICATIONS:
  MEMORY: 4096 bytes (0x000 -> 0xFFF)
    RESERVATIONS:
      INTERPRETER RESERVATION: 0x000 -> 0x200 
      CHIP-8 PROGRAMS: 0x200 OR 0x600(ETI 660)
      CHIP-8 PROGRAM/DATA SPACE: 0x200/0x600 -> 0xFFF(END OF RAM)
    REGISTERS:
      - 16 GENERAL PURPOSE 8-BIT REGISTERS(V0 -> VF)
      - 1 16-BIT I REGISTER(MEMORY ADDRESS STORAGE) 
      - VF REGISTER USED AS A FLAG
      - 2 SPECIAL PURPOSE 8-BIT REGISTERS(DELAY, SOUND)
      - X PSEUDO-REGISTERS(PC 16-BIT REGISTER + STACK POINTER 8-BIT REGISTER)
      - STACK (ARRAY OF 16 * 16-BIT VALUES)
    KEYBOARD:
      16-KEY HEX KEYPAD(1 -> F)
    DISPLAY:
      128x64PX MONOCHROME DISPLAY((0,0) , (127,0) , (0,63) , (127, 63))
    SPRITES:
      0 -> F
    TIMERS AND SOUND:
      CHIP-8 provides 2 timers, a delay timer and a sound timer. The delay timer is active whenever the delay timer register (DT) is non-zero. The sound timer is active whenever the sound timer register (ST) is non-zero. Both decrement one at a rate of 60Hz, when DT reaches 0, it deactivates. For ST as long as the value is greater then zero, the CHIP-8 buzzer will sound, when reaching zero, the timer deactivates.

    
