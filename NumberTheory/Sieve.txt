const int MAX_LIMIT = 1500000;
bool is_prime[MAX_LIMIT + 1];
vector<int> primes;

void sieve() {
    fill(is_prime + 2, is_prime + MAX_LIMIT + 1, true);
    for (int p = 2; p * p <= MAX_LIMIT; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= MAX_LIMIT; i += p)
                is_prime[i] = false;
        }
    }
    for (int p = 2; p <= MAX_LIMIT; p++) {
        if (is_prime[p]) primes.push_back(p);
    }
}