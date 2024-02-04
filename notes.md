### Big O Time Complexity
Big O notation is a way to categorize an algorithm based on time or memory requirements. It is used to decide what data structures should be used in a specific scenario.

Here are the three primary rules:

    1. Growth is with respect to the input.
    2. Constants are dropped in Big O notation. e.g. O(2N) isn't used.
    3. Big O covers the WORST CASE scenario of the time complexity for a program.

List of Big O notation categories from best to worst:

    1. O(1) - Time/memory usage does not change based on input size. 
    2. O(logn) - Binary search trees are an example of this (cutting potential usage in half each iteration).
    3. O(n) - Time/memory usage grows linearly based on input size.
    4. O(nlogn) - Quicksort is an example of this.
    5. O(n^2) - Time/memory usage grows exponentially based on input size. Usually nested for loops.
    6. O(2^n)
    7. O(n!)

Loops are a good indicator of Big O complexity.

### Arrays

An array is a fixed size, contiguous memory chunk. 

- Insertion in an array does not add an extra space for the inserted data, but rather overwrites an existing spot. 
- Deletion works the same way for arrays. 
- Both array insertion and deletion are O(1).

In Typescript, `const a = []` is not an array because it does not have a fixed size.

### Algorithms

A good way to solve a problem is to visualize it, write psuedocode, then real code. Check out the programs folder here for the algorithms and data structures covered during these lessons so far.

Most of the topics dicussed in the lesson videos for these pertained to how each search algorithm worked and the planning that went into it, and I figure it would be easier to review the code for these programs than it is to write out the explanations here.
