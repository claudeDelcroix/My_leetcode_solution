#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome(char* s) {
    int size_s = strlen(s),j = 0,iden = 0, k = 0;
   if(size_s == 1){
        return true;
    }
    char* result_string = (char*)malloc(size_s*sizeof(char));
    for(int i = 0;i<size_s;i++){
        if((s[i]>='a' && s[i]<= 'z') || (s[i]>= '0' && s[i]<='9') || (s[i]>='A' && s[i]<='Z')){
            if((s[i]>='a' && s[i]<= 'z') || (s[i]>= '0' && s[i]<='9')){
                result_string[j] = s[i];
                j++;
            }
            else{
                result_string[j] = tolower(s[i]);
                j++;
            }
        }
    }
    k = j ;
    for(int i = 0;i<j;i++){
        if(result_string[i] == result_string[k-1]){
            iden++;
            k--;
        }
        else{
            break;
        }
    }
free(result_string);
  if(iden == j){
    return true;
  }
  else{
    return false;
  }
}

int main()
{
    char *s= (char*)malloc(4*sizeof(char));
    s = "ALI";
    if(isPalindrome(s)){
        printf("true\n");
    }
    else{
        printf("false");
    }

    return 0;
}
