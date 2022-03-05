# Monty
Monty is a interpreter for Monty byte code files. Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. 
## How to clone
```
git clone https://github.com/Mcfreestyle/monty
```

## Compilation
```
gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty
```

## Usage
For example:
```
./monty bytecodes/0-add.m
```
You can use any file of the bytecodes folder to use the monty interpreter or you can create your ByteCode file using these allowed opcodes:
Opcode|Usage|Description
---|---|---
push|`push <int>`|Pushes an element to the stack
pop|`pop`|Removes the top element of the stack
pall|`pall`|Prints all the values on the stack, starting from the top of the stack
pint|`pint`|Prints the value at the top of the stack
swap|`swap`|Swaps the top two elements of the stack
add|`add`|Adds the top two elements of the stack
nop|`nop`| It doesn’t do anything
sub|`sub`|Subtracts the top element of the stack from the second top element of the stack
div|`div`|Divides the second top element of the stack by the top element of the stack
mul|`mul`|Multiplies the second top element of the stack with the top element of the stack

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
```
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
```
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
```
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
```
Example:
```
julien@ubuntu:~/monty$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
julien@ubuntu:~/monty$ ./monty bytecodes/07.m 
3
2
1
2
1
1
julien@ubuntu:~/monty$
```

## Author
* Michael Chambilla
