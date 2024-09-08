#include <stdio.h>
#include <stdlib.h>


int lengthOfLastWord(char* s) {
    int t = strlen(s) - 1, i = 0;
    if(s[t] == ' '){
        while(s[t] == ' '){
            t--;
        }
    }
     while(s[t]!=' '){
        i++;
        if(t == 0)break;
        t--;
     }

     return i;
}

int main(){
  int number = 0;
  char* s = "hey world";
  number = lengthOfLastWord(s);

  return 0;
}
