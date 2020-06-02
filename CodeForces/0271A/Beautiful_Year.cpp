bool is_distinct(int num) {
    set<int> digits; //will automatically remove duplicate by using set
    int count = 0; //count how many digits

    for (count = 0; num > 0; count++) {
        digits.insert(num % 10); //get last digit
        num /= 10; //remove last digit
    }
    return (int)digits.size() == count; //if size = count, it means no duplicate has appeared
}

void solve() {
    int num;
    cin >> num;
    num++;

    while (!is_distinct(num)) { //check if digit is distinct
        num++; //if not increase by one
    }
    cout << num << "\n";
}