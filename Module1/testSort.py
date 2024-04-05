


test_array = [i for i in range(6, 0, -1)]  



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
    if (right <= left):
        return
    if (right == left + 1):
        if (arr[left] > arr[right]):
            arr[left], arr[right] = arr[right], arr[left]
        return
    mid = (left + right) // 2
    mergeSort(arr, left, mid)
    mergeSort(arr, mid + 1, right)
    merge(arr, left, mid, right)












# def mergeSort(arr, left, right):
#     if (left >= right):
#         return
#     if right - left == 1:
#         if arr[right] < arr[left]:
#             arr[left], arr[right] = arr[right], arr[left]
#         return
#     else:
#         mid = (left + right) // 2
#         mergeSort(arr, left, mid)
#         mergeSort(arr, mid + 1, right)
#         merge(arr, left, mid, right)


def merge(arr, left, mid, right):
    i = left
    j = mid + 1
    tmp = []
    print("First subarray: ", arr[i:mid+1])
    print("Second subarray: ", arr[j:right + 1])
    while i <= mid and j <= right:
        if arr[i] < arr[j]:
            print(f"Comparing {arr[i]} from first subarray and {arr[j]} from second subarray.")
            print(f"{arr[i]} is smaller, so add it to the temporary array.")
            tmp.append(arr[i])
            i += 1
        else:
            print(f"Comparing {arr[i]} from first subarray and {arr[j]} from second subarray.")
            print(f"{arr[j]} is smaller, so add it to the temporary array.")
            tmp.append(arr[j])
            j += 1
        print("Temporary array after this step: ", tmp)
    while i <= mid:
        print(f"All elements from second subarray are added. Add remaining elements from first subarray: {arr[i]}")
        tmp.append(arr[i])
        i += 1
    while j <= right:
        print(f"All elements from first subarray are added. Add remaining elements from second subarray: {arr[j]}")
        tmp.append(arr[j])
        j += 1
    print("Temporary array after adding remaining elements: ", tmp)
    for k in range(right - left + 1):
        arr[left + k] = tmp[k]
    print("Final sorted array for this merge step: ", arr[left:right+1])


mergeSort(test_array, 0, len(test_array) - 1)
print(test_array)


