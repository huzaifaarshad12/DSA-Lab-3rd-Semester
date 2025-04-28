# -*- coding: utf-8 -*-
"""
Created on Sun Sep 15 19:30:17 2024

@author: huzai
"""

import random

def RandomArray(size):
    random_array = []
    for i in range(size):
        random_array.append(random.randint(1, 100))  # Generates a random number between 1 and 100
    return random_array


size = 9
result = RandomArray(size)
print(result)
