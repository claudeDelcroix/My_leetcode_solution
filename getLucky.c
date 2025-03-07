//la fonction transforme premierement une chaine de caractere en chaine de chiffre qui 
//forme un seul nombre et ensuite calcule la sommme des chiffre de ce nombre 
//et repete ce schema K fois et ensuite retourne la sommme 



int giveTHeNumbers(const char s) {
    switch (s) {
        case 'a' :
            return 1;
        case 'b' :
            return 2;
        case 'c' :
            return 3;
        case 'd' :
            return 4;
        case 'e' :
            return 5 ;
        case 'f' :
            return 6;
        case 'g' :
            return 7;
        case 'h' :
            return 8;
        case 'i' :
            return 9;
        case 'j' :
            return 10;
        case 'k' :
            return 11;
        case 'l' :
            return 12;
        case 'm' :
            return 13;
        case 'n' :
            return 14;
        case 'o' :
            return 15;
        case 'p' :
            return 16;
        case 'q' :
            return 17;
        case 'r' :
            return 18;
        case 's' :
            return 19;
        case 't' :
            return 20;
        case 'u' :
            return 21;
        case 'v' :
            return 22;
        case 'w' :
            return 23;
        case 'x' :
            return 24;
        case 'y' :
            return 25;
        case 'z' :
            return 26;
        default:
            return 0;
    }
}

void stringLetterToStringDigit(const char* s,char* newS) {
    int count = 0;
    for(int i = 0;i < strlen(s);i++) {
        if(giveTHeNumbers(s[i]) < 10) {
            newS[count] = giveTHeNumbers(s[i]) + '0';
            count++;
        }else {
            int digit = giveTHeNumbers(s[i]);
            const char secondL = digit%10 + '0';
            digit /= 10;
            const char firstL = digit + '0';
            newS[count] = firstL;
            count++;
            newS[count] = secondL;
            count++;
        }
    }
    newS[count] = '\0';
}

int getLucky(char* s, int k) {
    char *num = (char*)malloc(500*sizeof(char));
    if(num == NULL) {
        fprintf(stderr,"allocation failled\n");
        exit(EXIT_FAILURE);
    }
    stringLetterToStringDigit(s,num);
    int sum = 0;
    for(int i = 0;i < strlen(num);i++) {
        sum += num[i] - '0';
        printf("sum : %d \n",sum);
    }
    printf("the sum : %d\n",sum);
    if(k == 1) {
        return sum;
    }

    for(int i = 0;i < k-1;i++) {
        int cpy = sum;
        sum = 0;
        while(cpy > 0) {
            sum += cpy%10;
            cpy /= 10;
        }
    }
    free(num);
    return sum;
}

//version du code avec 0ms 

#include<string.h>
int getLucky(char* s, int k) {
    int i,j,a,sum=0,b,c=0,d=0;
    a=strlen(s);
    for(i=0;i<a;i++){
       j=s[i]-96;
      
       if(j<=9){
       sum+=j;
       } 
       else
    {
        b=j%10;
        j=j/10;
        sum+=b+j;
        
    }
    }
if(k>=2){
    c=sum;
        for(i=1;i<k;i++){
           while (c>9) {
            d+= c%10;
            c /= 10;
                          
    } 
     if(d+c>9){
           c=d+c;
            d=0;
           
    }
      
    }
    return d+c;
        }
    return sum;
}

//une autre version de la solution
int getLucky(char* s, int k) {
    char res[1000];
    int ind = 0;
    for(int i = 0; i< strlen(s); i++){
        int num = s[i] - 'a' + 1;
        ind += sprintf(res + ind, "%d", num);
    }
    int sum = 0, n = 0;
    printf("%s", res);

    while(n<k){
        int i = 0;
        sum = 0;
        while(i<strlen(res)){
            sum += res[i] - '0';
            i++;
        }
        sprintf(res, "%d", sum);
    printf("\n%s", res);
        n += 1;
    }

    return sum;
}
