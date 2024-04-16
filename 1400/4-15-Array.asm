.data
scores:		.word 90, 89, 78, 92, 95, 87
size:		.word 6
newline:	.asciiz "\n"

.text
		la	$t0, scores		#t0=address of 1st element
		lw	$t1, size		#t1=size=6
		li	$t2, 0			#t2=loop counter
loop:
		bge	$t2, $t1, next
		lw	$a0, 0($t0)		#a0=element of the array
		li	$v0, 1
		syscall
		li	$v0, 4
		la	$a0, newline
		syscall
		
		addi	$t0, $t0, 4		#t0=the address of next element (int = 4bytes)
		addi	$t2, $t2, 1		#i++, loop counter++
		b loop
		
next:
		li	$v0, 10
		syscall
