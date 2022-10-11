import numpy as np

n=2
M = np.random.randint(1,50,(n,n))#(min,max,(rows,cols))
M2 = np.random.randint(1,50,(n,n))
V =  np.random.randint(1,50,(n,1))
V2 = np.random.randint(1,50,(n,1))

print("Printando os valores(M,M2,V e V2): ",M,"\n\n",M2,"\n\n",V,"\n\n",V2,"\n\n")
# 1 - Implemente a operação de produto interno.
def produto_interno(V, V2,n):
  v = V.shape
  b=0
  resp = 0
  for i in range(n):
    resp += V[i] * V2[i]
  return resp 

print("PRODUTO INTERNO: ",produto_interno(V, V2,n),"\n")

#---------------------//-----------------//------------------------

# 2 - Implemente a operação de multiplicação matriz-vetor entre uma matriz nxn 
# e um vetor nx1 de dois modos:

#a. Linhas por colunas
def linha_coluna_vetor(M,V,n):
  m = M.shape
  v = V.shape
  b = np.zeros((n,1))
  
  for i in range(m[0]):
    resp = 0
    for j in range(v[0]):
      resp += M[i,j] * V[j]
    b[i] = resp
  return b

print("LINHA-COLUNA-VETOR: ",linha_coluna_vetor(M,V,n),"\n")

#b. Colunas por linhas
def coluna_linha_vetor(M,V,n): 
  m = M.shape
  v = V.shape
  b = np.zeros((n,1))
  
  for i in range(M.shape[1]):
    resp = 0
    for j in range(V.shape[0]):
      resp += M[i,j] * V[j]
    b[i] = resp
  return b

print("COLUNA-LINHA-VETOR",coluna_linha_vetor(M,V,n),"\n")
#------------------------//---------------------//---------------------------

# 3 - Implemente a operação de multiplicação matriz-matriz
def linha_coluna_matriz(M,M2):
  m = M.shape
  v = M2.shape
  b = np.zeros(M.shape)
  
  for i in range(M.shape[0]):
    resp = 0
    for j in range(M2.shape[0]):
      resp += M[i,j] * M2[j]
    b[i] = resp
  return b

print("LINHA-COLUNA-MATRIZ: ",linha_coluna_matriz(M,M2),"\n")



