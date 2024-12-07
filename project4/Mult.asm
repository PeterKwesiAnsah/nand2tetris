// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/4/mult/Mult.tst

// Tests the Mult program, designed to compute R2 = R0 * R1.
// Tests the program by having it multiply several sets of
// R0 and R1 values.

//initializing variables
@accumulator
M=0

@R0
D=M

@Multiplicand
M=D

@R1
D=M

@Multiplier
M=D

(LOOP)
    @Multiplier
    D=M
    @FINISH
    D;JEQ

    @Multiplicand
    D=M
    @FINISH
    D;JEQ

    @Multiplier
    D=M
    //jump to END
    @FINISH
    D;JEQ

    @Multiplicand
    D=M

    @accumulator
    M=D+M

    @Multiplier
    M=M-1

    @LOOP
    0;JMP

(FINISH)
    @accumulator
    D=M

    @R2
    M=D

(END)
    @END
    0;JMP
