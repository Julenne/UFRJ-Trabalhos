import numpy as np

def troca(M, i, j):
  linha_1 = np.copy(M[i])
  linha_2 = np.copy(M[j])

  M[i, :] = linha_2
  M[j, :] = linha_1

  return M

def divide_linha(M, i, k):
  M[i, :] = M[i, :] / k
  return M

def subtrai_linha(M, i, j, k):
  M[i, :] = M[i, :] - (k * M[j, :])
  return M

def acha_pivo(M, i):
  linha_pivo = None
  coluna_pivo = None

  for l in range(M.shape[0]): #linha
    if linha_pivo != None:
      break
    for c in range(M.shape[1]): #coluna
      
      #print(M[l,c], "=","(",l,",",c,")")
      #print(M[l,c] != 0.0)
      #print(c==i)
      
      if M[l,c] != 0.0:
        if c == i:
          linha_pivo = l
          coluna_pivo = c   
          break
        break
          
  if coluna_pivo == i:
    return linha_pivo
  else:
    return None

def gauss_jordan(A, b):
  C = np.column_stack((A,b))
  linha = 0
  coluna = 0
  while(linha < C.shape[0] and coluna < C.shape[1]):
    pivo = acha_pivo(C, coluna)
    if pivo != None:
      if pivo != linha:
        troca(C, pivo, linha)
      if C[linha,coluna] != 1:
        divide_linha(C, pivo, C[linha,coluna])
      for l in range(C.shape[1]):
        if C[l, coluna] > 0 and l != pivo:
          subtrai_linha(C, l, pivo, C[l,coluna])
      linha = linha + 1
      coluna = coluna + 1
    else:
        coluna = coluna + 1
  return C

### EXEMPLO:

K = np.array([[1., 2., 5., 1.],
              [1., 2., 5., 2.],
              [1., 2., 5., 3.],
              [1., 2., 5., 4.],
              [1., 2., 5., 5.]])
              
t = np.array([21.,22.,23.,24.,25.])

print(gauss_jordan(K, t))

