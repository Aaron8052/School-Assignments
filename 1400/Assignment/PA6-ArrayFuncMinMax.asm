# Programming assignment 6:
# Write a program that asks the user to enter an array of 10 integers and then sends the array to a 
# function, which returns the minimum and maximum value in the array. Main function outputs the 
# minimum and maximum value.
# For the function, the size, 10, is passed to function using $a0, and the address of the array is passed to
# function using $a1, and the minimum and maximum values are returned in $v0 and $v1.

.data
arr:		.space	40
size:		.word	10
prompt:		.asciiz	"Please enter an integer: "
resultMin:	.asciiz "Minimum Value: "
resultMax:	.asciiz "\nMaximum Value: "

.text

main:
	la	$t1, arr		# t1 = &arr
	li	$t0, 0		# t0 = counter
	lw	$t3, size	# t3 = size
prompt_loop:
	bge	$t0, $t3, next
	li	$v0, 4
	la	$a0, prompt
	syscall
	
	li	$v0, 5
	syscall
	move	$t2, $v0
	
	sw	$t2, 0($t1)	# get input and store to arr
	
prompt_loop_update:
	addi	$t1, $t1, 4	# arr ++
	addi	$t0, $t0, 1	# i ++
	b	prompt_loop
	
next:
	#pass args
	move	$a0, $t3		# a0 = t3 = size
	la	$a1, arr		# a1 = &arr
	jal	getMinMax	# Func call getMinMax
	move	$s0, $v0		# s0 = retv 0 = min
	move	$s1, $v1		# s1 = retv 1 = max
	
	#output min
	li	$v0, 4
	la	$a0, resultMin
	syscall
	li	$v0, 1
	move	$a0, $s0
	syscall
	
	#output max
	li	$v0, 4
	la	$a0, resultMax
	syscall
	li	$v0, 1
	move	$a0, $s1
	syscall
	
	# exit
	li	$v0, 10
	syscall
	
getMinMax:
	# a0 = size
	# a1 = address
	# v0 = min
	# v1 = max
	li	$t1, 0		# loop counter
	lw	$v0, ($a1)	# set both v0 v1 to the first element
	lw	$v1, ($a1)
getMinMaxLoop:	
	bge	$t1, $a0, return
	
	lw	$t0, ($a1)	# t0 = value
	blt	$t0, $v0, updateMin
	bgt	$t0, $v1, updateMax
getMinMaxNext:
	addi	$t1, $t1, 1
	addi	$a1, $a1, 4
	b 	getMinMaxLoop
updateMin:
	move	$v0, $t0
	b 	getMinMaxNext
updateMax:
	move	$v1, $t0
	b 	getMinMaxNext
return:
	jr	$ra