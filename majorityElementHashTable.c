#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int weight;
} hesmep;

// Fungsi untuk melakukan merging dua array yang telah terurut
void merge(hesmep* arr, hesmep* temp, int left, int mid, int right) {
    int i = left;   // Indeks untuk subarray kiri
    int j = mid + 1; // Indeks untuk subarray kanan
    int k = left;   // Indeks untuk array sementara temp[]

    // Membandingkan dan menggabungkan dua subarray secara terbalik
    while (i <= mid && j <= right) {
        if (arr[i].weight >= arr[j].weight) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Menyalin sisa elemen dari subarray kiri
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Menyalin sisa elemen dari subarray kanan
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Menyalin kembali elemen yang sudah digabungkan ke array asli
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

// Fungsi untuk membagi array menjadi dua bagian dan mengurutkan masing-masing bagian
void mergeSort(hesmep* arr, hesmep* temp, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        // Mengurutkan subarray kiri dan kanan
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);

        // Menggabungkan hasil yang telah diurutkan
        merge(arr, temp, left, mid, right);
    }
}

int majorityElement(int* nums, int numsSize) {
    // Menggunakan array dinamis untuk menyimpan frekuensi elemen
    hesmep* bobot = (hesmep*)malloc(numsSize * sizeof(hesmep));
    hesmep* temp = (hesmep*)malloc(numsSize * sizeof(hesmep));
    int uniqueCount = 0;

    // Menghitung frekuensi elemen
    for (int i = 0; i < numsSize; i++) {
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (bobot[j].key == nums[i]) {
                bobot[j].weight++;
                found = 1;
                break;
            }
        }
        if (!found) {
            bobot[uniqueCount].key = nums[i];
            bobot[uniqueCount].weight = 1;
            uniqueCount++;
        }
    }

    // Menyortir array berdasarkan bobot (frekuensi)
    mergeSort(bobot, temp, 0, uniqueCount - 1);

    // Mengembalikan elemen dengan frekuensi tertinggi
    int result = bobot[0].key;

    // Membebaskan memori yang dialokasikan
    free(bobot);
    free(temp);

    return result;
}
