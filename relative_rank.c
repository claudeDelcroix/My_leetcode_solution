// 71 ms
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void swap(int* xp,int* yp) {
    const int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int partition(int arr[],int low,int high) {
    const int pivot = arr[high];
    int i = (low - 1);

    for(int j = low;j < high;j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i + 1;
}

void quickSort(int arr[],int low,int high) {
    if(low < high) {
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi -1);
        quickSort(arr,pi + 1,high);
    }
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
        char** result = (char**)malloc(scoreSize*sizeof(char*));
    if (!result) {
        fprintf(stderr,"Echec allocation\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0;i < scoreSize;i++) {
        result[i] = (char*)malloc(20*sizeof(char));
    }

    int copy[scoreSize];
    for (int i = 0;i < scoreSize;i++) {
        copy[i] = score[i];
    }
    int index = 0;
    quickSort(copy,0,scoreSize-1);
  for (int i = 0; i < scoreSize; i++) {
    index = -1;
    for (int j = 0; j < scoreSize; j++) {
        if (score[i] == copy[j]) {
            index = j;
            break;
        }
    }

   int rank = scoreSize - index;
   if (rank == 1) {
        strcpy(result[i], "Gold Medal");
    } else if (rank == 2) {
        strcpy(result[i], "Silver Medal");
    }else if (rank == 3) {
        strcpy(result[i], "Bronze Medal");
    } else {
        sprintf(result[i], "%d", rank);
    }
    }
    *returnSize = scoreSize;
    return result;
}


//0 ms 

typedef struct {
    int score;
    int index;
} Player;

int cmp(const void* a, const void* b) {
    const Player* pa = (const Player*)a;
    const Player* pb = (const Player*)b;
    return pb->score - pa->score;  
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    *returnSize = scoreSize;
    Player* arr = malloc(sizeof(Player) * scoreSize);
    for (int i = 0; i < scoreSize; i++) {
        arr[i].score = score[i];
        arr[i].index = i;
    }

    qsort(arr, scoreSize, sizeof(Player), cmp);

    char** result = malloc(sizeof(char*) * scoreSize);
    for (int i = 0; i < scoreSize; i++) {
        result[arr[i].index] = malloc(20);
        if (i == 0)
            strcpy(result[arr[i].index], "Gold Medal");
        else if (i == 1)
            strcpy(result[arr[i].index], "Silver Medal");
        else if (i == 2)
            strcpy(result[arr[i].index], "Bronze Medal");
        else
            sprintf(result[arr[i].index], "%d", i + 1);
    }

    free(arr);
    return result;
}
