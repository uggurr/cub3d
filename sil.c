#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ayiklaMetni(const char* metin, const char* baslangic, const char* bitis) {
    const char* basIsaretcisi = strnstr(metin, baslangic, strlen(metin));

    if (basIsaretcisi == NULL) {
        return NULL; // Başlangıç işaretcisi bulunamazsa NULL döndür
    }

    basIsaretcisi += strlen(baslangic); // Başlangıç işaretçisini geç
    const char* bitisIsaretcisi = strnstr(basIsaretcisi, bitis, strlen(basIsaretcisi));

    if (bitisIsaretcisi == NULL) {
        return NULL; // Bitiş işaretcisi bulunamazsa NULL döndür
    }

    size_t boyut = bitisIsaretcisi - basIsaretcisi + strlen(bitis);
    char* sonuc = (char*)malloc(boyut + 1);

    if (sonuc == NULL) {
        perror("Hafıza tahsis hatası");
        exit(EXIT_FAILURE);
    }

    strncpy(sonuc, basIsaretcisi, boyut);
    sonuc[boyut] = '\0'; // Son karakteri NULL yap

    return sonuc;
}

int main() {
    const char* metin = "NO ./textures/path_to_the_north_texture.xpm\nSO ./textures/path_to_the_south_texture.xpm\nWE ./textures/path_to_the_west_texture.xpm\nEA ./textures/path_to_the_east_texture.xpm\nF 220,100,0\nC 225,30,0\n1           1\n                        1111111111111111111111111\n                        1000000000110000000000001\n                        1011000001110000000000001\n                        1001000000000000000000001\n111111111011000001110000000000001\n100000000011000001110111111111111\n11110111111111011100000010001\n11110111111111011101010010001\n11000000110101011100000010001\n10000000000000001100000010001\n10000000000000001101010010001\n11000001110101011111011110N0111\n11110111 1110101 101111010001\n11111111 1111111 111111111111";

    const char* baslangic = "1           1";
    const char* bitis = "11111111 1111111 111111111111";

    char* sonuc = ayiklaMetni(metin, baslangic, bitis);

    if (sonuc != NULL) {
        printf("Ayıklanan metin:\n%s\n", sonuc);
        free(sonuc); // Belleği serbest bırak
    } else {
        printf("Metinde istenen bölüm bulunamadı.\n");
    }

    return 0;
}
