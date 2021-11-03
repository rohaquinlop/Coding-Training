"""
Implementación propia del algoritmo Binary Search o Busqueda binaria
"""

def binarySearch(lst, num):
	"""
	Funcion que busca un número num en una lista lst y retorna el indice en el que se encuentra
	"""
	l, h = 0, len(lst)-1
        while l <= h:
            mid = l + ((h-l)>>1)
            if lst[mid] == num:
                return mid
            elif lst[mid] < num:
                l = mid+1
            else:
                h = mid-1
        return -1

print( binarySearch([1,2,3,4,5,6,7], 7) )
print( binarySearch([1,2,3,4,5,6,7], 6) )
print( binarySearch([1,2,3,4,5,6,7], 5) )
print( binarySearch([1,2,3,4,5,6,7], 4) )
print( binarySearch([1,2,3,4,5,6,7], 3) )
print( binarySearch([1,2,3,4,5,6,7], 2) )
print( binarySearch([1,2,3,4,5,6,7], 1) )
print( binarySearch([1,2,3,4,5,6,7], 0) )
print( binarySearch([1,2,3,4,5,6,7], 9) )
print( binarySearch([1,2,3,4,5,6,7], 8) )
