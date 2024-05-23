# write a program to do the following
# 1. ask the user to enter two integers and pass them to a function via the stack.
# 2. write a function to find the sum of two integers and the remainder of division of those two integers and return the sum and the remainder. 
# The parameters are passed to function on the stack and the sum and the remainder are returned on the stack.
# 3. print the return values in main function..
.data
prompt:        .asciiz "Please enter an integer: "
result1:    .asciiz "The sum is "
result2:    .asciiz    "\nThe remainder is "
.text
main:
    addi    $sp, $sp, -16
    li    $v0, 4
    la    $a0, prompt
    syscall
    li    $v0, 5
    syscall
    sw    $v0, 0($sp)
    
    li    $v0, 4
    la    $a0, prompt
    syscall
    li    $v0, 5
    syscall
    
    sw    $v0, 4($sp)
    
    jal    sumDiv
    
    li    $v0, 4
    la    $a0, result1
    syscall
    
    li    $v0, 1
    lw    $a0, 8($sp)
    syscall
    
    
    li    $v0, 4
    la    $a0, result2
    syscall
    
    li    $v0, 1
    lw    $a0, 12($sp)
    syscall
    
    
    addi    $sp, $sp, 16
    # exit
    li    $v0, 10
    syscall
    
    
sumDiv:
    #(16) 0 = num1, 4 = num2, 8 = sum, 12 = remainder
    lw    $a0, 0($sp)
    lw    $a1, 4($sp)
    
    add    $v0, $a0, $a1
    div    $a0, $a1
    mfhi    $v1
    
    sw    $v0, 8($sp)
    sw    $v1, 12($sp)
    
    jr    $ra
