#define ll long long
const ll MOD = 1e9 + 7;

class Solution {
public:
    ll normalize(const ll a, const ll b = MOD) {
        ll ans = a % b;
        if (ans < 0) {
            ans += b;
        }
        return ans;
    }
    
    ll modpow(ll base, ll exp, ll mod = MOD) {
        base = normalize(base, mod);
        ll ans = 1;
        base %= mod;
        while (exp) {
            if ((exp & 1LL)) {
                ans = (ans * base) % mod;
            }
            exp >>= 1;
            base = (base * base) % mod;
        }
        return ans;
    }
    
    int maxNiceDivisors(int primeFactors) {
        if (primeFactors == 1) return 1;
        int64_t num_3 = 0, num_2 = 0;
        if (primeFactors % 3 == 1) {
            primeFactors -= 4;
            num_2 += 2;
        } else if (primeFactors % 3 == 2) {
            primeFactors -= 2;
            num_2 += 1;
        }
        
        num_3 = primeFactors / 3;
        
        return (modpow(2, num_2) * modpow(3, num_3)) % MOD;
    }
};