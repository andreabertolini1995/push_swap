<h1 align="center"> Push Swap</h1>

<p align="center">
  <img src="https://github.com/andreabertolini1995/push_swap/assets/51784826/14613e8c-635e-48ff-bc25-6d5f99c28b55" />
</p>

This project is about sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. 

The goal is to write a program in C which calculates and displays on the standard output the smallest program, made of [push swap language instructions](#general-instructions),
that sorts the integers received as arguments.

## General Instructions
At the beginning:
* two stacks named **a** and **b** are given
* the stack a contains a random amount of negative and/or positive numbers which cannot be duplicated
* the stack b is empty
    
The goal is to sort in ascending order numbers into stack a. To do so the following operations are at disposal:

| Operation | Description |
| ----------- | ----------- |
| `sa` (swap a) | Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. |
| `sb` (swap b) | Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. |
| `ss` | sa and sb at the same time. |
| `pa` (push a) | Take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
| `pb` (push b) | Take the first element at the top of a and put it at the top of b. Do nothing if a is empty. |
| `ra` (rotate a) | Shift up all elements of stack a by 1. The first element becomes the last one. |
| `rb` (rotate b) | Shift up all elements of stack b by 1. The first element becomes the last one. |
| `rr` | ra and rb at the same time. |
| `rra` (reverse rotate a) | Shift down all elements of stack a by 1. The last element becomes the first one. |
| `rrb` (reverse rotate b) | Shift down all elements of stack b by 1. The last element becomes the first one. |
| `rrr` | rra and rrb at the same time. | 

## Solution
This optimisation problem can be solved in multipe ways. The following are the high-level steps of the approach I pursued:
1. find the number in stack a that requires the least number of operations to be pushed to stack b
2. push the number to stack b. Note that the number is always pushed in the correct position, so that stack a gets implicitly sorted while being moved to stack b
3. repeat this operation for all the numbers in stack a
4. rotate (or reverse rotate) stack b to move its highest number at the top of the stack
5. push all the numbers back in stack a

In order to choose, at each iteration, which number is the right candidate to be pushed from stack a to stack b, I go through each number in stack a and compute the number of operations required to move that number already in the correct spot at the top of stack b. The number associated to the least number of operations is the winning candidate to be sent to stack b.

Once the number to push has been identified, there are four possibilities:
* rotate both stack a and stack b,
* reverse rotate both stack a and stack b,
* rotate stack a and reverse rotate stack b, and
* rotate stack b and reverse rotate stack a.

The *cheapest* combinations of such operations is computed as follows:

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
   
In the example in the image below, **7** is the number to be pushed from stack a to stack b and **5** is the *highest lower*, i.e. the number that should appear at the top of stack b at the moment of the push in order to implicitly sort the stack. 

<p align="center">
  <img src="https://github.com/andreabertolini1995/push_swap/assets/51784826/ab3ea202-0747-4123-8a6e-9b5b155a66ab" width="600" />
</p>

## Run the code

To run the algorithm, it is first need to clone the repository and then to execute the Makefile.
```
git clone https://github.com/andreabertolini1995/push_swap.git
cd push_swap
make
```

Then, you can launch the executable followed by any sequence of positive or negative integers. The output will be the sequence of operations that have been performed to sort the stack in ascending order. As an example:
```
.push_swap 9 7 42 -68 452 0
pb
pb
sb
pb
pb
rb
pb
rrb
pb
rb
rb
pa
pa
pa
pa
pa
pa
```

To have a better understanding of the functioning of the algorithm and to visually see what is actually happening under the hood, you can also use the fantastic [push swap visualizer](https://github.com/o-reo/push_swap_visualizer). Here an example with 100 random numbers:

https://github.com/andreabertolini1995/push_swap/assets/51784826/3676fdb2-82fa-4386-846f-749680a95dcf

## Results

To quickly test the performance of the push swap algorithm on different stacks I used the [push swap tester](https://github.com/louisabricot/push_swap_tester).

The results showed that this approach performs very well, being able to provide a small amount of instructions, such as: 

* less than 700 instructions for a stack of 100 numbers 

<img width="370" alt="Screenshot 2023-06-01 at 13 25 50" src="https://github.com/andreabertolini1995/push_swap/assets/51784826/9d91947f-6903-46fe-a440-a821ce336e75">


* less than 5500 instructions for a stack of 500 numbers

<img width="370" alt="Screenshot 2023-06-01 at 13 26 20" src="https://github.com/andreabertolini1995/push_swap/assets/51784826/f846db86-18d9-4cb5-b75f-f975282df270">

