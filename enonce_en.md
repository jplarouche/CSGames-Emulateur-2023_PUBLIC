# The Atlantis Prophecy
Few people know it, but some great inventions of computing and mathematics were actually imagined and realized by the ancient civilization of Atlantis, a very long time ago. For example, the modern world actually owes the abacus, the electromechanical relay, and the transistor to the people of Atlantis.

The mythical CPU 6502, used in particular in the Apple II, the Commodore 64 and the Nintendo Entertainment System, was also developed by the people of Atlantis, and is considered one of their greatest technological achievements.

It is therefore not surprising that this technology was chosen when the time came for them to develop an encryption solution to protect their most important prophecy, the famous prophecy of Atlantis.

Indeed, research has made it possible to get hold of the binary image of a program developed for a 6502 architecture, which, if provided with the correct encryption key, will reveal the famous prophecy of Atlantis as well as the name of the sage who is its messenger.

## Summary

The Universities Committee wants to preserve the history of the ancient civilization of Atlantis. To do this, they asks your team to decipher the message of the prophecy. Then, they ask you to understand how the mythical 6502 processor works to keep knowledge and to be able to transmit it to future software engineers who will be trained in the great universities of our new civilization.

## Technical informations

**You must use the *C language***

### 6502 Emulator Details
- The system has 64kB (65536 bytes) of RAM;
- You must provide the emulator (therefore implement) 2 functions, *read6502* and *write6502* which will be called by the latter to read or write to memory;

### Details about the mysterious binary:
- The encryption key is a 3-character string containing numbers only. So there are 10^3 ("000" - "999") possible keys;
- The encryption key must be placed at address 0x200 before executing the binary. The key will therefore occupy cells 0x200, 0x201, 0x202;
- For each execution, the binary will make 48 writes to the memory address 0xFFF1 once the decryption is complete. If the key is correct, the prophecy will be revealed as well. If the key is bad, the '#' character will be written 48 times to the address mentioned. Note: The prophecy does not contain the '#' character;

## Tasks

### Get the 6502 emulator working
- Use the provided library (20 points)
- Implement proper memory management in your program (100 points)
- Create the *read6502* function (30 points)
- Create the *write6502* function (100 points)
- Your program must copy the binary into memory before execution (50 points)

### Find the encryption key and reveal the prophecy
- Implement a *brute force* method (250 points)
- Proper use of the memory address (50 points)
- Find the correct encryption key and message (200 points)

### Understand how the mythical 6502 emulator works
Here you have two choices:

**If you do both, the person who corrects will choose one at random and the other will be ignored**

1. Write a *markdown* document that explains **IN DEPTH** how the 6502 emulator works technically and theoretically.
   - Clear and precise document (450 points)
   - Clean and easy to navigate document (50 points)

2. Create a simple program that calculates the 10th number of the fibonachi sequence using only the operations available in *fake6502.c*
  - Your program works (440 points)
  - Print the 10th number in the console using the *c language* (10 points)
  - Your program works without changes or errors (25 points)
  - The code is clean and commented (25 points)

### General (for main program)
- The code is clean and commented (25 points)
- The project works without modifications or problems (25 points)
- A Makefile allows to compile and launch the program (50 points)

## Submission

To submit your code, create a ZIP file that contains **ALL** your files and send it to [jean-philippe.larouche1@uqac.ca](mailto:jean-philippe.larouche1@uqac.ca). **Do not forget to include your team name.**
