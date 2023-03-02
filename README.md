# Lab-07: Fork and Exec

Objective: Write a program that **takes a filename as a command-line argument** and performs the following steps:

1.	Open the file provided as a command-line argument.

2.	Read the contents of the file one-line at a time (use fgets or getline).

3.	Use fork-exec to create a new process that executes the program specified in the input file along with the arguments provided.

4.	The parent process will make note of the time the program was started (you can use a timer such as the time function defined in <time.h> to capture the time before the fork method is invoked, you can find out more about time function by typing man time).

5.	Then the parent process will wait for the child process to complete and when the child process terminates successfully, the parent process will capture the time the child process completed (you can again use a timer function to capture the time when the wait function returns).

6.	Open a log file (say, output.log) and write the command executed along with arguments, start time of the process, and the end time of the process separated by tabs. Use **ctime function to write the time in a human readable form.**

7.	Go to step 2 and repeat the above process for very command in the input file.
Please use standard I/O library function calls for all I/O operations in this assignment. Make sure you open the file in the appropriate modes for reading and writing and also make sure to close the file, especially when you are writing the file.


Here is a sample input file:
`
uname -a
/sbin/ifconfig
/home/UAB/puri/CS332/lab7/hw1 500 
/home/UAB/puri/CS332/lab7/hw1 1000 
`
Note: You will need to provide a different path for the hw1 executable.


Here is the corresponding sample output log file:

`
uname -a    Thu Oct 10 17:43:44 2019    Thu Oct 10 17:43:44 2019
/sbin/ifconfig    Thu Oct 10 17:43:44 2019    Thu Oct 10 17:43:44 2019
/home/UAB/puri/CS332/lab7/hw1 500    Thu Oct 10 17:43:45 2019    Thu Oct 10 17:43:46 2019
/home/UAB/puri/CS332/lab7/hw1 1000    Thu Oct 10 17:43:46 2019    Thu Oct 10 17:43:57 2019
`
Hints: 
You can download the sample C program hw1.c (this is an old homework assignment). This program has some similar functions, feel free to use them.  Compile the program using the following command:

`
$ gcc -Wall -O -o hw1 hw1.c
`
