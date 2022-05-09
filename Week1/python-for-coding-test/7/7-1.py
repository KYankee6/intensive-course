def sequnetial_search(n, target, array):
    for i in range(n):
        if array[i] == target:
        	return i + 1 #현재 위치 반환, 인덱스 + 1