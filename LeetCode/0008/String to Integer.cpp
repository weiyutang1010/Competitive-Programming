#include <cmath>
using namespace std;

class Solution {
public:  
    int myAtoi(string str) {
      string new_string = "";
      for(int i = 0; i < str.size(); i++) {
        
        while(str[i] == ' ') {
          i++;
          if(str[i+1] == NULL) {
            return 0;
          }
        }
        
        int current_number_ascii = (int)str[i];
        int next_number_ascii = (int)str[i + 1];
        bool is_number = current_number_ascii >= 48 && current_number_ascii <= 57;
        bool not_a_number = (current_number_ascii < 48 || current_number_ascii > 57);
        bool not_a_negative_and_positive_sign = (str[i] != '-') && (str[i] != '+');
        
        
        if(not_a_number && not_a_negative_and_positive_sign) {
          return 0;
        } else {
          new_string += str[i];
        }
        
        if((next_number_ascii < 48 || next_number_ascii > 57)){
          break;
        }
      }
      
      int i = 0;
      int init_zero_count = 0;
      while(new_string[i] == '0' || new_string[i] == '-') {
        init_zero_count++;
        i++;
      }
      
      if(new_string.length()-init_zero_count > 11 && new_string [0] == '-'){
        return (pow(2, 31) * -1);
      } else if(new_string.length()-init_zero_count > 11){
        return pow(2, 31) - 1;
      }
        
      int char_to_int;
      long new_num = 0;
      if (new_string [0] == '-') {
        for (int i = 1; i < new_string.size(); i++) {
        char_to_int = (int)new_string[i];
        char_to_int -= 48;
        new_num += char_to_int * pow(10, new_string.size() - (i + 1));
        }
        new_num *= -1;
      } else if (new_string [0] == '+') {
        for (int i = 1; i < new_string.size(); i++) {
        char_to_int = (int)new_string[i];
        char_to_int -= 48;
        new_num += char_to_int * pow(10, new_string.size() - (i + 1));
        }
      } else{
        for (int i = 0; i < new_string.size(); i++) {
          char_to_int = (int)new_string[i];
          char_to_int -= 48;
          new_num += char_to_int * pow(10, new_string.size() - (i + 1));
        }
      }
      
      if(new_num >= pow(2, 31) - 1){
        return (pow(2, 31) - 1);
      } else if(new_num <= pow(2, 31) * -1){
        return (pow(2, 31) * -1);
      } else {
        return new_num;
      }
  }
};