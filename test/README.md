# Simple_shell Project

## Table of Contents
* [Project Description](#project-description)
* [File Structure](#file-structure)
* [Requirements](#requirements)
* [Usage](#usage)
* [Interactive Mode](#interactive-mode)
* [Non Interactive Mode](#non-interactive-mode)
* [Features](#features)
* [Example of Use](#example-of-use)
* [Authors](#authors)

## Project Description
This is a simple UNIX command interpreter that replicates functionalities of the simple shell (sh). This shell is intentionally minimalistic, yet includes the basic functionality of a traditional Unix-like command line user interface. This program was written entirely in C programming language.
Standard functions and system calls employed in simple_shell include:
   `access, execve, exit, fork, free, fstat, getline, malloc, perror, signal, stat, wait, write.`

## File Structure
* [AUTHORS](AUTHORS) - List of contributors to this repository
* [man_1_simple_shell](man_1_simple_shell) - Manual page for the simple_shell
* [shell.h](shell.h) - program header file
* [token.c](token.c) - tokenizing function that creates an array of tokens from a buffer with a specified delimiter
* [simple_shell.c](simple_shell.c) - essential functions to the shell
* [strings.c](string.c) - functions related to string manipulation
* [_puts.c](_puts.c) - function that writes a string to standard output

## Requirements

simple_shell is designed to run in the `Ubuntu 14.04 LTS` linux environment and to be compiled using the GNU compiler collection v. `gcc 4.8.4` with flags`-Wall, -Werror, -Wextra, and -pedantic.`

## Usage

After compilation, the resulting program can run stand-alone, either in interactive or non-interactive mode.

## Interactive Mode

In interactive mode, simply run the program and wait for the prompt to appear. From there, you can type commands freely, exiting with either the "exit" command or ctrl-D.

## Non Interactive Mode

In non-interactive mode, echo your desired command and pipe it into the program like this:

```echo "ls" | ./shell```
In non-interactive mode, the program will exit after finishing your desired command(s).

## Features

1. DIsplay a prompt and wait for the user to type a command. A command-line always ends with a new line.
2. The prompt is displayed again each time a command has been executed.
3. The command lines are simple, no semicolons, no pipes, no redirections, or any other advanced features.
4. The command lines are made only of one word.No arguement will be passed to the programs.
5.If an executable is not found the shell prints an error message and displayu the prompt again.

## Example of Use
Run the executable in your terminal after compiling:
```
$ ./shell
$ # This is our rendition of the shell
$ ls -al
total 52
drwxr-xr-x 2 root root   154 Aug 23 10:17 .
drwxr-xr-x 4 root root    30 Aug 19 14:57 ..
-rw-r--r-- 1 root root   180 Aug 21 13:55 AUTHORS
-rw-r--r-- 1 root root  1232 Aug 23 08:04 man_1_simple_shell
-rw-r--r-- 1 root root   445 Aug 19 14:57 _puts.c
-rw-r--r-- 1 root root  3945 Aug 23 10:16 README.md
-rwxr-xr-x 1 root root 17880 Aug 23 08:12 shell
-rw-r--r-- 1 root root  2860 Aug 23 08:10 shell.c
-rw-r--r-- 1 root root   431 Aug 21 13:40 shell.h
-rw-r--r-- 1 root root  1168 Aug 21 13:32 strings.c
-rw-r--r-- 1 root root   818 Aug 21 10:00 token.c

```

## Authors
Ikebude Michael | [GitHub](https://github.com/mikecasey12)

Ojini Ifeoma | [GitHub](https://github.com/Jinnie506)
