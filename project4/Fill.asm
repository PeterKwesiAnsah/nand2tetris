// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/4/fill/Fill.tst

// Tests the Fill.hack program in the CPU emulator.


//Keep watching the keyboard mapped register
//if 0,we jump to the program that clears the screen
//if not we fill the screen



//initializing variables
@accumulator
M=0


(FILL)

   //terminate loop
   @KBD
   D=A
   @accumulator
   D=D-M
   @WATCH
   D;JEQ

   //fill the pixels
   @SCREEN
   D=A
   @accumulator
   A=D+M
   M=0

    //increment accumulator
    @accumulator
    M=M+1

   @FILL
   0;JMP


(CLEAR)

   //terminate loop
   @KBD
   D=A
   @accumulator
   D=D-M
   @WATCH
   D;JEQ

   //clear the pixels
   @SCREEN
   D=A
   @accumulator
   A=D+M
   M=-1

    //increment accumulator
    @accumulator
    M=M+1

   @CLEAR
   0;JMP



(WATCH)
      @KBD
      D=M

      @accumulator
      M=0

      @FILL
      D;JEQ

      @CLEAR
      0;JMP
