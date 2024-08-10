# CPU Scheduling Algorithms

This repository contains implementations of three fundamental CPU scheduling algorithms written in C:

1. **First-Come, First-Served (FCFS)**
2. **Shortest Job First (SJF)**
3. **Shortest Remaining Time First (SRTF)**

## Table of Contents

- [Introduction](#introduction)
- [Algorithms Overview](#algorithms-overview)
  - [FCFS](#first-come-first-served-fcfs)
  - [SJF](#shortest-job-first-sjf)
  - [SRTF](#shortest-remaining-time-first-srtf)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

CPU scheduling is a crucial aspect of process management in operating systems. The scheduling algorithms determine the order in which processes are executed by the CPU, which can significantly impact system performance. This repository provides C implementations of three common scheduling algorithms: FCFS, SJF, and SRTF.

## Algorithms Overview

### First-Come, First-Served (FCFS)

FCFS is the simplest scheduling algorithm. Processes are executed in the order they arrive, without preemption. It is non-preemptive, meaning once a process starts its execution, it cannot be stopped until it finishes.

### Shortest Job First (SJF)

SJF schedules processes based on the length of their next CPU burst. The process with the shortest burst time is selected for execution next. SJF can be preemptive or non-preemptive, depending on whether it allows a process to be interrupted by a new process with a shorter burst time.

### Shortest Remaining Time First (SRTF)

SRTF is a preemptive version of SJF. It schedules processes based on the remaining time of their CPU burst. If a new process arrives with a burst time less than the remaining time of the currently running process, the current process is preempted.

## Installation

To run these algorithms locally, clone the repository and compile the C files using a C compiler.

```bash
https://github.com/Rikhil777/Scheduling_Algorithms.git
cd Scheduling_Algorithms
```

Compile the programs using a C compiler, such as `gcc`:

```bash
gcc fcfs.c -o fcfs
gcc sjf.c -o sjf
gcc srtf.c -o srtf
```

## Usage

You can run the compiled executables to execute the algorithms:

```bash
./fcfs
./sjf
./srtf
```

Each program will prompt for input, such as process arrival and burst times, and will output the scheduling order along with relevant metrics like average waiting time and turnaround time.

## Contributing

Contributions are welcome! If you'd like to add improvements or fix any bugs, please fork the repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
