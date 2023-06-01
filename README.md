<h1 align="center"> Push Swap</h1>

<p align="center">
  <img src="https://github.com/andreabertolini1995/push_swap/assets/51784826/14613e8c-635e-48ff-bc25-6d5f99c28b55" />
</p>

<!-- ![push_swap](https://github.com/andreabertolini1995/push_swap/assets/51784826/14613e8c-635e-48ff-bc25-6d5f99c28b55) -->

This project is about sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. 

The goal is to write a program in C which calculates and displays on the standard output the smallest program, made of [Push swap language instructions](#general-instructions),
that sorts the integers received as arguments.

## General Instructions
At the beginning:
    * 2 stacks named a and b are given.
    * The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
    * The stack b is empty.
    
The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:
<!-- replace with table here -->

| Instruction | Description |
| ----------- | ----------- |
| sa (swap a) | Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. |
| sb (swap b) | Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. |
| ss | sa and sb at the same time. |
| pa (push a) | Take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
| pb (push b) | Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. |
| sb (swap b) | Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. |
| sa (swap a) | Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. |
| sb (swap b) | Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. |
    
<!--    * ss : sa and sb at the same time.
    * pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
    * pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
    * ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
    * rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
    * rr : ra and rb at the same time.
    * rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
    * rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
    * rrr : rra and rrb at the same time.  -->
    

## General approach
This ptimisation problem can be solved in multipe diffeerent ways. The following are the high-level steps followed by my approach:
* find the number in stack a that requires the least number of operations (in both stacks) to be pushed to stack b
* push the number to stack b. Note that the number is always pushed in the correct position, so that stack a gets implicitly sorted while being moved to stack b
* repeat this operation for all the numbers in stack a
* rotate (or reverse rotate) stack b to move its highest number at the top of the stack
* push all the numbers back in stack a

This approach performs very well, being able to provide a relatively small amount of instructions, such as:
* less than 700 instructions for a stack of 100 numbers
*  less than 5500 instructions for a stack of 500 numbers

Let's have a look at some more details of the algorihtm.

## What number to push and how?

In order to choose, at each iteration, which number is the right candidate to be pushed from stack a to stack b, I go through each number in stack a and store the least number of operations required to move that number already in the correct spot at the top of stack b. 

To do so, for any given *number to push* in stack a, its *highest lower* number from stack b is computed, i.e. the number that should appear at the top of stack b at the moment of the push, in order to move the number in the correct spot and implicitly sort the stack.

In the image below, **7** is the number to push from stack a and **5** is the highest lower found in stack b.

<p align="center">
  <img src="https://github.com/andreabertolini1995/push_swap/assets/51784826/bfca9e69-bfd9-4036-a107-86b7d940d42a" width="600" height="400" />
</p>

At this point, there are four possibilities:
* rotate both stack a and stack b,
* reverse rotate both stack a and stack b,
* rotate stack a and reverse rotate stack b, and
* rotate stack b and reverse rotate stack a.

The *cheapest* combinations of such operations is given by the following formula:

$$ \min(
      \min(
         \min(
            \max(rot_a, rot_b),
            \max(rrot_a, rrot_b)
            ),
         rot_a + rrot_b
         ),
      rot_b + rrot_a
      )
   ) $$


The number associated to the least number of operations is the winning candidate to be sent to stack b.

## Results

Following, a couple of videos, realised with the fantastic [push swap visualizer](https://github.com/o-reo/push_swap_visualizer), showing visually the functioning of the algorithm.

* with 100 random numbers:

https://github.com/andreabertolini1995/push_swap/assets/51784826/3676fdb2-82fa-4386-846f-749680a95dcf

* with 500 random numbers:

https://github.com/andreabertolini1995/push_swap/assets/51784826/e70b2c6a-b610-49cb-a58f-385f389ae262

