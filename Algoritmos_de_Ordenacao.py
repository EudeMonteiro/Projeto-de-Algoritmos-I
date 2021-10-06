#Autor: Eude Monteiro da Hora

import random as rd
import time

number_of_comparisons = 0  # Número de comparações realizadas
number_of_swaps = 0        # Número de trocas realizadas

#BubbleSort
def bubbleSort(V: list, start = None, end = None) -> (list, float):
  
  start_time = time.time() # Início do contador de tempo
   
  for i in range(1, len(V)):
    for j in range(0, len(V) - i):

      # Incremento do número de comparações
      global number_of_comparisons
      number_of_comparisons += 1

      # Comparação e troca
      if V[j] > V[j+1]:
        Aux = V[j]
        V[j] = V[j+1]
        V[j+1] = Aux
        
        # Incremento do número de trocas
        global number_of_swaps
        number_of_swaps += 1
  
  return V, (time.time() - start_time)



# MergeSort

# Função merging (junção das listas)
def merging(V: list, start: int, mid: int, end: int):
  
  i = k = start
  j = mid + 1
  Aux = [None] * len(V)
  while ((i <= mid) and (j <= end)):
    
    # Incremento do número de comparações
    global number_of_comparisons
    number_of_comparisons += 1

    # Comparação e cópia para o vetor auxiliar
    if (V[i] < V[j]):
      Aux[k] = V[i]
      i += 1
    
    else:
      Aux[k] = V[j]
      j += 1

      # Incremento do número de trocas
      global number_of_swaps
      number_of_swaps += 1
      
    k += 1
    
  #Cópia dos elementos restantes do vetor
  if (i > mid): 
    while (j <= end): 
      Aux[k] = V[j]
      j += 1
      k += 1
      
  else:
    while (i <= mid):
      Aux[k] = V[i]
      i += 1
      k += 1

  #Cópia do vetor auxiliar para o vetor original    
  for k in range(start, k):
    V[k] = Aux[k]
  
def mergeSort(V: list, start, end) -> (list, float):
  
  # Início do contador de tempo
  start_time = time.time()  

  #Chamada recursiva da função mergeSort()
  if start < end:
    
    half = (start + end) // 2
    mergeSort(V, start, half)        
    mergeSort(V, half + 1, end)
    merging(V, start, half, end)

  return V, (time.time() - start_time)


'''O algoritmo abaixo (BucketSort) em si não realiza comparações ou trocas.
   Todas as comparações e trocas são realizadas após a etapa de separação 
   dos valores nos buckets, as quais são operadas pelo algoritmo BubbleSort
   neste caso, ao qual se referem os números de trocas e comparações exibidos
   ao fim da execução do programa'''

#BucketSort
def bucketSort(V: list, start = None, end = None) -> (list, float):
  
  # Início do contador de tempo
  start_time = time.time()
  
  #Vetor de buckets
  BucketVector = []
  
  #Determinação do valor máximo
  if V:
    maxValue = V[0]
  
  else:
    return V, (time.time() - start_time)

  for i in range(1, len(V)):     # Laço para encontrar o valor
    if V[i] > maxValue:          # máximo do vetor
      maxValue = V[i]
  
  # Quantidade de buckets
  for i in range(len(V)):
    BucketVector.append([])

  # Separação dos valores nos buckets
  for i in range(len(V)):
    BucketVector[(len(V) * V[i]) // (maxValue + 1)].append(V[i])
  
  # Ordenação dos buckets
  for i in BucketVector:
    bubbleSort(i)

  # Concatenação dos buckets
  Sorted_Vector = []
  for x in BucketVector:
    Sorted_Vector += x

  V = Sorted_Vector
  return V, (time.time() - start_time)



# Seleção de algoritmo
print("| Algoritmos de ordenação |\n\nSelecione um dos algoritmos de ordenação \
abaixo:\n\nDigite um dos números abaixo para selecionar seu respectivo algoritmo \
de ordenação:\n\n1 - BubbleSort\n2 - MergeSort\n3 - BucketSort")

# Dicionário de opções dos algoritmos de ordenação
algorithms = {1 : "BubbleSort",
              2 : "MergeSort",
              3 : "BucketSort"}


# Opção para ordenação segundo um dos algoritmos
while True: 
  alg_option = int(input("\nAlgoritmo: "))
  
  if alg_option in algorithms:
    print(f"\nAlgoritmo selecionado: {algorithms[alg_option]}")
    break

  else:
    print("Opção inválida inserida. Tente novamente.")



# Tipo do vetor
print("\nEscolha o tipo do vetor a ser ordenado: \n\n1 - Vetor ordenado de \
forma \033[1mdecrescente\033[0m \n2 - Vetor ordenado de forma \033[1maleatória\033[0m")


#Dicionário de opções de tipos de vetor
vector_types = {1 : "Decrescente",
                2 : "Aleatório"  }

while True: #Validação de entrada
  while True:
    try:
      vector_type_option = int(input("\nTipo do vetor: "))
    
    except ValueError:
      print("Opção inválida inserida. Tente novamente.")
    
    else:
      break

  if vector_type_option in vector_types:
    print(f"Tipo selecionado: {vector_types[vector_type_option]}")
    break

  else:
    print("Opção inválida inserida. Tente novamente.")


# Tamanho do vetor
print("\nEscolha o tamanho do vetor a ser ordenado: \n\n1 - 10 elementos\n\
2 - 100 elementos\n3 - 1000 elementos\n4 - 10000 elementos\n5 - 100000 elementos")

while True: #Validação de entrada
  while True:
    try:
      vector_size_option = int(input("\nOpção de tamanho do vetor: "))
    
    except ValueError:
      print("Opção inválida inserida. Tente novamente.")
    
    else:
      break

  if vector_size_option in range(1, 6):
    print(f"Tamanho selecionado: {10 ** vector_size_option} elementos\n")    
    break

  else:
    print("Opção inválida inserida. Tente novamente.")



# Intervalo de valores do vetor
print("\nEscolha o intervalo de valores para o vetor:")

while True: # Validação de entrada
  while True:
    try:
      vector_range_lower_bound = int(input("\nO intervalo do vetor irá de: "))
    
    except ValueError:
      print('Valor inválido inserido. Tente novamente.\n')

    else:
      break

  while True:
    try:
      vector_range_upper_bound = int(input("até: "))
    
    except ValueError:
      print('Valor inválido inserido. Tente novamente.\n')

    else:
      break

  if vector_range_lower_bound > vector_range_upper_bound:
    print("\nO limite inferior do intervalo do vetor não \
deve ser maior que o limite superior. Tente novamente.")
    
  elif (vector_range_upper_bound - vector_range_lower_bound + 1) < 10 ** vector_size_option:
    print("\nNão há valores distintos suficientes para ocupar \no tamanho do \
vetor escolhido dentro do intervalo \nselecionado. Selecione outro intervalo.")
    
  else:
    break



# Geração e ordenação do vetor

# Dicionário de funções (algoritmos)
algorithm_functions = {1 : bubbleSort,
                       2 : mergeSort,
                       3 : bucketSort}
                  
def Vector_generation_sorting(alg_option: int, 
                              vector_type_option: int, 
                              vector_size_option: int):
  
  # Geração de vetor
  Vector = rd.sample(range(vector_range_lower_bound, vector_range_upper_bound + 1), 10 ** vector_size_option)
  
  
  if vector_type_option == 1:   # Ordena a lista de valores aleatórios
    Vector.sort(reverse = True) # em ordem decrescente
    
  
  while True: #Opção para apresentar os valores do vetor de entrada
    print_vector = input("\nDeseja printar o vetor gerado? (S/N): ")

    if print_vector == "s" or print_vector == "S":
      print(f"\nVetor gerado:   {Vector}\n")
      break

    elif print_vector == "n" or print_vector == "N":
      break

    else:
      print("Opção inválida.")


  # Valores retornados pelo algoritmo selecionado
  ordered_vector, elapsed_time = algorithm_functions[alg_option](Vector, 0, len(Vector) - 1)

  # Impressão dos dados referentes à execução
  print(f"Vetor ordenado: {ordered_vector}\n\n\
Número de comparações: {number_of_comparisons} comparações\n\
Número de trocas: {number_of_swaps} trocas\n\
Tempo de execução: {elapsed_time:.8f} segundos")

Vector_generation_sorting(alg_option, vector_type_option, vector_size_option)
