"""
Implementación propia del algoritmo mergeSort
"""

def concatenate(a, b):
	"""
	Funcion que recibe dos listas y las concatena respetando el orden de cada elemento
	"""
	res = []
	while a or b:
		if not a:
			res.append(b.pop(0))
		elif not b:
			res.append(a.pop(0))
		else:
			a1 = a[0]
			b1 = b[0]
			if a1 < b1:
				res.append(a1)
				a.pop(0)
			else:
				res.append(b1)
				b.pop(0)
	return res

def divideLst(lst):
	res = []
	mid = len(lst)//2
	i = 0
	while i < mid:
		res.append(lst.pop(0))
		i += 1
	return res, lst

def mergeSort(lst):
	if len(lst) == 1:
		return lst
	else:
		a, b = divideLst(lst)
		return concatenate( mergeSort(a), mergeSort(b) )

l1 = mergeSort([1, 5, 4, 3, 2, 7, 6])

print(l1)