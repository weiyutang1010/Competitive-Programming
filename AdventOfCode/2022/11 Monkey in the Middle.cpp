/*
 * author: weiyutang
 */

#include <bits/stdc++.h>
using namespace std;

/* ===== BEGIN USER CODE ===== */

#define ll long long
#define ld long double
#define f first
#define s second
#define endl "\n"

const int MOD = 1e9 + 7;
const vector<vector<int>> dirs4 {{0,1}, {1,0}, {-1,0}, {0,-1}};
const vector<vector<int>> dirs8 {{0,1}, {1,0}, {-1,0}, {0,-1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};

class Monkey {
private:
    queue<int64_t> items;
    int op; // 1 for multiply, 0 for addition
    int op1, op2; // operands
    int test_divisor;
    int inspect_count; // number of items inspected
    int monkey1, monkey2; // which monkey to throw to

public:
    Monkey() {}

    Monkey(const vector<int>& items, int op, int op1, int op2, int divisor, int monkey1, int monkey2) {
        for (const int item: items) {
            this->items.push(item);
        }

        this->op = op;
        this->op1 = op1;
        this->op2 = op2;
        this->test_divisor = divisor;
        this->monkey1 = monkey1;
        this->monkey2 = monkey2;
        this->inspect_count = 0;
    }

    int64_t operation(int64_t worry_level) {
        int64_t a = op1, b = op2;
        if (a == -1)
            a = worry_level;

        if (b == -1)
            b = worry_level;

        int64_t res = (op ? a * b : a + b);
        return res;
    }

    void receive_item(int64_t worry_level) {
        items.push(worry_level);
    }

    int test_item(int64_t worry_level) {
        if (worry_level % test_divisor == 0) {
            return monkey1;
        }
        return monkey2;
    }
    
    int64_t inspect() {
        inspect_count++;

        int64_t worry_level = items.front();
        items.pop();

        int64_t new_level = operation(worry_level);
        return new_level;
    }

    int get_divisor() const {
        return test_divisor;
    }

    int get_inspect_count() const {
        return inspect_count;
    }

    bool empty() {
        return items.empty();
    }
};

int64_t get_largest_two_count(const vector<Monkey>& monkeys) {
    int64_t count1 = 0, count2 = 0;
    for (const Monkey& monkey: monkeys) {
        int cnt = monkey.get_inspect_count();
        if (cnt > count1) {
            count2 = count1;
            count1 = cnt;
        } else if (cnt > count2) {
            count2 = cnt;
        }
    }

    return count1 * count2;
}

void part2(vector<Monkey> monkeys) {
	int64_t ans = 0;

    int64_t MOD = 1;
    for (const Monkey& monkey: monkeys) {
        MOD *= monkey.get_divisor();
    }

    for (int i = 0; i < 10000; i++) {
        for (Monkey& monkey: monkeys) {
            int next_monkey, next_divisor;
            int64_t new_level;
            while (!monkey.empty()) {
                new_level = monkey.inspect();
                new_level %= MOD;
                next_monkey = monkey.test_item(new_level);
                monkeys[next_monkey].receive_item(new_level);
            }
        }
    }

    ans = get_largest_two_count(monkeys);
	cout << "Part 2: " << ans << endl;
}

void part1(vector<Monkey> monkeys) {
	int ans = 0;

    for (int i = 0; i < 20; i++) {
        for (Monkey& monkey: monkeys) {
            int next_monkey;
            int64_t new_level;
            while (!monkey.empty()) {
                new_level = monkey.inspect() / 3;
                next_monkey = monkey.test_item(new_level);
                monkeys[next_monkey].receive_item(new_level);
            }
        }
    }

	ans = get_largest_two_count(monkeys);
    cout << "Part 1: " << ans << endl;
}

void info_to_monkeys(const vector<vector<string>>& monkey_info, vector<Monkey>& monkeys) {
    for (const vector<string>& info: monkey_info) {
        int n = info.size();

        string token;
        vector<int> starting_items;
        string line = info.at(1);
        stringstream ss1 (line);

        ss1 >> token >> token;
        while (ss1 >> token) {
            if (token.back() == ',')
                token.pop_back();
            starting_items.push_back(stoi(token));
        }

        int op, op1, op2;
        line = info.at(2);
        stringstream ss2 (line);
        ss2 >> token >> token >> token;
        ss2 >> token;
        if (token[0] == 'o')
            op1 = -1;
        else
            op1 = stoi(token);
        
        ss2 >> token;
        op = (token == "*" ? 1 : 0);

        ss2 >> token;
        if (token[0] == 'o')
            op2 = -1;
        else
            op2 = stoi(token);

        int divisor;
        line = info.at(3);
        stringstream ss3 (line);
        ss3 >> token >> token >> token >> token;
        divisor = stoi(token);

        int monkey1, monkey2;
        line = info.at(4);
        stringstream ss4 (line);
        ss4 >> token >> token >> token >> token >> token >> token;
        monkey1 = stoi(token);
        
        line = info.at(5);
        stringstream ss5 (line);
        ss5 >> token >> token >> token >> token >> token >> token;
        monkey2 = stoi(token);

        monkeys.push_back(Monkey (starting_items, op, op1, op2, divisor, monkey1, monkey2));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t = 1;
    //cin >> t;

    int idx = 0;
	string st;
	vector<vector<string>> monkey_info;
    while (getline(cin, st)) {
        if (st.size() == 0) {
            idx++;
            continue;
        }

        if (idx == monkey_info.size())
            monkey_info.push_back(vector<string> ());

	    monkey_info[idx].push_back(st);
    }

    vector<Monkey> monkeys;
    info_to_monkeys(monkey_info, monkeys);

    while (t--) {
        part1(monkeys);
		part2(monkeys);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
