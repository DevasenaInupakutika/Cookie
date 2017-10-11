max_n = 5005
mod = 998244353


fact = [1 for _ in xrange(max_n)]
for i in xrange(1, max_n):
    fact[i] = i * fact[i - 1]


def mod_rev(x):
    return pow(x, mod - 2, mod)


def mod_com(n, m):
    return fact[n] * mod_rev(fact[n - m] * fact[m]) % mod


# a, b, c = map(int, raw_input().split(' '))
a, b, c = 500, 500, 500

ans = 1
for x, y in [(a, b), (b, c), (c, a)]:
    num = 0
    for k in xrange(min(x, y) + 1):
        num += mod_com(x, k) * mod_com(y, k) * fact[k] % mod
    ans *= num
print ans % mod

ans = 1
for x, y in [(a, b), (b, c), (c, a)]:
    ans *= mod_com(max(x, y), min(x, y))
print ans % mod
