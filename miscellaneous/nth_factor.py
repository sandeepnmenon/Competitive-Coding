import math

# find pth factor of a number


def get_pth_factor(num, p):
    factors_first = []
    factors_second = []
    for i in range(1, math.ceil(math.sqrt(num))+1):
        if num % i == 0:
            if i*i != num:
                factors_first.append(i)
                factors_second.append(num // i)
            else:
                factors_first.append(i)

    factors = factors_first + factors_second[::-1]
    print(factors_first, factors_second[::-1])
    return factors[p - 1]

# Remove anagrams from a list


def count_sort_string(lst):
    count = [0] * 26
    for i in lst:
        count[ord(i) - ord('a')] += 1
    # Create the sorted string from the count array
    sorted_string = ''
    for i in range(len(count)):
        sorted_string += chr(i + 97) * count[i]
    return sorted_string


def remove_anagrams(string_lst):
    hash_check = {}
    result = []
    for string in string_lst:
        sorted_string = count_sort_string(string)
        if sorted_string not in hash_check:
            hash_check[sorted_string] = sorted_string
            result.append(string)
    return sorted(result)
