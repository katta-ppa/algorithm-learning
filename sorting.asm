#remove sz and replace with number of elements


#Registers used

#t0 -- size of array
#t1 -- count
#t2 -- k number of largest elements to print
#t7 -- current element in the inner loop for comparing
#t8 -- current element in the inner loop for comparing



    .data
mess1:   .asciiz " Enter number of elements to be stored in the array. "
mess2:   .asciiz " Enter the elements. (0 to quit) "
mess3:   .asciiz " Enter number of largest to be printed"
List:   .space  200
NL:     .asciiz "\n"

    .text

main:
    li $t1, 0
    la $a1, List

    li $v0, 4
    la $a0, mess1
    syscall

    li $v0, 5
    syscall
    move $t0, $v0

    li $v0, 4
    la $a0, mess3
    syscall

    li $v0, 5
    syscall
    move $t2, $v0

    li $v0, 4
    la $a0, mess2
    syscall

read_array:
    addi $t1, $t1, 1
    
    li $v0, 5
    syscall

    sw $v0, 0($a1)
    addiu $a1, $a1, 4

    beq $t1,$t0, sort
    j read_array


sort:
    move $s3, $t0                       # set outer loop limit
    addi $s3, $s3, -1

outer:                               # outer bubble-sort loop
    bge $zero, $s3, outer_end
    li $s0, 0                        # set inner loop counter
    li $s1, 0                        # set current element offset

inner:                               # inner bubble-sort loop
    bge $s0, $s3, inner_end
    lw $t7, List($s1)                # get current element
    lw $t8, List + 4($s1)            # get next element
    ble $t7, $t8, no_swap
    sw $t8, List($s1)
    sw $t7, List + 4($s1)

no_swap:
    addi $s1, $s1, 4
    addi $s0, $s0, 1                 # increment inner loop counter
    j inner                          # restart inner loop

inner_end:
    addi $s3, $s3, -1                # decrement outer loop limit
    j outer                          # restart outer loop

outer_end:

print:
                        
    move $s1, $zero                 # set counter for # of elems printed
    sub $s2, $t0, -1($t2)           # set offset from Array

print_loop:
    bge $s1, $t2, print_loop_end    # stop after last elem is printed

    lw $a0, List($s2)              # print next value from the list
    li $v0, 1
    syscall

    la $a0, NL                       # print a newline
    li $v0, 4
    syscall

    addi $s1, $s1, 1                 # increment the loop counter
    addi $s2, $s2, 4                 # step to the next array elem
    j print_loop                     # repeat the loop

print_loop_end:
    li $v0, 10
    syscall