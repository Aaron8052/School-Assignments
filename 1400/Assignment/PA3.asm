# Write a program that asks the user to enter integers until -99. The program should find and output the 
# average of odd integers and the average of even integers that the user entered (not including -99)

.data
prompt:		.asciiz "\nPlease enter an integer, enter -99 to eliminate: "
avgOdd:		.asciiz "\nThe average of odd numbers: "
avgEven:		.asciiz "\nThe average of even numbers: "
remainder:	.asciiz " Remainder: "
.text

		li	$t1, 0		# t1 = odd num counter
		li	$s1, 0		# s1 = odd sum
		li	$t0, 0		# t1 = even num counter
		li	$s0, 0		# s0 = even sum
		
loop:
		# a loop that prompts user for int input until -99
		li	$v0, 4		# output string
		la	$a0, prompt
		syscall
		
		li	$v0, 5
		syscall
		
		move	$t2, $v0		# t2: input
		beq	$t2, -99, next	# to next if input is -99
		#beqz	$t2, loop	# skip zero
		
		andi	$t3, $t2, 1	# t3: last binary digit of t2 (user input)
		bnez	$t3, isOdd	# if t3 is not 0: odd number

isEven:
		add	$s0, $s0, $t2	# s2 += input
		addi	$t0, $t0, 1	# t0 ++
		b	loop		# go back to loop
isOdd:
		add	$s1, $s1, $t2	# s1 += input
		addi	$t1, $t1, 1	# t1 ++
		b	loop		# go back to loop
next:
		beqz	$t1, evenAverage	# skip if no odd input
		
		# odd avg
		div	$s1, $t1
		
		li	$v0, 4		# output integer
		la	$a0, avgOdd
		syscall
		
		li 	$v0, 1
		mflo	$a0
		syscall
		
		li	$v0, 4		# output remainder
		la	$a0, remainder
		syscall
		
		
		li 	$v0, 1
		mfhi	$a0
		syscall
		
evenAverage:
		beqz	$t0, exit	# skip if no even input
		
		# even avg
		div	$s0, $t0
		
		li	$v0, 4		# output integer
		la	$a0, avgEven
		syscall
		
		
		li 	$v0, 1
		mflo	$a0
		syscall
		  
		li	$v0, 4		# output remainder
		la	$a0, remainder
		syscall
		
		
		li 	$v0, 1
		mfhi	$a0
		syscall
		
exit:
		li	$v0, 10
		syscall
		
		
		
