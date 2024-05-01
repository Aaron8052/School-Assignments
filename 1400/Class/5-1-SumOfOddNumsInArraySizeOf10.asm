# define an array of 10 integers and get the input of elements
# from the user
# use the loop to find the sum of odd integers and output the sum

.data
array: 		.space 40
size:		.word 10
prompt:		.asciiz "Enter an integer: "
result:		.asciiz "The sum is "

.text
main:
	# get input
	la	$t0, array		# t0 = address of 1st element
	lw	$t1, size		# t1 = i = size ---- decrease to 0
input_loop:
	blez	$t1, next
	li	$v0, 4
	la	$a0, prompt
	syscall
	li	$v0, 5
	syscall				# v0 = input
	sw	$v0, ($t0)		# array[i] = input
	# update
	addi	$t0, $t0, 4		# t0 = address of next element
	addi	$t1, $t1, -1		# i--
	b	input_loop
next:
	# find sum of odd integer
	li	$s0, 0			# s0 = sum = 0
	la	$t0, array		# t0 = address of the first element
	lw	$t1, size		# t1 = i = size ------ decrease to 0
sum_loop:
	blez	$t1, print
	lw	$t2, ($t0)		# t2 = array[i]
	andi	$t3, $t2, 1		# t3 = array[i] % 2
	beqz	$t3, update
	# else -> odd
	add	$s0, $s0, $t2		# sum = sum + array[i]
update:
	addi	$t0, $t0, 4		# t0 = address of next element
	addi	$t1, $t1, -1		# i--
	b	sum_loop
	
print:	# print the sum
	li	$v0, 4
	la	$a0, result
	syscall
	li	$v0, 1
	move	$a0, $s0
	syscall