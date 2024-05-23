# write a program to do the following
# 1. define an array of 8 integers with some initial values (some even, some odd, some positive and some negative)
# 2. write a function to count how many odd integers in the array and return the counter. 
# Two parameters are passed to function via $a0 and $a1, the address of an array  and number of integers in the array, and the return value is stored in $v0.
# 3. print the return value in main function..
.data
arr:        .word    1, 1, -3, -1, 4, 6, -7, -8
size:        .word    8
result:        .asciiz    "Odd Integers: "
.text
main:
    li    $v0, 4
    la    $a0, result
    syscall
    
    # a0 = address
    # a1 = size
    # v0 = return value
    
    
    la    $a0, arr
    lw    $a1, size
    jal    oddCount
    
    move    $a0, $v0
    li    $v0, 1
    syscall
    
    # exit
    li    $v0, 10
    syscall
    
oddCount:
    # a0 = address
    # a1 = size
    # v0 = return value
    li    $v0, 0        # odd count
    li    $t0, 0        # loop counter
loop:
    bge    $t0, $a1, return
    lw    $t1, ($a0)    # t1 = element
    andi    $t1, $t1, 1    # t1 %= 1
    beqz     $t1, update
    
    # else is odd
    addi    $v0, $v0, 1
update:
    addi    $t0, $t0, 1
    addi    $a0, $a0, 4
    b     loop
return:
    jr    $ra
