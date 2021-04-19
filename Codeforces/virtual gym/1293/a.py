from sys import stdin

lines = stdin.readlines()
lines.pop(0)

i = 0
tam = len(lines)
res = ""
while i < tam:
  values = lines[i].strip().split()
  nums = lines[i+1].strip().split()
  i += 2
  ##Logica para marcar
  ##values.strip().split(' ')
  ##nums.strip().split(' ')
  values = list(map(int, values))
  nums = list(map(int, nums))
  n = values[0]
  s = values[1]
  array = [1]*n
  for num in nums:
    array[num-1] = 0
  ##Ahora buscar los numeros
  if array[s-1] == 1:
    res += "0\n"
  else:
    left = -1
    right = -1
    steps = 0
    j = s-1
    while j >= 0:
      if array[j] == 1:
        left = steps
        break
      steps += 1
      j-=1
    
    j = s-1
    steps = 0
    while j < n:
      if array[j] == 1:
        right = steps
        break
      steps += 1
      j += 1
    
    ##Ahora agregar a la salida
    if left == -1:
      res += str(right) + "\n"
    elif right == -1:
      res += str(left) + "\n"
    else:
      if left < right:
        res += str(left) + "\n"
      else:
        res += str(right) + "\n"

print(res.strip())