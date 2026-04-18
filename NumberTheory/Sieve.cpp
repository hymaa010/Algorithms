/* Normal sieve can run up to N = 1e7 */ 
const int N = 1e7 + 1;
int isPr[N];
vector<int> primes;

void sieve(){
    for (int i = 2; i < N; ++i) isPr[i] = 1;
    for (int i = 2; i < N; ++i) {
        if(isPr[i]){
            primes.push_back(i);
            for (int j = i * i; j < N; j += i) {
                isPr[j] = 0;
            }
        }
    }
}


/* same code but saves lp[x] instead of isPr */
const int N = 1e7;
int lp[N];
vector<int> primes;

void sieve(){
    for (int i = 2; i < N; ++i) {
        if(!lp[i]){
            primes.push_back(i);
            for (int j = i * i; j < N; j += i) {
                if(!lp[j]) lp[j] = i;
            }
        }
    }
}

/* Linear Sieve Works on O(N) */

const int N = 1e7;
vector<int> lp(N + 1);
vector<int> primes;
void sieve()
{
    for (int i = 2; i <= N; ++i) {
        if(lp[i] == 0) {
            lp[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; i * primes[j] <= N; ++j) {
            lp[i * primes[j]] = primes[j];
            if (primes[j] == lp[i]) {
                break;
            }
        }
    }
}
