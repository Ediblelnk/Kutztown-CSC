# Chapter 1: Introduction

## Objectives

- To describe the basic organization of computer systems
- To provide a grand tour of the major components of operation systems
- To give an overview of the many types of computing environments
- To explore several open-source operating systems

## What is an Operating System?

- A program that acts as an intermediary between a user of a computer and the computer hardware
- Operating system goals:
  - Execute user programs and make solving user problems easier
  - Make the computer system convenient to use
  - Use the computer hardware in an *efficient* manner

## Computer System Structure

- Computer System can be divided into four components:
    1. Hardware - provides basic computing resources
        - CPU, memory, I/O devices
    1. Operating system
        - Controls and coordinates use of hardware among various applications and users
    1. Application programs - define the ways in which the system resources are used to solve the computing problems of the users
        - Word processors, compilers, web browsers, database systems, video games
    1. Users
        - People, machines, other computers

## Four Components of a Computer System

[diagram.1]

## What Operating Systems Do

- Depends on the point of view
- Users want convenience, *ease of use*, and *good performance*
  - Don't care about *resource utilization*
- But shared computers, such as a *mainframe*, or *minicomputer* must keep all users happy
- Users of dedicated systems such as *workstations* have dedicated resources but frequently use shared resources from *servers*
- Handheld computers are *resource poor*, optimized for usability and battery life
- Some computers have little or not user interface, such as embedded computers in devices and automobiles

## Operating System Definition

- OS is a **resource allocator**
  - Manages all resources
  - Decides between conflicting requests for efficient and fair resource use
- OS is a **control program**
  - Controls execution of programs to prevent errors and improper use of the computer
- No universally accepted definition
- "Everything a vendor ships when you order an operating system" is a good approximation, but varies wildly
- "The one program running at all times on the computer" is the **kernel**
- Every else is either:
  1. A system program (ships with the operating system), or
  1. An application program.

## Computer Startup

- **Bootstrap program** is loaded at power-up or reboot
  - Typically stored in ROM or EPROM, generally known as **firmware**
  - Initializes all aspects of system
  - Loads operating system kernel and starts execution

## Computer System Organization

- Computer-system operation
  - One or more CPUs, device controllers connect through common bus providing access to shared memory

[diagram.2]

## Computer System Operation

- I/O devices and the CPU can execute concurrently
- Each device controller is *charge of a particular device type*
- Each device controller has a *local buffer*
- CPU moves data from/to main memory to/from local buffers
- I/O is from the device to local buffer of controller
- Device controller informs CPU that it has finished its operation by causing an **interrupt**

## Common Functions of Interrupts

- Interrupt transfers control to the interrupt service routine generally, through the **interrupt vector**, which contains the addresses of all the service routines
- Interrupt architecture must save the address of the interrupt instruction
- A **trap** or **exception** is a software-generated interrupt caused either by an error or a user request
- An operating system is **interrupt drive**

## Interrupt Handling

- The operating system preserves the state of the CPU by storing registers and the program counter
- Determines which type of interrupt has occurred:
  1. **Polling**
  1. **Vectored** interrupt system
- Separate segments of code determine what action should be taken for each type of interrupt

## Interrupt Timeline

[diagram.3]

## I/O Structure

- After I/O starts, control returns to user program only upon I/O completion
  - **Wait instruction** idles the CPU until the next interrupt
  - **Wait loop** (contention for memory access)
  - At most one I/O request is outstanding at a time, no simultaneous I/O processing
- After I/O starts, control returns to user program without waiting for I/O completion
  - **System call** - request to the OS to allow the user to wait for I/O completion
  - **Device-status table** contains entry for each I/O device indicating its type, address and state
  - OS indexes into I/O device table to determine device status and to modify table entry to include interrupt

## Storage Structure

- **Main memory** - only large storage media that the CPU can access directly
  - **Random access**, typically **volatile**
- **Secondary storage** - extension of main memory that provides large **nonvolatile** storage capacity
- Hard disks - rigid metal or glass platters covered with magnetic recording material
  - Disk surface is logically divided into **tracks**, which are subdivided into **sectors**
  - The **disk controller** determines the logical interaction between the device and the computer
- **Solid-state disks** - faster than hard disks, nonvolatile
  - Various technologies
  - Becoming more popular

## Storage Hierarchy

- Storage systems organized in hierarchy
  - Speed
  - Cost
  - Volatility
- **Caching** - copying information into faster storage system; main memory can be viewed as a cache for secondary storage
- **Device Driver** for each device controller to manage I/O
  - Provides uniform interface between controller and kernel
