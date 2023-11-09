# Discipline: Computer Architecture and Organization
# Activity: Evaluation 01 - Assembly Language Programming
# Program 01
# Group: 
# - Jonathas Meine
# - Mateus José da Silva

.data
    vector: .word 0, 0, 0, 0, 0, 0, 0, 0  # Array of numbers

    # Strings for printing
    enter: .asciz "Enter the size of the array (max = 8): "
    invalidValue: .asciz "Invalid Value.\n"
    vectorStart: .asciz "\nVector["
    vectorEnd: .asciz "] = "
.text

    la s0, vector  # s0 stores the address of the vector

    # t0 and t1 delimit the size of the vector
    addi t0, zero, 2
    addi t1, zero, 9

askSize:  # Ask the user for the size of the vector until a value between [2, 8] is provided

    # Write string
    addi a7, zero, 4
    la a0, enter
    ecall

    # Read int
    addi a7, zero, 5
    ecall

    # If (i < 2 || i >= 9), go to invalid
    blt a0, t0, ifInvalid
    bge a0, t1, ifInvalid

    jal ifValid  # Go to ifValid

ifInvalid:

    # Write string
    addi a7, zero, 4
    la a0, invalidValue
    ecall

    jal askSize  # Return

ifValid:

    add s1, zero, a0  # s1 stores the size of the vector

    add t0, zero, zero  # t0 = i (for loop counter)

forInsert:  # for(i = 0; i < vectorSize; i++) to fill the vector

    bge t0, s1, endForInsert  # If (i >= vectorSize), go out

    # Print Vector[
    addi a7, zero, 4
    la a0, vectorStart
    ecall

    # Print i
    addi a7, zero, 1
    add a0, zero, t0
    ecall

    # Print ] =
    addi a7, zero, 4
    la a0, vectorEnd
    ecall

    # Read int
    addi a7, zero, 5
    ecall

    # Store value in the vector
    slli t1, t0, 2
    add t1, t1, s0
    sw a0, 0(t1)

    addi t0, t0, 1  # i++

    jal forInsert  # Return

endForInsert:

    # Bubble sort

    addi t5, s1, -1  # t5 = vectorSize - 1

    add t0, zero, zero  # t0 = i (for bubble sort)

forBubble:  # for(i = 0; i < vectorSize - 1; i++)

    bge t0, t5, endForBubble  # If (i >= vectorSize - 1), go out

    add t1, zero, zero  # t1 = j (for bubble sort 2)

forBubble2:  # for(j = 0; j < vectorSize - 1; j++)

    bge t1, t5, endForBubble2  # If (j >= vectorSize - 1), go out

    # Read values from the vector
    slli t2, t1, 2
    add t2, t2, s0
    lw t3, 0(t2)  # t3 = vector[j]
    lw t4, 4(t2)  # t4 = vector[j + 1]

    # Swap positions j and (j + 1) in the vector if vector[j] > vector[j + 1]
    blt t3, t4, endIfBubble
    beq t3, t4, endIfBubble
    sw t4, 0(t2)
    sw t3, 4(t2)

endIfBubble:
    addi t1, t1, 1  # j++
    jal forBubble2  # Return

endForBubble2:

    addi t0, t0, 1  # i++
    jal forBubble  # Return

endForBubble:

    # Print the sorted vector
    add t0, zero, zero  # t0 = i

forPrint:

    bge t0, s1, endForPrint  # If (i >= vectorSize), go out

    # Vector[
    addi a7, zero, 4
    la a0, vectorStart
    ecall

    # i
    addi a7, zero, 1
    add a0, zero, t0
    ecall

    # ] =
    addi a7, zero, 4
    la a0, vectorEnd
    ecall

    # Print vector
    slli t1, t0, 2
    add t1, t1, s0
    lw a0, 0(t1)
    addi a7, zero, 1
    ecall

    addi t0, t0, 1
    jal forPrint  # Return

endForPrint:
