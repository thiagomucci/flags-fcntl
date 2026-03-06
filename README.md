# fcntl flags
A small Unix-style tool written in C to inspect and modify file descriptor flags using `fcntl`

This project is based on concepts from **APUE (Advanced Programming in the UNIX Environment), Chapter 3**

## Features

- Opens a file using `open()`
- Retrieves file status flags using `fcntl(F_GETFL)`
- Displays the access mode of the file descriptor
- Optionally enables additional flags

## Supported Flags

| Option | Description |
|------|-------------|
| -a | Enable `O_APPEND` mode |
| -n | Enable `O_NONBLOCK` mode |

## Usage


./fdflags [options] <file>
>i will add the flags
