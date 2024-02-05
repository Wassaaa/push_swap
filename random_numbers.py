import random
import sys

def generate_unique_numbers(n, min_int=-2147483648, max_int=2147483647):
    seen = set()
    while len(seen) < n:
        num = random.randint(min_int, max_int)
        if num not in seen:
            seen.add(num)
            print(num, end=' ')

if __name__ == "__main__":
    n = int(sys.argv[1]) if len(sys.argv) > 1 else 100
    generate_unique_numbers(n)