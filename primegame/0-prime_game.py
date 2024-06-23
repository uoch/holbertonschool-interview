#!/usr/bin/python3


def is_prime(num):
    """Check if a number is prime."""
    if num <= 1:
        return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True


def generate_primes_up_to(n):
    """Generate a list of prime numbers up to n using the prime division method."""
    primes = []
    for i in range(2, n + 1):
        if is_prime(i):
            primes.append(i)
    return primes


def build_prime_multiples_dict(n):
    """Build a dictionary where keys are prime numbers and values are lists of their multiples up to n."""
    primes = generate_primes_up_to(n)
    prime_multiples = {}
    for prime in primes:
        multiples = [prime * i for i in range(2, n // prime + 1)]
        prime_multiples[prime] = multiples
    return prime_multiples


def isWinner(x, nums):
    """Determine who the winner of the game is."""
    prime_multiples = build_prime_multiples_dict(max(nums))
    player = 0
    for num in nums:
        if num in prime_multiples:
            player = 1 - player
    return ["Maria", "Ben"][player]
