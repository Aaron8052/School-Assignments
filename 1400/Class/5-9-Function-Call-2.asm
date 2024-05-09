.data
array:		.word 10, 2, 1, -9, -8, 0, -2, 6
size:		.word 8
result:		.asciiz "# of even integers: "
.text
main:
	la	$a0, array
	lw	$a1, size
	jal	count		# function call count
	move	$s0, $v0
	# print
	li	$v0, 3
	la	$a0, result
	syscall
	li	$v0, 1
	move	$a0, $s0
	syscall
	#exit
	li	$v0, 10
	syscall
	
	
count:
	addi	$sp, $sp, -8	# allocate 8 bytes stack memory (stack mem is going down, so -8)
	sw	$s0, 0($sp)	# store data into stack memory
	sw	$s1, 4($sp)
	li	$s0, 0		# s0 = counter
	li	$s1, 0		# s0 = i = loop counter
loop:
	bge	$s1, $a1, return
	lw	$t0, ($a0)	# t0 = element
	andi	$t1, $t0, 1	# t1 = t0 % 2
	bnez	$t1, update
	#else --> even
	addi	$s0, $s0, 1	# counter ++
update:
	addi	$a0, $a0, 4	# a0 = address of next element
	addi	$s1, $s1, 1	# i ++
	b 	loop
return:
	move	$v0, $s0	# store the return value into v0
	lw	$s0, 0($sp)	# restore the data from stack memory to $s
	lw	$s0, 4($sp)
	addi	$sp, $sp, 8	# release stack memory
	jr	$ra