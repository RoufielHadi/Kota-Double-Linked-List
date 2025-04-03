/*
Author: Roufiel Hadi  
NIM: 241524028  
Kelas: 1A  
Prodi: Sarjana Terapan Teknik Informatika  
Jurusan: Teknik Komputer dan Informatika  
Politeknik Negeri Bandung  
*/

#include "linked.h"

// ===================== KONSTRUKTOR =====================
void CreateListPenduduk(ListPenduduk *L) {
    L->First = NULL;
}

void CreateListKota(ListKota *L) {
    L->First = NULL;
}

void DeleteListPenduduk(ListPenduduk *L) {
    addressPenduduk temp;
    while (L->First != NULL) {
        temp = L->First;
        L->First = L->First->next;
        free(temp);
    }
}

void DeleteListKota(ListKota *L) {
    addressKota temp;
    while (L->First != NULL) {
        DeleteListPenduduk(&(L->First->dataPenduduk));
        temp = L->First;
        L->First = L->First->next;
        free(temp);
    }
}

// ===================== VALIDATOR =====================
boolean isEmptyPenduduk(ListPenduduk L) {
    return (L.First == NULL);
}

boolean isEmptyKota(ListKota L) {
    return (L.First == NULL);
}

// ================== OPERASI DASAR ====================
addressPenduduk CreatePenduduk(char *nama) {
    addressPenduduk P = (addressPenduduk)malloc(sizeof(daftarPenduduk));
    if (P == NULL) {
        printf("Gagal mengalokasikan memori untuk penduduk.\n");
        return NULL;
    }
    strcpy(P->namaPenduduk, nama);
    P->next = NULL;
    return P;
}

addressKota CreateKota(char *namaKota, addressPenduduk dataPenduduk) {
    addressKota P = (addressKota)malloc(sizeof(daftarKota));
    if (P == NULL) {
        printf("Gagal mengalokasikan memori untuk kota.\n");
        return NULL;
    }
    strcpy(P->namaKota, namaKota);
    CreateListPenduduk(&P->dataPenduduk);
    if (dataPenduduk != NULL) {
        addressPenduduk newPenduduk = CreatePenduduk(dataPenduduk->namaPenduduk);
        InsertLastPenduduk(&P->dataPenduduk, newPenduduk);
    }
    P->next = NULL;
    return P;
}

void InsertFirstPenduduk(ListPenduduk *L, addressPenduduk P) {
    if (P != NULL) {
        P->next = L->First;
        L->First = P;
    }
}

void InsertFirstKota(ListKota *L, addressKota P) {
    if (P != NULL) {
        P->next = L->First;
        L->First = P;
    }
}

void InsertLastPenduduk(ListPenduduk *L, addressPenduduk P) {
    if (P != NULL) {
        if (isEmptyPenduduk(*L)) {
            L->First = P;
        } else {
            addressPenduduk temp = L->First;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = P;
        }
    }
}

void InsertLastKota(ListKota *L, addressKota P) {
    if (P != NULL) {
        if (isEmptyKota(*L)) {
            L->First = P;
        } else {
            addressKota temp = L->First;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = P;
        }
    }
}

void InsertAfterPenduduk(addressPenduduk pBef, addressPenduduk PNew) {
    if (pBef != NULL && PNew != NULL) {
        PNew->next = pBef->next;
        pBef->next = PNew;
    }
}

void InsertAfterKota(addressKota pBef, addressKota PNew) {
    if (pBef != NULL && PNew != NULL) {
        PNew->next = pBef->next;
        pBef->next = PNew;
    }
}

void DeleteFirstPenduduk(ListPenduduk *L) {
    if (!isEmptyPenduduk(*L)) {
        addressPenduduk temp = L->First;
        L->First = L->First->next;
        free(temp);
    }
}

void DeleteFirstKota(ListKota *L) {
    if (!isEmptyKota(*L)) {
        addressKota temp = L->First;
        DeleteListPenduduk(&temp->dataPenduduk);
        L->First = L->First->next;
        free(temp);
    }
}

void DeleteLastPenduduk(ListPenduduk *L) {
    if (!isEmptyPenduduk(*L)) {
        if (L->First->next == NULL) {
            free(L->First);
            L->First = NULL;
        } else {
            addressPenduduk temp = L->First;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            free(temp->next);
            temp->next = NULL;
        }
    }
}

void DeleteLastKota(ListKota *L) {
    if (!isEmptyKota(*L)) {
        if (L->First->next == NULL) {
            DeleteListPenduduk(&L->First->dataPenduduk);
            free(L->First);
            L->First = NULL;
        } else {
            addressKota temp = L->First;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            DeleteListPenduduk(&temp->next->dataPenduduk);
            free(temp->next);
            temp->next = NULL;
        }
    }
}

void DeleteAfterPenduduk(addressPenduduk pBef) {
    if (pBef != NULL && pBef->next != NULL) {
        addressPenduduk temp = pBef->next;
        pBef->next = temp->next;
        free(temp);
    }
}

void DeleteAfterKota(addressKota pBef) {
    if (pBef != NULL && pBef->next != NULL) {
        addressKota temp = pBef->next;
        DeleteListPenduduk(&temp->dataPenduduk);
        pBef->next = temp->next;
        free(temp);
    }
}

void DeAlokasiPenduduk(addressPenduduk *P) {
    if (*P != NULL) {
        free(*P);
        *P = NULL;
    }
}

void DeAlokasiKota(addressKota *P) {
    if (*P != NULL) {
        DeleteListPenduduk(&(*P)->dataPenduduk);
        free(*P);
        *P = NULL;
    }
}

int NbElmtPenduduk(ListPenduduk L) {
    int count = 0;
    addressPenduduk P = L.First;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

int NbElmtKota(ListKota L) {
    int count = 0;
    addressKota K = L.First;
    while (K != NULL) {
        count++;
        K = K->next;
    }
    return count;
}

addressPenduduk SearchPenduduk(ListPenduduk L, char *nama) {
    addressPenduduk P = L.First;
    while (P != NULL) {
        if (strcmp(P->namaPenduduk, nama) == 0) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

addressKota SearchKota(ListKota L, char *namaKota) {
    addressKota K = L.First;
    while (K != NULL) {
        if (strcmp(K->namaKota, namaKota) == 0) {
            return K;
        }
        K = K->next;
    }
    return NULL;
}

void PrintPenduduk(ListPenduduk L) {
    addressPenduduk P = L.First;
    if (P == NULL) {
        printf("List penduduk kosong.\n");
    } else {
        printf("Daftar Penduduk:\n");
        while (P != NULL) {
            printf("- %s\n", P->namaPenduduk);
            P = P->next;
        }
    }
}

void PrintKota(ListKota L) {
    addressKota K = L.First;
    if (K == NULL) {
        printf("List kota kosong.\n");
    } else {
        printf("Daftar Kota:\n");
        while (K != NULL) {
            printf("- %s\n", K->namaKota);
            PrintPenduduk(K->dataPenduduk);
            K = K->next;
        }
    }
}

ListPenduduk BalikListPenduduk(ListPenduduk L) {
    ListPenduduk reversed;
    CreateListPenduduk(&reversed);
    addressPenduduk P = L.First;
    while (P != NULL) {
        addressPenduduk newPenduduk = CreatePenduduk(P->namaPenduduk);
        InsertFirstPenduduk(&reversed, newPenduduk);
        P = P->next;
    }
    return reversed;
}

ListKota BalikListKota(ListKota L) {
    ListKota reversed;
    CreateListKota(&reversed);
    addressKota K = L.First;
    while (K != NULL) {
        addressKota newKota = CreateKota(K->namaKota, NULL);
        addressPenduduk penduduk = K->dataPenduduk.First;
        while (penduduk != NULL) {
            addressPenduduk newPenduduk = CreatePenduduk(penduduk->namaPenduduk);
            InsertLastPenduduk(&newKota->dataPenduduk, newPenduduk);
            penduduk = penduduk->next;
        }
        InsertFirstKota(&reversed, newKota);
        K = K->next;
    }
    return reversed;
}

