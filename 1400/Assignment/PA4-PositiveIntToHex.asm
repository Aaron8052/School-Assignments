.data
hexNumbers:	.asciiz "0123456789ABCDEF"
buffer:		.asciiz "0x00000000"
prompt:		.asciiz "Please enter a non-negative integer: "
result:		.asciiz "Hex: "
.text

main:
		li	$v0, 4
		la	$a0, prompt
		syscall
		
		li	$v0, 5
		syscall
		move	$s0, $v0			# s0 = user input
		
		bltz	$s0, main
		
		la	$s1, hexNumbers		# s1 = list of all hex numbers
		la	$s2, buffer		# s2 = hex buffer
		
		li	$t7, 9			# t7 = buffer digit counter
		li	$t6, 16
loop:
		# get last 4 digits of user input in binary
		andi	$t0, $s0, 15		# t0 = remainder
		srl	$s0, $s0, 4		# s0 /= 16
		
		add	$t1, $s1, $t0		# t1 = s1 + t0
		add	$t2, $s2, $t7		# t2 = s2 + t7
		
		lb	$t3, ($t1)		# t3 = value of t1
		sb	$t3, ($t2)
		
		
		
		ble	$t7, 2, next
		blez	$s0, next
		
		addi	$t7, $t7, -1
		
		b 	loop
		
next:
		li	$v0, 4
		la	$a0, result
		syscall
		
		li	$v0, 4
		move	$a0, $s2
		syscall
