.data
list:		.word	30, 2, 10, 5, -3, -5, 8, 9
size:		.word	8
prompt:		.asciiz "Enter a search value: "
.text

main:
	# get input for array (skip)
	# input search value
	li	$v0, 4
	la	$a0, prompt
	syscall
	li	$v0, 5
	syscall
	
	# call function
	addi	$sp, $sp, -16		# request 16 bytes stack memory
	la	$s0, list
	sw	$s0, 0($sp)		# offset 0 = pointer / address of array
	lw	$s0, size
	sw	$s0, 4($sp)		# offset 4 = size
	sw	$v0, 8($sp)		# offset 8 = search value

	jal 	search
	
	lw	$s1, 12($sp)		# load the return value from stack memory
	addi	$sp, $sp, 16		# release stack memory
	
	# print ...
	li	$v0, 1
	move	$a0, $s1
	syscall
	
	#exit
	li	$v0, 10
	syscall

search:	# 0($sp) = address, 4($sp) = size, 8($sp) = search value, 12 = return value
	lw	$t0, 0($sp)		# t0 = address
	lw	$t1, 4($sp)		# t1 = size
	lw	$t2, 8($sp)		# t3 = search value
	
	# function body
	li	$t3, -1			# t3 = index, return value
	li	$t4, 0			# t4 = , index, 0 --> size --> 1
loop:
	bge	$t4, $t1, return
	lw	$t5, ($t0)		# t5 = list[i]
	bne	$t5, $t2, update
	# else, found
	move	$t3, $t4
	b	return
update:
	addi	$t0, $t0, 4		# t0 = address of next element
	addi	$t4, $t4, 1		# i+=
	b	loop
return:
	sw	$t3, 12($sp)
	jr	$ra