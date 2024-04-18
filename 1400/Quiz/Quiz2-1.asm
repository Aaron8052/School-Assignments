# Write a program that asks the user for an integer. 
# If the integer is negative, then the program asks the user for the length and width of a rectangle 
# and then calculates and outputs the perimeter of the rectangle. 
# If the integer is positive, then the program asks the user for the radius of a circle and then calculates and outputs the circumference of the circle. 
# If the integer is zero, then the program asks the user for the side of a square and then calculates and outputs the perimeter of the square.
.data
prompt:           .asciiz "Please enter an integer: "
length:            .asciiz "Please enter the length of the rectangle: "
width:            .asciiz "Please enter the width of the rectangle: "
perimeter:        .asciiz "\nThe Perimeter is: "
radius:            .asciiz "Please enter the radius of the circle: "
circumference:        .asciiz "\nThe circumference of the circle is: "
squareSide:        .asciiz "Please enter the length of a side of the square: "
.text
        li    $v0, 4
        la    $a0, prompt
        syscall
        
        li    $v0, 5        # v0 = user selection
        syscall
        
        beqz    $v0, squarePerimeter
        bltz    $v0, rectanglePerimeter
        
circle:
        li    $v0, 4
        la    $a0, radius
        syscall
        
        li    $v0, 5        # v0 = radius
        syscall
        
        li    $t0, 2        # 2
        mult    $v0, $t0    # radius x 2
        mflo    $t0        #t0 = radius x 2
        
        li    $t1, 3
        mult    $t0, $t1
        mflo    $t0
        
        li    $v0, 4
        la    $a0, circumference
        syscall
        
        li    $v0, 1
        move    $a0, $t0
        syscall
        
        b     exit
squarePerimeter:
        li    $v0, 4
        la    $a0, squareSide
        syscall
        
        li    $v0, 5        # v0 = square side
        syscall
        
        li    $t0, 4        # 4
        mult    $v0, $t0    # side x 4
        mflo    $t0        #t0 = side x 4
        
        li    $v0, 4
        la    $a0, perimeter
        syscall
        
        li    $v0, 1
        move    $a0, $t0
        syscall
        
        b     exit
rectanglePerimeter:
        li    $t0, 2
        
        li    $v0, 4
        la    $a0, length
        syscall
        
        li    $v0, 5        # v0 = length
        syscall
        mult    $v0, $t0
        mflo    $t1        #t1 = 2 length
        
        li    $v0, 4
        la    $a0, width
        syscall
        
        li    $v0, 5        # v0 = width
        syscall
        
        mult    $v0, $t0
        mflo    $t2        #t2 = 2 width
        
        add    $t0, $t1, $t2
        
        li    $v0, 4
        la    $a0, perimeter
        syscall
        
        li    $v0, 1
        move    $a0, $t0
        syscall
exit:
        li    $v0, 10
        syscall    