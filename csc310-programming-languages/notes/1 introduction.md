# 1. Introduction

## 1.1 The Art of Language Design

There are thousands of high-level programming languages, and new ones continue to emerge. Why?

1. **Evolution**: Find better ways to do something over time.

    - **GoTo-based** flow control: Basic, Fortran, Cobol, *evolved to*
    - **Repetition** (for, while, loops), **Selection** (if, else, switch, match), *evolved to*
    - **Nested block structure** (nested repetition and selection): Ada, Pascal, Algol, *evolved to*
    - **Object Orientated**: C++, Eiffel, Smalltalk

1. **Special Purpose**: Support a specific task or solve a specific problem.

    - **C** was developed to support creating a kernel and operating system development
    - **Java** was developed to support running the same program on "any device"
    - **Lisp** was developed for the implementation of A.I.
    - **Oracle** was developed for database.
    - **HTML** was developed for implementing a webpage.
    - **Fortran** was created for scientific purposes.

1. **Personal Preference**: Every programming language has pros and cons, which are very subjective.
    - d

What makes a language successful?

1. **Expressive power**: Being able to express powerful concepts easily
    - c++: ++, --, +=, ...
    - visual basic: And <-> AndAlso, Or <-> OrElse

1. **Ease of Use**: People's view of how easy it is to program with.
1. **Ease of Implementation**: Unix C++ -> Visual C++
1. **Standardization**: If something is not standardized, then it causes massive headaches.
1. **Open Source**: Limiting access to something does not encourage people to use it.
    - ex. DoD for Ada, IBM Pl/I
1. **Excellent Compilers**
1. **Economic, Patronage, and Inertia**

It is a combinations of the above factors that may help determine whether a language is "good". We need to consider the *viewpoints* of both the *programmer* and the *language implementor*.

## 1.2 The Programming Language Spectrum

The many existing languages can be classified into families based on their **model of computation**.

- **Declarative**
  - *functional*: Lisp/Scheme, ML, Haskell
  - *dataflow*: Id, Val
  - *logic*, constraint-based: Prolog, spreadsheets, SQL

**Declarative** languages focus on *what the computer is to do*. More in tuned with *programmer's point of view*.

Example:

```SQL
SELECT S.name
FROM Student S, Faculty F
WHERE S.major = 'CS' AND F.name = 'Charlie Shim'
```

- **Imperative**
  - *von Neumann*: C, Ada, Fortran, ...
  - *object-oriented*: Smalltalk, Eiffel, Java, ...
  - *scripting*: Perl, Python, PHP, ...

**Imperative** languages focus on *how the computer should do it*. Mainly for *performance reasons*.

## 1.3 Why Study Programming Languages?

1. A good understanding of languages design and implementation can help one **choose the most appropriate language for any given task**. Most languages are better for some things than others.

1. Make it **easier to learn new languages**. There are *basic concepts that underlie all programming languages*, such as
    - types
    - control (iteration, selection, recursion, nondeterminancy, concurrency)
    - abstraction
    - naming

1. Programmers with a strong grasp of language theory will be in a **better position to design elegant, well-structured notation** that meets the needs of current users and facilitates future development.

## 1.4 Compilation and Interpretation

### Question

Briefly explain the difference between compilation and interpretation. Give an example. Are they mutually exclusive? (No, many languages do a combination of both)

**The compiler is itself a machine language program**, presumably created by compiling some other high-level program. When written to a file in a format understood by the operating system, machine language commonly known as ***object code***.

An **alternate style** of implementation for high-level languages is known as **interpretation**. The **interpreter implements a virtual machine** whose machine language *is* the high-level programming language. The interpreter reads statements in that language more or less at a time, executing them as it goes along.

The compiler **translates** the high-level **source program into** an equivalent **target program** (typically in machine languages), and then goes away.

**Compilation generally leads to better performance**. In general, a decision made at compile time is a decision that does not need to be made at runtime.

Since the (final version of a) program is **compiled only once**, but generally **executed many times**, the savings can be substantial.

(Reference diagram 1)

| Compilation | Interpretation |
| :-- | :-- |
| Source compiled into target code via the Compiler, which is an executable. Then this executable is run with the input to create the output. | Interpretation uses a virtual machine to run the code directly with the input to produce output. |
| Specific to machine & O.S. | Independent of machine & O.S. |
| better performance (fewer decisions at runtime) | more flexible (push back decisions) |
| more efficient (code optimization) | better debugging (generally) |

Common **compiled languages** include **C, C++, Cobol, Fortran, Early Basic**.
Common **interpreted languages** include **Modern Basic, Python, Ruby, PHP, Perl, MATLAB**.
Common **both** languages include **Java, Visual Basic**.

We generally say that a language is **interpreted** when the *initial translator is simple*. We generally say that a language is **compiled** when the *translator is complicated*. *Thorough analysis* and *nontrivial transformation (does not bear strong resemblance to the source)* are key identifiers of **compilation**.

Most interpreted languages employ an **initial translator** (a **preprocessor**) that removes comments and white space, and groups characters together into **tokens**, i.e. keywords, identifiers, numbers, and symbols. The translator may identify high-level syntactic structures, such as loops and subroutines.

### Fortran-style Compilation

> The **Fortran** implementation comes close to **pure compilation**. The compiler relies on a separate program, known as the "linker", to merge the appropriate routines into the final program:

Fortran program --(Compiler)--> Incomplete machine language --(Linker, Library routines)--> Machine language program

### Assembly-style Compilation

> Many compilers generate **assembly language** instead of machine language. This convention facilitates **debugging**, since assembly language is easier for people to read, and isolates the compiler from changes in the format of machine language files.

Source program --(Compiler)--> Assembly language --(Assembler)--> Machine language.

> Compilers for *C*, and many other languages under Unix, begin with a preprocessor that removes comments and expands macros.

Source program --(Preprocessor)--> Modified source program --(Compiler)--> Assembly language.

> *C++* early implementations actually generated an intermediate program in *C*, instead of assembly.

C++ program --(C++ Compiler)--> C program --(C Compiler)--> Assembly language

### Self-hosting and Bootstrapping

Many compilers are **self-hosting**. They are written in the language they compile, for example **C compiler in C**.

This uses a technique known as **bootstrapping**. One starts with a simple implementation and use it to build a progressively more sophisticated versions.

For example, if we has a *C* compiler already, we might start by writing, in a simple subset of *C*, a compiler for an equally simple subset of Java. Once this compiler was working, we could hand-translate the *C* code into our subset of Java and run the compiler through itself. We could then repeatedly extend the compiler to accept a larger subset of Java, bootstrap it again, and repeat.

### Late Binding

Compilers for languages that permit a lot of **late binding** are traditionally *interpreted*. Examples are *Lisp, Prolog, Smalltalk, etc.* Late binding leads to increased **flexibility**.

Recent implementations of **Java** employ a **just-in-time, JIT, compiler** that translate *byte code* into *machine language* immediately before each execution of the program. This is also done in **C#**.

Note:

> A compiler does not necessarily translate from a high-level language into machine language. The term *compilation* applies whenever we translate automatically from one nontrivial language to another, with full analysis of the meaning of the input.

## 1.5 Programming Environments

Programmers are assisted by other tools, for example assemblers, preprocessors, linkers, style checkers, configuration management, etc.

In *older programming environments*, tools may be *executed individually*.

More *recent environemnts* provide much more *integrated tools* and *integrated development environments (IDEs)*. The editor for an IDE may incorporate knowledge of language syntax, providing templates all the standard control structures, and checking syntax *as* it is typed in.

Example:

```C++
#include <iostream>

using namespace std;

int main() {
    cout << "Hello World" << endl;
}
```

Refer to diagram 3.

## 1.6 An Overview of Compilation

In a typical compiler, compilation proceeds through a **series of well-defined phases**.
