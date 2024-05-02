# define an array of 10 integers and initialize the array with some different values
# use the loop to check the element of the array. If the element is even, hen increase the element by 1.
# if it is odd, then double it.

.data
values:		.word 5, 2, 3, 5, 8, -8, 10, -99, 2, 7
size:		.word 10
space:		.asciiz "\n"
.text
		la	$t0, values		# t0 = array ptr
		li	$t1, 0			# t1 = loop counter
		lw	$t2, size		# t2 = size
		li	$t5, 2			# t5 = 2
loop: 
		bge	$t1, $t2, print
		lw	$t3, ($t0)		# t3 = array[i]
		


		andi	$t4, $t3, 1
		beqz	$t4, even
		
		# odd
		# value *= 2
		
		#mult	$t3, $t5		# t3 *= 2
		#mflo	$t3
		sll	$t3, $t3, 1		# t3 *= 2 (shift left 1 bit)
loop_next:
		sw	$t3, ($t0)		# array[i] = t3
		addi	$t1, $t1, 1		# i ++
		addi	$t0, $t0, 4		# ptr ++
		b 	loop
even:
		# even
		# value ++
		
		addi	$t3, $t3, 1		# t3 ++
		b 	loop_next
print:
		la	$t0, values		# t0 = array ptr
		li	$t1, 0			# t1 = loop counter
		lw	$t2, size		# t2 = size

loop_print:
		bge	$t1, $t2, exit
		
		li	$v0, 4
		la	$a0, space
		syscall
		
		li	$v0, 1
		lw	$a0, ($t0)		# t3 = array[i]
		syscall
		
		
		addi	$t1, $t1, 1		# i ++
		addi	$t0, $t0, 4		# ptr ++
		b 	loop_print
exit:

		li	$v0, 10
		syscall