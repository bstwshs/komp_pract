# пятое 1 вариант питон
import random
 
def get_min_array(arr1, arr2):
    return [min(x, y) for x, y in zip(arr1, arr2)]
 
array1 = [random.randint(1, 10) for _ in range(5)]
array2 = [random.randint(1, 10) for _ in range(5)]
result = get_min_array(array1, array2)
print(f"Массив 1: {array1}")
print(f"Массив 2: {array2}")
print(f"Мин Массив: {result}")