char* convertToTitle(int columnNumber) {
  int i=0,index=0;
  char arr[20];
  int x=columnNumber;
  while(x>0){
    x--;
    arr[i++] =(x%26 )+'A';
    x /=26;
    printf("%c",arr[index++]);
  }
  char* result = (char*)malloc((i + 1) * sizeof(char));

    // Reverse the string and copy it to the result
    for (int j = 0; j < i; j++) {
        result[j] = arr[i - j - 1];
    }
    result[i] = '\0';  // Null-terminate the string

    return result; 
}
