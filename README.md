# get_next_line

This is the implementation of the `get_next_line` function in C, as part of the 42 School curriculum.

## Table of Contents

- [Description](#description)
- [Examples](#examples)
- [Usage](#usage)
- [Functionality](#functionality)
- [Usage](#usage)

## Description

The `get_next_line` project is designed to read a line from a file descriptor or multiple file descriptors `(Bonus)`, allowing for efficient reading of files or other input sources.

## Examples

Here is an example demonstrating the usage of `get_next_line`:

  ```c
  int	main(void)
  {
  	int fd;
  	char *line;
  
  	fd = open("file.txt", O_RDONLY);
  	line = get_next_line(fd);
  	while (line)
  	{
  		printf("Line: %s", line);
  		free(line);
  		line = get_next_line(fd);
  	}
  	close(fd);
  	return (0);
  }
  ```
  For Bonus:
  ```c
  int	main(void)
  {
  	int		fd;
  	int		fd1;
  	int		fd2;
  	char	*line;
  
  	fd = open("file.txt", O_RDONLY);
  	fd1 = open("file1.txt", O_RDONLY);
  	fd2 = open("file2.txt", O_RDONLY);
  	line = get_next_line(fd);
  	while (line)
  	{
  		printf("FD: %d, LINE: %s\n", fd, line);
  		free(line);
          line = get_next_line(fd1);
          printf("FD: %d, LINE: %s\n", fd1, line);
  		free(line);
          line = get_next_line(fd2);
           printf("FD: %d, LINE: %s\n", fd2, line);
  		free(line);
  		line = get_next_line(fd);
  	}
  	close(fd);
  	close(fd1);
  	close(fd2);
  }
  ```  

## Usage

To use the `get_next_line` function in your project, follow these steps:

1. Clone the repository:

    ```bash
    https://github.com/Madelsa/42-get_next_line.git
    ```

2. Include the header file in your `.c` file:

    ```c
    #include "get_next_line.h"
    ```
    For Bonus:
    ```c
    #include "get_next_line_bonus.h"
    ```

4. Compile the `get_next_line` project by running the following command:

    ```bash
    gcc get_next_line.c get_next_line_utils.c my_program.c
    ```
    For Bonus:
    ```bash
    gcc get_next_line.c get_next_line_utils.c my_program.c
    ```
    `Note:`  the `my_program.c` file is the file that contains your `main` function.

5. Use `get_next_line` in your code to read lines from file descriptors.

## Functionality

The `get_next_line` function reads a line from a file descriptor and returns the line ending with a newline character (`'\n'`) or the end-of-file (`EOF`). It allocates memory for the line and handles multiple file descriptors `(Bonus)`.

### Usage

To use the `get_next_line` function in your project, follow these steps:

1. Clone the repository:

    ```bash
    https://github.com/Madelsa/42-get_next_line.git
    ```

2. Include the header file in your `.c` file:

    ```c
    #include "get_next_line.h"
    ```
    For Bonus:
    ```c
    #include "get_next_line_bonus.h"
    ```

3. Compile the `get_next_line` project with your `.c` file that contains the `main` function by running the following command:

    ```bash
    gcc get_next_line.c get_next_line_utils.c my_program.c
    ```
    For Bonus:
    ```bash
    gcc get_next_line_bonus.c get_next_line_utils_bonus.c my_program.c
    ```

4. Run your `a.out` executable:
   
   ```bash
   ./a.out
   ```
5. Now you can use `get_next_line` in your code.
