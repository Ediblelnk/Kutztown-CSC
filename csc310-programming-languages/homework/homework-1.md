# CSC310 Procedure-Oriented Programming Languages

## Homework 1 (Due: Friday, Feb 2, 2024)

(Note) Every homework SHOULD BE TYPED !!

### Answer following questions

Check your Understanding

#### p16 6. What distinguishes declarative languages from imperative languages?

The main focus on declarative languages is what the programmer would like to accomplish. These types of languages orientate themselves on *what* the program is doing. The exact implementation of how the program is accomplishing ideas is more opaque. This allows the programmer to conceptualize at a more abstract level, but often leads to mediocre performance.

Contrasting with declarative languages, imperative languages focus primarily on *how* the computer accomplishes what the programmer has in mind. This generally improves performance, but requires the programmer to be more specific in implementation than with declarative languages.

#### p25 11. Explain the distinction between interpretation and compilation. What are the comparative advantages and disadvantages of the two approaches?

For **Compilation**, *source code* is is compiled into *target code* via the compiler, which is an executable that significantly changes the form and appearance of the source code. This *target code* is then able to be run with input to create corresponding output. This process creates target code which is more specific to the hardware or operating system it is running on, but there are advantages. The compilation process makes a number of decisions about the source program, which leads to fewer decisions that need to be made at runtime. Additionally, various code optimizations may be able to applied. This leads to better performance when compared to interpreted code.

For **Interpretation**, *source code* (generally) goes through a translating process. This creates target code which is still very similar to the original source code. This target code is then run on a virtual machine, which runs the target code directly with the input to produce output. This style of approach is independent of machine or operating system. It is more flexible, as decisions are held off until the absolutely *need* to be made; this also leads to better debugging capabilities. The fact that decisions are always made at the last possible place, however, means that performance trails, sometimes significantly, to compiled languages.

#### p36 22. List the principle phases of compilation, and describe the work performed by each
