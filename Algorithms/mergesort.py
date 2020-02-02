"""
Implementación propia del algoritmo mergeSort
"""

def concatenate(a, b):
	"""
	Funcion que recibe dos listas y las concatena respetando el orden de cada elemento
	"""
	res = []
	i = 0
	j = 0
	while (i < len(a)) or ( j < len(b)):
		if i == len(a):
			res.append(b[j])
			j += 1
		elif j == len(b):
			res.append(a[i])
			i += 1
		else:
			if a[i] < b[j]:
				res.append(a[i])
				i += 1
			else:
				res.append(b[j])
				j += 1
	return res

def divideLst(lst):
	res = []
	mid = len(lst)//2
	i = 0
	while i < mid:
		res.append(lst[i])
		i += 1
	return res, lst[i::]

def mergeSort(lst):
	if len(lst) == 1:
		return lst
	else:
		a, b = divideLst(lst)
		return concatenate( mergeSort(a), mergeSort(b) )

l1 = mergeSort([1, 5, 4, 3, 2, 7, 6])

print(l1)