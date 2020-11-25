# Push Swap

## Clone
To copy on your Desktop
```
cd ~/Desktop; git clone ...
```
## Build and Run
```
cd ~/Desctop/push_swap; make
./push_swap ...
```
## Summary
Sort data on a stack, with a set of instructions, using the lowest possible number of actions. It requires to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.

## Learning objectives
- sorting algorithms
- concept of [complexity](https://en.wikipedia.org/wiki/Analysis_of_algorithms)

## Detailed description
Sort a set of int values with two stacks and a set of instructions to manipulate both stacks.

Goal:
Write two programs in C:
- **checker** takes integer arguments and read instructions on the standard output. Checker executes them and displays OK if integers are sorted. Otherwise it will displat KO. (First element in the argument represents the top of the stack).
- **push_swap** calculates and displays on the standard output push_swap instructions. The instructions must sort given numbers in ascending orger.

Starting point:
- stack **a** contains random numbers, positive and negative, without duplicates.
- stack **b** is empty.

Operations to use for sorting:
- **sa** : swap **a** - swap the first 2 elements at the top of stack **a**.
- **sb** : swap **b** - swap the first 2 elements at the top of stack **b**.
- **ss** : **sa** and **sb** at the same time.
- **pa** : push **a** - take the first element at the top of **b** and put it at the top of **a**.
- **pb** : push **b** - take the first element at the top of **a** and put it at the top of **b**.
- **ra** : rotate **a** - shift up all elements of stack **a** by 1. The first element becomes the last one.
- **rb** : rotate **b** - shift up all elements of stack **b** by 1. The first element becomes the last one.
- **rr** : **ra** and **rb** at the same time.
- **rra** : reverse rotate **a** - shift down all elements of stack **a** by 1. The last element becomes the first one.
- **rrb** : reverse rotate **b** - shift down all elements of stack **a** by 1. The last element becomes the first one.
- **rrr** : **rra** and **rrb** at the same time.


## Notes (delete later)
- from one integers configuration to another, the most efficient sorting algorithm can differ
- fast sort O(n log(n))
- To get really good with algorithms, you should have up to high school math. For example, asymptotics might involve the properties of logarithms. Calculus would also be helpful. To be truly superb with algorithms, probability, linear algebra, discrete math, and multivariate calculus are all pretty good to have (like, on the level of machine learning).

1. **a** - max values go to bottom
2. **b** - min values go to bottom
3. swap top values accordingly

## Resources
Khan Academy - [Algorithms course](https://www.khanacademy.org/computing/computer-science/algorithms)<br>
Wikipedia - [Analysis of Algorithms](https://en.wikipedia.org/wiki/Analysis_of_algorithms)