# Write a program that asks the user to enter an integer and outputs the integer in 32-bit two's completement binary.
# There should be a space separating each 4 digits

# Sample runs

# Enter a number: -1
# 1111 1111 1111 1111 1111 1111 1111 1111

# -- Program is finished running --

# Enter a number: 9
# 0000 0000 0000 0000 0000 0000 0000 1001

# -- Program is finished running --

.data
prompt:		.asciiz "Enter a number: "
space:		.asciiz " "

.text
# main:
		# get input / initializations
		# setup digit counter	0-32
		# setup digits shift right, 31-0
		
# loop:
		# shift $s0 to the right (srl) by $t1 digits and store to t3
		# andi t3 with 1 to get target digit
		
		# if t1 <= 0 then exit
		
		# t0 ++
		# t1 --
		
		# branch counter (if counter % 4 = 0 then print a space)
		# branch back to loop

main:
		li	$v0, 4
		la	$a0, prompt
		syscall
		
		li	$v0, 5
		syscall
		move	$s0, $v0			# s0 = input
		
		li	$t0, 0			# t0 = digit counter
		li	$t1, 31			# t1 = digits shift right
		
loop:		
		# get & print binary
		srlv	$t3, $s0, $t1
		andi	$a0, $t3, 1
		
		li	$v0, 1
		syscall
		
		
		blez	$t1, exit		# if t1 <= 0, exit
		
		addi	$t0, $t0, 1		# t0 ++
		addi	$t1, $t1, -1		# t1 --
		
		andi	$t2, $t0, 3		# t2 = t0 % 4
		beqz	$t2, loop_space		# if t2 == 0, print space
		
		b 	loop
loop_space:
		li	$v0, 4
		la	$a0, space
		syscall
		
		b 	loop
exit:
		li	$v0, 10
		syscall
