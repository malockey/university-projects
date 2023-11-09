# Disciplina: Arquitetura e Organização de Computadores
# Atividade: Avaliação 03 – Programação de Procedimentos
# Problema 2
# Grupo: 
# - Jonathas Meine
# - Mateus José da Silva

.data
    vetor: .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99
    informe: .asciz "Informe o numero de posicoes a serem somadas: "
    strErrado: .asciz "Numero de posicoes invalido\n"
    somaTotal: .asciz "Soma resultante: "

.text
    jal zero, main

somaVetorRec:
    # PUSH
    addi sp, sp, -4
    sw ra, 0(sp)

    addi a2, a2, -1 # numeroPosicao--

    bge a2, zero, rec # condicao de parada do procedimento recursivo
    jalr ra, 0
    
    rec:
        #Carrega valor de vetor[i]
        slli t1, a2, 2
        add t1, t1, a1
        lw t2, 0(t1) # t2 = vetor[i]
        
        add a0, a0, t2 # a0 guardando as somas
        
        jal ra, somaVetorRec # recursao

        # POP
        lw ra, 0(sp)
        addi sp, sp, 4

        jalr ra, 0 # Retorna ao chamador + 4

main:
    la a1, vetor # endereco base do vetor

    addi t0, zero, 2
    addi t1, zero, 101
    
pedirPosicao: # pedir o numero da posicao
	
	# escrita de string
	addi a7, zero, 4
	la a0, informe
	ecall
    
	# leitura de int
	addi a7, zero, 5
	ecall

    # se (a0 < 2 || a0 >= 101) vai para numErrado
    blt a0, t0, numErrado
    bge a0, t1, numErrado
    
    jal zero, numCerto # vai para numCerto

numErrado:
    # escrita de string
    addi a7, zero, 4
    la a0, strErrado
    ecall

    jal zero, pedirPosicao # retorna para pedirPosicao

numCerto:
    add a2, zero, a0 # a2 = numeroPosicoes

    # escrita de string
    addi a7, zero, 4
    la a0, somaTotal
    ecall
    
    add a0, zero, zero # a0 = 0

    jal ra, somaVetorRec # guarda o PC no ra e vai para o procedimento somaVetorRec

    # imprimir soma
    addi a7, zero, 1
    ecall