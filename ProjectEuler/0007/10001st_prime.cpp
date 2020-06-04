// To check if a number is prime, we only have to check it against all the previous prime numbers.
// That is because numbers that are not prime can be written as multiply(composite) of prime numbers.

void solve() {
    vector<int> primes {2, 3};

    int current_value = 3;
    while (primes.size() < 10001) {
        bool found_prime = true;
        current_value += 2; //Add 2 because prime number can only be odd
        for (int i = 0; i < (int)primes.size(); i++) {
            if (current_value % primes[i] == 0) { //Check against all the previous prime numbers
                found_prime = false;
                break;
            }
        }
        if (found_prime) {
            primes.push_back(current_value); //If it is prime we add to our list of primes
        }
    }
    cout << primes[10000] << "\n"; //print the 10001st element
}
