class operand {
    public:
        char type;
        int n1;
        int n2;

        operand() {
            n1 = INT_MIN;
            n2 = INT_MIN;
        }

        bool has_missing() {
            return n1 == INT_MIN || n2 == INT_MIN;
        }

        void push_num(int num) {
            if (n1 == INT_MIN) {
                n1 = num;
            } else {
                n2 = num;
            }
        }

        int get_num() {
            if (type == '+') {
                return n1 + n2;
            } else if (type == '-') {
                return n1 - n2;
            } else if (type == '*') {
                return n1 * n2;
            } else {
                return n1 / n2;
            }
        }
};

int solve(string s) {
    int n = s.size();
    // to be used similar to a stack
    vector<operand> v;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            // push operation and its type '+', '-', '*', or '/'
            operand x;
            x.type = s[i+1];
            v.push_back(x);
            i++;
        } else if (s[i] == ')') {
            // Get the number after performing the operation
            operand value = v.back();
            int num = value.get_num();
            v.pop_back();

            // If there is still other operand (outer bracket),
            // fill the value into the other operation
            int idx = (int)v.size() - 1;
            if (idx >= 0) {
                while (!v[idx].has_missing()) {
                    idx--;
                }
                v[idx].push_num(num);
            } else {
                // no more operation left
                ans = num;
            }
        } else if (s[i] != ' ') {
            // if number is character
            int is_negative = 1;
            if (s[i] == '-') {
                is_negative = -1;
                i++;
            }

            // read all digits
            int num = 0;
            while (isdigit(s[i])) {
                num *= 10;
                num += s[i] - '0';
                i++;
            }
            i--; // to avoid skipping closing bracket

            // push number into operation
            v.back().push_num(num * is_negative);
        }
    }

    return ans;
}