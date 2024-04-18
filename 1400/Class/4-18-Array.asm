# define an integer array of 5 elements
# use a loop to input those elements
# after input, use another loop to find the sum of all elements
# output the sum

.data
num:		.space 20
size:		.word 5
prompt:		.asciiz "Enter an integer: "
result:		.asciiz "The sum is "

.text
main: 
	# get input
	la	$t0, num		#t0 = address of 1st element
	lw	$t1, size		#t1 = size
	li	$t2, 0			#loop counter: i = t2 = 0 up to size -1
input:
	bge	$t2, $t1, next		#if (i >= size) exit the loop
	li	$v0, 4
	la	$a0, prompt
	syscall
	li	$v0, 5
	syscall				#v0 = input data
	sw	$v0, ($t0)		#num[0]=input
	# update
	addi	$t0, $t0, 4		#t0 = address of next element
	addi	$t2, $t2, 1		#i++
	b 	input
next:
	#output all elements--skip
	#find sum of all elements
	li	$s0, 0			#s0 = sum = 0
	la	$t0, num		#t0 = address of 1st element
	li	$t2, 0			#loop counter: i = t2 = 0 up to size -1
sum:
	bge	$t2, $t1, output	#if (i >= size) exit the loop
	lw	$t3, ($t0)		#t3 = num[i]
	add	$s0, $s0, $t3		#sum += num[i]
	#update
	addi	$t0, $t0, 4		#t0 = address of next element
	addi	$t2, $t2, 1		#i++
	b 	sum
output:	#print sum
	li	$v0, 4
	la	$a0, result
	syscall
	li	$v0, 1
	move	$a0, $s0
	syscall
	
	li	$v0, 10
	syscall
	