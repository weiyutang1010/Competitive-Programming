bool solve(int x) {
    if (x < 0) {
        return false;
    } else if (x < 10) {
        return true;
    } else if (x % 10 == 0) {
        return false;
    }
    
    int digit = 0, temp = x;
    while (temp) {
        temp /= 10;
        digit++;
    }
    
    int i = 1;
    while (x > 9) {
        //compare first and last digit
        if ((x % 10) != (x / (int)pow(10, digit - (2 *i) + 1))) {
            return false;
        } 
        
        // if 2nd digit is 0, check if 2nd last digit is also 0
        else if ((x / (int)pow(10, digit - (2 *i))) % 10 == 0) {
            if ((x % 100) /10 != 0) {
                return false;
            }
        }
        
        // remove 1st and last digit
        x /= 10;
        x = x % (int)pow(10, digit - (2 * i));
        i++;
    }
    
    return true;
}