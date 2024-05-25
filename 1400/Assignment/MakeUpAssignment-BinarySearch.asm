# Make-up assignment:
# Define binary search function.
# Pass the address of the integer array, the size, and the search value via the stack memory, and return the
# index via the stack memory as the following:
# 	Address in 0($sp)
# 	Size in 4($sp)
# 	Search value in 8($sp)
# 	position in 12($sp)
.data
bbb:	.word	2,5,7,9,10,12,14,15,18,19
ccc:	.word	10
aaa:	.asciiz "Please enter int to search: "

.text
main:

	li	$v0, 4
	la	$a0, aaa
	syscall
	
	li	$v0, 5
	syscall
	
	addi	$sp, $sp, -16
	sw	$v0, 8($sp)
	
	la	$t0, bbb
	sw	$t0, 0($sp)
	
	lw	$t0, ccc
	sw	$t0, 4($sp)

	jal	binarySearch
	
	lw	$a0, 12($sp)
	li	$v0, 1
	syscall
	
	addi	$sp, $sp, 16
	
	li	$v0, 10
	syscall
	
binarySearch:
	lw	$a0, 0($sp)	# array
	lw	$a1, 4($sp)	# size
	lw	$a2, 8($sp)	# value
	
	li	$t0, 0		# first = 0
	addi	$t1, $a1, -1	# last = size - 1
	li	$t2, -1		# position
	li	$t3, 0		# found = false
	
	whileLoop:
		bnez	$t3, return		# while loop conditions
		bgt	$t0, $t1, return	
		
		# middle = (first + last) /2
		add	$t4, $t0, $t1
		srl	$t4, $t4, 1		# middle = t4 /= 2
		
		sll	$t5, $t4, 2		# t4 *= 4 = address offset
		add	$t5, $a0, $t5		# t5 = address of middleElement
		lw	$t5, ($t5)		# t5 = middle element

		beq	$t5, $a2, foundAtMiddle	# middle element == value
		bgt	$t5, $a2, toLeft	# middle element > value
		
			# else toRight
			addi	$t0, $t4, 1	# first = middle + 1
			b 	whileLoop
			
		foundAtMiddle:
			li	$t3, 1		# found = true
			move	$t2, $t4	# t2 = position = middle
			b 	return
		toLeft:
			addi	$t1, $t4, -1	# last = middle - 1
			b 	whileLoop
return:
	sw	$t2, 12($sp)
	jr	$ra	