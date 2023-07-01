class Solution {
    int[] primes = new int[5000005];
    int cnt = 0;
    Boolean[] p = new Boolean[5000005];

    public int countPrimes(int n) {
        isprimes(n);
        return cnt;
    }

    private void isprimes(int n) {
        p[1] = true;
        for (int i = 2; i <= n; i++) {
            if (!p[i])
                primes[cnt++] = i;
            for (int j = 0; i * primes[j] <= n; j++) {
                p[i * primes[j]] = true;
                if (i % primes[j] == 0)
                    break;
            }
        }
    }
}