# Write a program that asks the user to enter an array of 10 integers and then calls a function to
# sort the array. After the function call, the main function should output the sorted integers in
# the array.
# The function uses the bubble sort algorithm to sort an array of “N” words into ascending order.
# The address of the array and the value N will be passed to the function on
# the stack.

.data
arr:		.space	40
size:		.word	10
prompt:		.asciiz	"Please enter an integer: "
space:		.asciiz	" "

.text
main:
	lw	$t0, size	# size
	la	$t1, arr	# arr ptr
	li	$t2, 0		# counter
loopInput:
	# input
	bge	$t2, $t0, next	# exit condition
	# get input and save
	li	$v0, 4
	la	$a0, prompt
	syscall
	li	$v0, 5
	syscall
	# update
	sw	$v0, ($t1)
	addi	$t1, $t1, 4
	addi	$t2, $t2, 1
	
	b	loopInput
next:
	# init arg and store in stack memory
	la	$t1, arr	# arr ptr
	addi	$sp, $sp, -8	# alloc 8 bytes of stack memory
	# 0 = arrptr, 4 = size
	sw	$t1, 0($sp)
	sw	$t0, 4($sp)
	jal	bubbleSort
	# func has no return value
	addi	$sp, $sp, 8	# dealloc stack
print:
	lw	$t0, size	# size
	la	$t1, arr	# arr ptr
	li	$t2, 0		# counter
loopOutput:
	# output
	bge	$t2, $t0, exit	# exit condition
	# print each arr element
	li	$v0, 1
	lw	$a0, ($t1)	
	syscall
	li	$v0, 4
	la	$a0, space
	syscall
	# update
	sw	$v0, ($t1)
	addi	$t1, $t1, 4
	addi	$t2, $t2, 1
	b	loopOutput
exit:
	# exit
	li	$v0, 10
	syscall
	
	
	
	
	
bubbleSort:
	# 0 = arrptr, 4 = size
	lw	$t0, 4($sp)
	addi	$t0, $t0, -1	# t0 = maxElement
	
outerLoop:
	blez	$t0, return
	lw	$t1, 0($sp)	# t1 = address of current index
	li	$t2, 0		# index
	innerLoop:
		bge	$t2, $t0, updateOuterLoop
		
		lw	$t3, ($t1)	# t3 = value of current index
		addi	$t4, $t1, 4	# t4 = address of next index
		lw	$t5, ($t4)	# t5 = value of next index
		
		bgt	$t5, $t3, updateInnerLoop
		# swap
		sw	$t5, ($t1)
		sw	$t3, ($t4)
		
	updateInnerLoop:
		addi	$t1, $t1, 4
		addi	$t2, $t2, 1
		b	innerLoop
updateOuterLoop:
	addi	$t0, $t0, -1
	b	outerLoop
return:
	jr	$ra
	