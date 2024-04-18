# Write a program that asks the user to enter two integers  
# and displays the difference and remainder of the division of those two numbers.
.data
firstNum:        .asciiz "Please enter the first number: "
secondNum:         .asciiz "Please enter the second number: "
diff:            .asciiz "\nThe difference of the integers is: "
remainder:        .asciiz "\nThe ramainder of num1 / num2 is: "
.text
main:
            li    $v0, 4
            la    $a0, firstNum
            syscall
            
            li    $v0, 5
            syscall
            move    $t1, $v0    #t1 = num1
            
            li    $v0, 4
            la    $a0, secondNum
            syscall
            
            li    $v0, 5
            syscall
            move    $t2, $v0    #t2 = num2
            
            
substraction:
            li    $v0, 4
            la    $a0, diff
            syscall
            
            
            sub    $a0, $t1, $t2
            li    $v0, 1
            syscall
            
division:
            li    $v0, 4
            la    $a0, remainder
            syscall
            
            
            div    $t1, $t2
            mfhi    $a0
            li    $v0, 1
            syscall