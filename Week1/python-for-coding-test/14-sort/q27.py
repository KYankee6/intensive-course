def binary_counter(array, x):
    n = len(array)
    a = first(array,x,0,n-1)
    if a ==None:
        return 0
    b = last(array,x,0,n-1)
    return b-a+1


def first(array, target, start, end):
    if start > end:
        return None
    mid = (start + end) // 2
    if target <= array[mid]:
        end = mid - 1
        return first(array, target, start, end)

    elif target < array[mid]:
        start = mid + 1
        return first(array, target, start, end)

    else:
        if mid == 0 or target > array[mid - 1]:
            return mid


def last(array, target, start, end):
    if start > end:
        return None
    mid = (start + end) // 2
    if target <= array[mid]:
        return last(array, target, start, mid - 1)
    elif target > array[mid]:
        return last(array, target, mid + 1, end)
    else:
        if mid == n - 1 or target > array[mid + 1]:
            return mid