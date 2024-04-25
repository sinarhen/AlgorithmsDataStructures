import time


desc_array = [i for i in range(10000, 0, -1)]  # worst case for ascending
asc_array = [i for i in range(1, 10000)]  # best case for ascending

# decorator for time calculation
def time_it(func):
    def wrapper(*args, **kwargs):
        start = time.time()
        result = func(*args, **kwargs)
        end = time.time()
        print(func.__name__ + " took " + str((end - start) * 1000) + " mil sec")
        return result
    return wrapper


@time_it
def insertion_sort_desc(arr):
    length = len(arr)
    for i in range(1, length):
        if (arr[i] > arr[i-1]):
            j = i
            while (j > 0 and arr[j] > arr[j - 1]):
                arr[j], arr[j - 1] = arr[j - 1], arr[j]
                j -= 1
    return arr

@time_it
def insertion_sort_asc(arr):
    length = len(arr)
    for i in range(1, length):
        if (arr[i] < arr[i-1]):
            j = i
            while (j > 0 and arr[j] < arr[j - 1]):
                arr[j], arr[j - 1] = arr[j - 1], arr[j]
                j -= 1
    return arr


#best cases
insertion_sort_desc(desc_array)
insertion_sort_asc(asc_array)

#worst cases
insertion_sort_desc(asc_array)
insertion_sort_asc(desc_array)

# SO Big O is O(n^2) for worst case and O(n) for best case

