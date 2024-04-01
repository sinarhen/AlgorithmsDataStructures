


test_array = [i for i in range(100, 0, -1)]  



def insertion_sort(array):
    length = len(array)
    for i in range(1, length):
        if (array[i] > array[i - 1]):
            continue
        else: 
            j = i
            while (j > 0 and array[j] < array[j - 1]):
                array[j], array[j - 1] = array[j - 1], array[j]
                j -= 1

    return array


def mergeSort(arr, left, right):
    if (left >= right):
        return
    if right - left == 1:
        if arr[right] < arr[left]:
            arr[left], arr[right] = arr[right], arr[left]
        return
    else:
        mid = (left + right) // 2
        mergeSort(arr, left, mid)
        mergeSort(arr, mid + 1, right)
        merge(arr, left, mid, right)


def merge(arr, left, mid, right):
    i = left
    j = mid + 1
    tmp = []
    while (i <= mid and j <= right):
        if arr[i] < arr[j]:
            tmp.append(arr[i])
            i += 1
        else:
            tmp.append(arr[j])
            j += 1
        
    while i <= mid:
        tmp.append(arr[i])
        i += 1
    while j <= right:
        tmp.append(arr[j])
        j += 1
         
    for k in range(right - left + 1):
        arr[left + k] = tmp[k]



mergeSort(test_array, 0, len(test_array) - 1)
print(test_array)
