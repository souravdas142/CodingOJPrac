import itertools
import os

digits = list(range(0, 10))
url = "https://rms01.realme.net/sw/RMX3471export_11_C.16_2023061220240"

for permutation in itertools.product(digits, repeat=3):
    permutation_list = [str(digit) for digit in permutation]
    permutation = "".join(permutation_list)
    permutation = int(permutation)
    #urlPermute = url.join(permutation)
    print(permutation)
    print("\n")
