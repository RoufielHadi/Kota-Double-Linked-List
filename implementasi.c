/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include "implementasi.h"
#include <stdio.h>
#include <string.h>

/* Fungsi Entry (Tambah Data) */
void Implementasi_Tambah_Kota(ListKota *L, const char *namaKota) {
    // Cek apakah kota sudah ada
    if (SearchKota(*L, (char *)namaKota) != NULL) {
        printf("Kota %s sudah ada dalam daftar.\n", namaKota);
        return;
    }
    
    // Buat kota baru
    addressKota newKota = CreateKota((char *)namaKota, NULL);
    if (newKota == NULL) {
        printf("Gagal menambahkan kota %s.\n", namaKota);
        return;
    }
    
    // Tambahkan ke list
    InsertLastKota(L, newKota);
    printf("Kota %s berhasil ditambahkan.\n", namaKota);
}

void Implementasi_Tambah_Penduduk(ListKota *L, const char *namaKota, const char *namaPenduduk) {
    // Cari kota
    addressKota kota = SearchKota(*L, (char *)namaKota);
    if (kota == NULL) {
        printf("Kota %s tidak ditemukan.\n", namaKota);
        return;
    }
    
    // Cek apakah penduduk sudah ada
    if (SearchPenduduk(kota->dataPenduduk, (char *)namaPenduduk) != NULL) {
        printf("Penduduk %s sudah ada di kota %s.\n", namaPenduduk, namaKota);
        return;
    }
    
    // Buat penduduk baru
    addressPenduduk newPenduduk = CreatePenduduk((char *)namaPenduduk);
    if (newPenduduk == NULL) {
        printf("Gagal menambahkan penduduk %s.\n", namaPenduduk);
        return;
    }
    
    // Tambahkan ke list penduduk kota
    if (kota->dataPenduduk.First == NULL) {
        InsertFirstPenduduk(&(kota->dataPenduduk), newPenduduk);
    } else {
        InsertLastPenduduk(&(kota->dataPenduduk), newPenduduk);
    }
    
    printf("Penduduk %s berhasil ditambahkan ke kota %s.\n", namaPenduduk, namaKota);
}

/* Fungsi Delete (Hapus Data) */
void Implementasi_Hapus_Kota(ListKota *L, const char *namaKota) {
    if (isEmptyKota(*L)) {
        printf("Daftar kota kosong.\n");
        return;
    }
    
    addressKota prev = NULL;
    addressKota curr = L->First;
    
    // Cari kota
    while (curr != NULL && strcmp(curr->namaKota, namaKota) != 0) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr == NULL) {
        printf("Kota %s tidak ditemukan.\n", namaKota);
        return;
    }
    
    // Hapus semua penduduk di kota tersebut
    DeleteListPenduduk(&(curr->dataPenduduk));
    
    // Hapus kota dari list
    if (prev == NULL) {
        DeleteFirstKota(L);
    } else {
        DeleteAfterKota(prev);
    }
    
    printf("Kota %s dan semua penduduknya berhasil dihapus.\n", namaKota);
}

void Implementasi_Hapus_Penduduk(ListKota *L, const char *namaKota, const char *namaPenduduk) {
    // Cari kota
    addressKota kota = SearchKota(*L, (char *)namaKota);
    if (kota == NULL) {
        printf("Kota %s tidak ditemukan.\n", namaKota);
        return;
    }
    
    if (isEmptyPenduduk(kota->dataPenduduk)) {
        printf("Tidak ada penduduk di kota %s.\n", namaKota);
        return;
    }
    
    addressPenduduk prev = NULL;
    addressPenduduk curr = kota->dataPenduduk.First;
    
    // Cari penduduk
    while (curr != NULL && strcmp(curr->namaPenduduk, namaPenduduk) != 0) {
        prev = curr;
        curr = curr->next;
    }
    
    if (curr == NULL) {
        printf("Penduduk %s tidak ditemukan di kota %s.\n", namaPenduduk, namaKota);
        return;
    }
    
    // Hapus penduduk
    if (prev == NULL) {
        DeleteFirstPenduduk(&(kota->dataPenduduk));
    } else {
        DeleteAfterPenduduk(prev);
    }
    
    printf("Penduduk %s berhasil dihapus dari kota %s.\n", namaPenduduk, namaKota);
}

/* Fungsi Tampilkan Data */
void Implementasi_Tampilkan_Semua(const ListKota *L) {
    if (isEmptyKota(*L)) {
        printf("Daftar kota kosong.\n");
        return;
    }
    
    addressKota kota = L->First;
    while (kota != NULL) {
        printf("\nKota: %s\n", kota->namaKota);
        printf("Jumlah Penduduk: %d\n", NbElmtPenduduk(kota->dataPenduduk));
        printf("Daftar Penduduk:\n");
        
        if (isEmptyPenduduk(kota->dataPenduduk)) {
            printf("- Tidak ada penduduk\n");
        } else {
            PrintPenduduk(kota->dataPenduduk);
        }
        
        kota = kota->next;
    }
}

void Implementasi_Tampilkan_Kota(const ListKota *L, const char *namaKota) {
    addressKota kota = SearchKota(*L, (char *)namaKota);
    if (kota == NULL) {
        printf("Kota %s tidak ditemukan.\n", namaKota);
        return;
    }
    
    printf("\nKota: %s\n", kota->namaKota);
    printf("Jumlah Penduduk: %d\n", NbElmtPenduduk(kota->dataPenduduk));
    
    if (isEmptyPenduduk(kota->dataPenduduk)) {
        printf("- Tidak ada penduduk\n");
    } else {
        PrintPenduduk(kota->dataPenduduk);
    }
}

/* Fungsi Tambahan */
int Implementasi_Hitung_Penduduk_Kota(const ListKota *L, const char *namaKota) {
    addressKota kota = SearchKota(*L, (char *)namaKota);
    if (kota == NULL) {
        printf("Kota %s tidak ditemukan.\n", namaKota);
        return 0;
    }
    return NbElmtPenduduk(kota->dataPenduduk);
}

int Implementasi_Hitung_Total_Kota(const ListKota *L) {
    return NbElmtKota(*L);
}

int Implementasi_Hitung_Total_Penduduk(const ListKota *L) {
    int total = 0;
    addressKota kota = L->First;
    
    while (kota != NULL) {
        total += NbElmtPenduduk(kota->dataPenduduk);
        kota = kota->next;
    }
    
    return total;
}

/* *** Fungsi Edit Data *** */
void Implementasi_Edit_Kota(ListKota *L, const char *namaKotaLama, const char *namaKotaBaru) {
    if (isEmptyKota(*L)) {
        printf("Daftar kota kosong.\n");
        return;
    }

    // Cari kota yang akan diedit
    addressKota kota = SearchKota(*L, (char *)namaKotaLama);
    if (kota == NULL) {
        printf("Kota %s tidak ditemukan.\n", namaKotaLama);
        return;
    }

    // Cek apakah nama baru sudah digunakan
    if (SearchKota(*L, (char *)namaKotaBaru) != NULL) {
        printf("Kota %s sudah ada dalam daftar.\n", namaKotaBaru);
        return;
    }

    // Edit nama kota
    strcpy(kota->namaKota, namaKotaBaru);
    printf("Nama kota berhasil diubah dari %s menjadi %s.\n", namaKotaLama, namaKotaBaru);
}

void Implementasi_Edit_Penduduk(ListKota *L, const char *namaKota, const char *namaPendudukLama, const char *namaPendudukBaru) {
    // Cari kota
    addressKota kota = SearchKota(*L, (char *)namaKota);
    if (kota == NULL) {
        printf("Kota %s tidak ditemukan.\n", namaKota);
        return;
    }

    if (isEmptyPenduduk(kota->dataPenduduk)) {
        printf("Tidak ada penduduk di kota %s.\n", namaKota);
        return;
    }

    // Cari penduduk yang akan diedit
    addressPenduduk penduduk = SearchPenduduk(kota->dataPenduduk, (char *)namaPendudukLama);
    if (penduduk == NULL) {
        printf("Penduduk %s tidak ditemukan di kota %s.\n", namaPendudukLama, namaKota);
        return;
    }

    // Cek apakah nama baru sudah digunakan
    if (SearchPenduduk(kota->dataPenduduk, (char *)namaPendudukBaru) != NULL) {
        printf("Penduduk %s sudah ada di kota %s.\n", namaPendudukBaru, namaKota);
        return;
    }

    // Edit nama penduduk
    strcpy(penduduk->namaPenduduk, namaPendudukBaru);
    printf("Nama penduduk berhasil diubah dari %s menjadi %s di kota %s.\n", 
           namaPendudukLama, namaPendudukBaru, namaKota);
}
