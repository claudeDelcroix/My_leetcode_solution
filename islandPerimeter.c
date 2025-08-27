// my solution with 6 ms runtime and memory 15.14 mb
int getNumberSide(const int* arr,const int* size_array){
    int carre = 0;
    int voisin = 0;
    for(int i = 0;i < *size_array;i++){
        if(arr[i] == 1){
            carre++;
        }
        if(i+1 < *size_array && arr[i] == 1 && arr[i+1] == 1){
            voisin++;
        }
    }
    return abs(carre*4 - voisin*2);
}

void getPerimetre(int* array,int* size_array,const int* arr1,const int* arr2,const int* size_arr,const int index){
    for(int i = 0;i < *size_arr;i++){
        if(arr1[i] == 1 && arr2[i] == 1){
            array[index] -= 1;
            array[index+1] -= 1;
        }
    }
}

int islandPerimeter(int** grid,int gridSize,const int* gridColsize){
    if(gridSize == 1 && *gridColsize == 1){
        return grid[0][0] == 1 ? 4:0;
    }
    int* result_array = (int*) calloc(gridSize,sizeof(int));
    if(result_array == NULL){
        fprintf(stderr,"Error allocation\n");
        exit(EXIT_FAILURE);
    }
    int size_array = 0;
    //recupere les valeurs de chaque case selon le fait qu'il soit voisinee ou pas

    for(int i = 0;i < gridSize;i++){
        result_array[size_array] = getNumberSide(grid[i],gridColsize);
        size_array +=1;
    }

    //calculer et modifier chaque case du tableau
    int index = 0;
    for(int i = 1;i < gridSize;i++){
        getPerimetre(result_array,&size_array,grid[i-1],grid[i],gridColsize,index);
        index++;
    }
    // calcul de la somme
    int perimetre = 0;
    for(int i = 0;i < size_array;i++){
        perimetre += result_array[i];
    }
    free(result_array);
    return perimetre;
}


//solution with 0 ms 

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int m = gridColSize[0];
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1){
                sum += 4;
                if((j<m-1)&&(grid[i][j+1] == 1)){
                    sum = sum -1;
                }if((j>0)&&(grid[i][j-1] == 1)){
                    sum = sum - 1;
                }if((i<n-1)&&(grid[i+1][j] == 1)){
                    sum = sum - 1;
                }if((i>0)&&(grid[i-1][j] == 1)){
                    sum = sum - 1;
                }
            }
        }
    }
    return sum;
}

// a other 
int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int p = 0;
    int r = gridSize;
    int c = *gridColSize;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 1) {
                p += 4;
                if (i > 0 && grid[i - 1][j] == 1) p -= 2;
                if (j > 0 && grid[i][j - 1] == 1) p -= 2;
            }
        }
    }
    return p;
}
//a other 

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int islands = 0, neighbors = 0;
    int m = gridSize, n = gridColSize[0];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                islands++;
                // check upward neighbor
                if (i > 0 && grid[i - 1][j] == 1) neighbors++;
                // check left neighbor
                if (j > 0 && grid[i][j - 1] == 1) neighbors++;
            }
        }
    }
    return islands * 4 - neighbors * 2;
}
