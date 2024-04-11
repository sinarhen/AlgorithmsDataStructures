def findCrossoverIndexHelper(x, y, left, right):
    if left >= right:
        return -1  # No crossover found

    mid = (left + right) // 2

    if y[mid] <= x[mid] and y[mid + 1] > x[mid + 1]:
        return mid

    if y[mid] > x[mid]:   
        return findCrossoverIndexHelper(x, y, left, mid - 1)  
    else:  
        return findCrossoverIndexHelper(x, y, mid + 1, right) 

def findCrossoverIndex(x, y):
    n = len(x)
    return findCrossoverIndexHelper(x, y, 0, n - 1)
