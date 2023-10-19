# System Calls

1. fork
2. wait
3. getpid
4. pthread_create
5. pthread_join
6. pthread_self
7. pipe
8. read
9. write
10. exec

#### Why is important for a parent process to call wait, or an equivalent function call, for each child process created?

If wait is not called, then the parent process may end before all child processes have ended. This creates zombie/orphan processes, which is not good.

#### What is meant by a blocking system call? Give an example of a blocking system call that we have used in a programming project.

A blocking system call is a call to a function that blocks the execution of the program until the call is complete. An example of such a call would be `wait()`, which we used in processes.

#### How can we pass multiple values to a thread?

We can pass multiple values to a thread by using structs. A struct can "hold" multiple values, and the struct (pointer). Can then be passed as the sole value argument a thread accepts.

#### Why can unnamed pipes only be used for inter-process communication between related processes?

Unnamed pipes can only be used for IPC because they used file descriptors, which will be known only locally to the parent and any child processes.

#### How can bidirectional communication be achieved with unnamed pipes?

To achieve bidirectional communication, you can use two pipes. That way, each process gets its own set of a read and a writer end of a pipe.

#### What is one advantage of using a Makefile to build a software project?

Building the project is super easy, and does not vary per language. Once you set up the contents of the makefile with the proper commands to build the software project, all you need to do is type "make" in the shell, and the makefile will make it.

#### What is a `.PHONY` target and why would we need to use one?

A phony target is a target that does exist in the program. Its vole is to act as a convenient subroutine the makefile executes, typically to manipulate the files of the software project. One example is the `.PHONY clean`, which typically cleans up auxiliary files from the project.