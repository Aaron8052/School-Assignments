.data
#.align	2
array:		.space 40
size:		.word 10
prompt:		.asciiz "please enter 10 integers: \n"
result1:	.asciiz "Min: "
result2:	.asciiz "\nMax: "

.text
main:
	li	$v0, 4
	la	$a0, prompt
	syscall
	
	la	$s0, array	# s0 = pointer of array
	lw	$s1, size	# s1 = size
	
input:
	blez	$s1, next
	li	$v0, 5
	syscall
	sw	$v0, ($s0)	# store into memory
	addi	$s0, $s0, 4	# point to next element
	addi	$s1, $s1, -1	# decrease loop counter
	b	input	
next:	#set the arguments
	la	$a1, array
	lw	$a0, size
	jal	min_max
	move	$s2, $v0
	move	$s3, $v1
	
	# print
	li	$v0, 4
	la	$a0, result1
	syscall
	li	$v0, 1
	move	$a0, $s2
	syscall
	
	li	$v0, 4
	la	$a0, result2
	syscall
	li	$v0, 1
	move	$a0, $s3
	syscall
	
	li	$v0, 10
	syscall
	
min_max:
	# a0 = size, a1 = address, v0 = min, v1 = max
	lw	$v0, ($a1)
	lw	$v1, ($a1)
	addi	$a1, $a1, 4	# a1 = address of next element
	li	$t0, 1		# t0 = loop counter, i = 1
loop:
	bge	$t0, $a0, return
	lw	$t1, ($a1)	# t1 = element
	bgt	$v0, $t1, update_min
	# else do not update min
	b	max
update_min:
	move	$v0, $t1	#update min
max:
	bgt	$v1, $t1, update
	#else update max
	move	$v1, $t1
update:
	addi	$t0, $t0, 1	#i++
	addi	$a1, $a1, 4	#point to next element
	b	loop
	
return:
	jr	$ra