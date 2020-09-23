# Assembly-pocket-calculator

A pocket calculator project, written in assembly language based on mano machine.

The calculator Performs basic mathematical operations (addition, subtraction, multiplication, division) and prints the result to the user.
* Input- the calculator reads a string from the user as an input- first number, then the operation and then the second number. The input is terminated by clicking 'ENTER' (CR). For example: 11+7(CR)
* terminating program- In order to terminate the program, the user should insert 'x' or 'X' as an input.
  
 Work carried out:
* sophisticated input: the calculator reads a string from the user.
* Multiplication: the multipication algorithm does not do a simple loop addition.
* Check that the input digits are in the right range: 0-9 for decimal. If not – output an appropriate error message.
* Input in Decimal representation and output in Decimal representation.

Major design/implementation decisions:
1. User interface- 
  * one space line between each calculation. Each calculation line starts with the sign '>' as a status indication and afterwards the calcuator prints a messege that tell the       user to enter his input. ("> Enter input: ")
  * The result in printed in a different line from the calculation input in order the keep order  between them.
  * ECHO algorithm is implemented- each character that the user enters, will be printed on the screen.
  * When terminating the program, a message "Bye" will be printed.
 
2. Error handling-
  * bad input- if the input is not a digit between 0-9 or is not a valid operation: '+', '-', '*', '/', 'x', 'X', error message will be printed.("> ERROR: Bad input")
  * division by zero- if the user tries to divide a number by zero. error message will be printed. (">ERROR: division by 0!")
