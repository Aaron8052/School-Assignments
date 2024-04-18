# Use a loop to print all perfect square numbers from 1 to 90 inclusive.

.data
begin:		.word 1
end:		.word 90
#newline:	.asciiz "\n"

.text

main:
		lw	$t1, end		# t1: max
		lw	$t0, begin		# t0: i counter
		
loop:
		mult	$t0, $t0
		mflo	$t2			#t2: i sqr

		bgt	$t2, $t1, exit		# if(t0 > t1) break;
	
		li	$v0, 1			#print sqr
		move	$a0, $t2
		syscall
		
		#li	$v0, 4			#print \n
		#la	$a0, newline
		li	$v0, 11			#11: output char
		li	$a0, 32			#32: space
		syscall
		
		addi	$t0, $t0, 1		#i++
		b	loop
		
exit:
		li	$v0, 10
		syscall