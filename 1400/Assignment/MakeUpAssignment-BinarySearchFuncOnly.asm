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