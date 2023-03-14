### Push_swap - 42 school
Is a very simple and a highly straightforward algorithm project:
data must be sorted.

You have at your disposal a set of integer values, 2 stacks, and a set of instructions
to manipulate both stacks.

Your program has to calculates and displays on the standard output the smallest program, made of Push swap language instructions, that sorts the integers received as arguments. In other words, must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top

#### Rules
* You have 2 stacks named a and b.
* At the beginning:
	* The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
* The stack b is empty.
* The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:
	* sa (swap a) and sb (swap b): Swap the first 2 elements at the top of stack.
	* ss : sa and sb at the same time.
	* pa (push a): Take the first element at the top of b and put it at the top of a.
	* pb (push b): Take the first element at the top of a and put it at the top of b.
	* ra (rotate a) and rb (rotate b): Shift up all elements of stack by 1.
		* The first element becomes the last one.
	* rr : ra and rb at the same time.
	* rra (reverse rotate a) and rrb (reverse rotate b): Shift down all elements of stack by 1.
		* The last element becomes the first one.
	* rrr : rra and rrb at the same time.

#### Learning topics in this project:
* Rigor and algorithms.
* C programming, specially linked lists.
* Sorting algorithms: Time complexity.
* Makefile
* Debbuging

### Bonus Part
#### Checker program
The checker program reads the instructions outputed by the push_swap program and applies them to the list of arguments.
Thus check if it's sorted. If it is, print OK. Oterwise print KO.
