# Disciplina: Arquitetura e Organização de Computadores
# Atividade: Avaliação 03 – Programação de Procedimentos
# Problema 1
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

somaVetor:
    # PUSH
    addi sp, sp, -4
    sw s0, 0(sp)

    add s0, zero, zero # soma = 0
    
    add t0, zero, zero # i = 0

    for: # for(i = 0; i < numeroPosicoes; i++)
        bge t0, a2, fimFor # se i >= numeroPosicoes, vai para fimFor

        #Carrega valor de vetor[i]
        slli t1, t0, 2
        add t1, t1, a1
        lw t2, 0(t1) # t2 = vetor[i]

        add s0, s0, t2 # soma += vetor[i]

        addi t0, t0, 1 # i++
        
        jal zero, for # Retorna

    fimFor:
    
    add a0, zero, s0

    # POP
	lw s0, 0(sp)
	addi sp, sp, 4

    jalr ra, 0 # Retorna ao chamador + 4

main:
    la a1, vetor # endereco base do vetor

    addi t0, zero, 2
    addi t1, zero, 101
    
pedirPosicao: # pedir o numero da posicao
	
	# chamar string informe
	addi a7, zero, 4
	la a0, informe
	ecall
    
	# leitura de int
	addi a7, zero, 5
	ecall
    
    blt a0, t0, numErrado # if < vai para numErrado
    bge a0, t1, numErrado # if >= vai para numErrado
    
    ## else
    jal zero, numCerto

numErrado:
    addi a7, zero, 4
    la a0, strErrado
    ecall
    jal zero, pedirPosicao

numCerto:
    add a2, zero, a0 # a2 = numeroPosicoes

    # chamar string somaTotal
    addi a7, zero, 4
    la a0, somaTotal
    ecall
    
    jal ra, somaVetor # guarda o PC no ra e vai para o procedimento somaVetor

    # imprimir soma
    addi a7, zero, 1
    ecall