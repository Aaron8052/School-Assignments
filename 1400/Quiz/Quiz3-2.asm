# Write a program that asks the user for a room number  (integer from 100 to 499) and displays the room number.
# Input validation: only accept the room number from 100 to 499 inclusive.
.data
prompt:        .asciiz "Please enter room#: "
min:        .word    100
max:        .word    499
result:        .asciiz "The room# is: "
err:        .asciiz    "Room# must in between 100-499 inclusive!\n"
.text
        
init:
        lw    $t1, min
        lw    $t2, max
main:
        li    $v0, 4
        la    $a0, prompt
        syscall
        
        li    $v0, 5
        syscall
        move    $t0, $v0    # t0 = input
        
        blt    $t0, $t1, error
        bgt    $t0, $t2, error
        
        # next
        li    $v0, 4
        la    $a0, result
        syscall
        
        li    $v0, 1
        move    $a0, $t0
        syscall
        
        li    $v0, 10
        syscall
        
error:
        li    $v0, 4
        la    $a0, err
        syscall
        
        b     main 