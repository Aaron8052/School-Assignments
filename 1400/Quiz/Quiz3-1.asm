# write the program to do the following 
# 1. define an array of 10 integers and then ask the user to input 10 integers and store in the array using a loop.
# 2. After complete the step1, use loop to count how many negative integers in the array and then output the counter.
.data
intArr:        	.space 40        # int arr[10]
size:        	.word 10
prompt:        .asciiz    "Please enter a number: "
result:        .asciiz "Total negative numbers: "
.text
init:
        # setup
        li    $t0, 0        # loop counter: i
        la    $t1, intArr    # arr ptr
        lw    $t2, size    # t2 = size
        
loop_prompt:
        # prompt the user and store
        
        # prompt
        li    $v0, 4
        la    $a0, prompt
        syscall
        
        li    $v0, 5
        syscall
        
        sw    $v0, ($t1)    # *t1 = input
        
        # update counters
        addi    $t0, $t0, 1    # i ++
        addi    $t1, $t1, 4    # ptr ++
        
        bge    $t0, $t2, negative
        
        b     loop_prompt
        
negative:
        # setup
        li    $t0, 0        # loop counter: i
        la    $t1, intArr    # arr ptr
        li    $t4, 0        # negtive # counter    
loop_negative:
        lw    $t3, ($t1)    # t3 = *t1
        bltz    $t3, is_negative
        bge    $t0, $t2, print_result
        b    loop_update
        
is_negative:
        addi    $t4, $t4, 1
loop_update:
        # update counters
        addi    $t0, $t0, 1    # i ++
        addi    $t1, $t1, 4    # ptr ++
        b     loop_negative
        
print_result:
        # result
        li    $v0, 4
        la    $a0, result
        syscall
        
        li    $v0, 1
        move    $a0, $t4
        syscall