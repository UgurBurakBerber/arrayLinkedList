//  main.c
//  ArrayLinkedList
//  Created by Uğur Burak Berber on 21.12.2023.

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100



void basaEkle(int dizi[], int* boyut, int yeni_veri) {
    if (*boyut >= MAX_SIZE) {
        printf("Dizi dolu, ekleme yapilamadi.\n");
        return;
    }

    for (int i = *boyut; i > 0; i--) {
        dizi[i] = dizi[i - 1];
    }

    dizi[0] = yeni_veri;
    (*boyut)++;
}

void sonaEkle(int dizi[], int* boyut, int yeni_veri) {
    if (*boyut >= MAX_SIZE) {
        printf("Dizi dolu, ekleme yapilamadi.\n");
        return;
    }

    dizi[*boyut] = yeni_veri;
    (*boyut)++;
}

void bastanSil(int dizi[], int* boyut) {
    if (*boyut <= 0) {
        printf("Dizi zaten bos.\n");
        return;
    }

    for (int i = 0; i < *boyut - 1; i++) {
        dizi[i] = dizi[i + 1];
    }

    (*boyut)--;
}

void sondanSil(int dizi[], int* boyut) {
    if (*boyut <= 0) {
        printf("Dizi zaten bos.\n");
        return;
    }

    (*boyut)--;
}

int arama(int dizi[], int boyut, int aranan) {
    for (int i = 0; i < boyut; i++) {
        if (dizi[i] == aranan) {
            return i;
        }
    }
    return -1;
}

void listeKur(int dizi[], int boyut) {
    for (int i = 0; i < boyut; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int dizi[MAX_SIZE];
    int boyut = 0;
    int secim, sayi, pozisyon;

    do {
        printf("Nereye eklemek/silmek/aramak istiyorsunuz? (1: Başa ekle, 2: Sona ekle, 3: Baştan sil, 4: Sondan sil, 5: Arama): ");
        scanf("%d", &secim);

        switch (secim) {
                
            case 1:
                printf("Bir sayi girin: ");
                scanf("%d", &sayi);
                basaEkle(dizi, &boyut, sayi);
                break;
            case 2:
                
                printf("Bir sayi girin: ");
                scanf("%d", &sayi);
                sonaEkle(dizi, &boyut, sayi);
                break;
                
            case 3:
                bastanSil(dizi, &boyut);
                break;
                
            case 4:
                sondanSil(dizi, &boyut);
                break;
                
            case 5:
                printf("Aranacak sayiyi girin: ");
                scanf("%d", &sayi);
                pozisyon = arama(dizi, boyut, sayi);
                if (pozisyon != -1) {
                    printf("%d bulundu. Pozisyon: %d\n", sayi, pozisyon);
                } else {
                    printf("%d bulunamadi.\n", sayi);
                }
                break;
                
            default:
                printf("Geçersiz seçim!\n");
                break;
        }

        printf("Devam etmek istiyor musunuz? (1: Evet, 0: Hayır): ");
        scanf("%d", &secim);
    } while (secim != 0);

    printf("Dizideki elemanlar: ");
    listeKur(dizi, boyut);

    return 0;
}
