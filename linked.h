/*
Author: Roufiel Hadi  
NIM: 241524028  
Kelas: 1A  
Prodi: Sarjana Terapan Teknik Informatika  
Jurusan: Teknik Komputer dan Informatika  
Politeknik Negeri Bandung  
*/

#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#define MAX 100

//struck untuk Linked List Non Restricted Fitur List Penduduk dalam suatu kota
typedef struct penduduk *addressPenduduk;
typedef struct penduduk {
    char namaPenduduk[MAX];              
    addressPenduduk next;           
} daftarPenduduk;

typedef struct {
    addressPenduduk First;
} ListPenduduk;
 
//struck untuk Linked List Non Restricted Fitur List Kota
typedef struct kota *addressKota;
typedef struct kota {
    char namaKota[MAX];
    ListPenduduk dataPenduduk; 
    addressKota next;
} daftarKota;

typedef struct {
    addressKota First;
} ListKota;

// =====================================================
// ===================== KONSTRUKTOR ===================
// =====================================================
void CreateListPenduduk(ListPenduduk *L);
// Tujuan : Membuat list penduduk kosong
// IS     : L sembarang
// FS     : Terbentuk list penduduk kosong (First = NULL)

void CreateListKota(ListKota *L);
// Tujuan : Membuat list kota kosong
// IS     : L sembarang
// FS     : Terbentuk list kota kosong (First = NULL)

void DeleteListPenduduk(ListPenduduk *L);
// Tujuan : Menghapus semua elemen dalam list penduduk
// IS     : L mungkin kosong atau berisi elemen
// FS     : Semua elemen dalam list penduduk dihapus dan didealokasi

void DeleteListKota(ListKota *L);
// Tujuan : Menghapus semua elemen dalam list kota
// IS     : L mungkin kosong atau berisi elemen
// FS     : Semua elemen dalam list kota dihapus dan didealokasi

// =====================================================
// ===================== VALIDATOR =====================
// =====================================================
boolean isEmptyPenduduk(ListPenduduk L);
// Tujuan : Mengecek apakah list penduduk kosong
// Mengembalikan TRUE jika list penduduk kosong, FALSE jika tidak

boolean isEmptyKota(ListKota L);
// Tujuan : Mengecek apakah list kota kosong
// Mengembalikan TRUE jika list kota kosong, FALSE jika tidak

// =====================================================
// ================== OPERASI DASAR ====================
// =====================================================
addressPenduduk CreatePenduduk(char *nama);
// Tujuan : Membuat node baru dengan data nama penduduk
// IS     : Nama penduduk terdefinisi
// FS     : Mengembalikan address node baru, atau NULL jika gagal

addressKota CreateKota(char *namaKota, addressPenduduk dataPenduduk);
// Tujuan : Membuat node baru dengan data nama kota
// IS     : Nama kota terdefinisi
// FS     : Mengembalikan address node baru, atau NULL jika gagal

void InsertFirstPenduduk(ListPenduduk *L, addressPenduduk P);
// Tujuan : Menambahkan elemen P sebagai elemen pertama dalam daftar penduduk
// IS     : L mungkin kosong
// FS     : P menjadi elemen pertama dalam list penduduk

void InsertFirstKota(ListKota *L, addressKota P);
// Tujuan : Menambahkan elemen P sebagai elemen pertama dalam daftar kota
// IS     : L mungkin kosong
// FS     : P menjadi elemen pertama dalam list kota

void InsertLastPenduduk(ListPenduduk *L, addressPenduduk P);
// Tujuan : Menambahkan elemen P sebagai elemen terakhir dalam daftar penduduk
// IS     : L mungkin kosong
// FS     : P menjadi elemen terakhir dalam list penduduk

void InsertLastKota(ListKota *L, addressKota P);
// Tujuan : Menambahkan elemen P sebagai elemen terakhir dalam daftar kota
// IS     : L mungkin kosong
// FS     : P menjadi elemen terakhir dalam list kota

void InsertAfterPenduduk(addressPenduduk pBef, addressPenduduk PNew);
// Tujuan : Menyisipkan elemen PNew setelah elemen pBef dalam daftar penduduk
// IS     : pBef tidak NULL
// FS     : PNew menjadi elemen setelah pBef dalam daftar penduduk

void InsertAfterKota(addressKota pBef, addressKota PNew);
// Tujuan : Menyisipkan elemen PNew setelah elemen pBef dalam daftar kota
// IS     : pBef tidak NULL
// FS     : PNew menjadi elemen setelah pBef dalam daftar kota

void DeleteFirstPenduduk(ListPenduduk *L);
// Tujuan : Menghapus elemen pertama dari daftar penduduk
// IS     : List tidak kosong
// FS     : Elemen pertama dalam daftar penduduk dihapus dan didealokasi

void DeleteFirstKota(ListKota *L);
// Tujuan : Menghapus elemen pertama dari daftar kota
// IS     : List tidak kosong
// FS     : Elemen pertama dalam daftar kota dihapus dan didealokasi

void DeleteLastPenduduk(ListPenduduk *L);
// Tujuan : Menghapus elemen terakhir dari daftar penduduk
// IS     : List tidak kosong
// FS     : Elemen terakhir dalam daftar penduduk dihapus dan didealokasi

void DeleteLastKota(ListKota *L);
// Tujuan : Menghapus elemen terakhir dari daftar kota
// IS     : List tidak kosong
// FS     : Elemen terakhir dalam daftar kota dihapus dan didealokasi

void DeleteAfterPenduduk(addressPenduduk pBef);
// Tujuan : Menghapus elemen setelah pBef dalam daftar penduduk
// IS     : pBef tidak NULL dan memiliki elemen setelahnya
// FS     : Elemen setelah pBef dalam daftar penduduk dihapus dan didealokasi

void DeleteAfterKota(addressKota pBef);
// Tujuan : Menghapus elemen setelah pBef dalam daftar kota
// IS     : pBef tidak NULL dan memiliki elemen setelahnya
// FS     : Elemen setelah pBef dalam daftar kota dihapus dan didealokasi

void DeAlokasiPenduduk(addressPenduduk *P);
// Tujuan : Mengembalikan memori dari suatu node penduduk ke sistem
// IS     : P terdefinisi
// FS     : Memori yang ditempati oleh P dikembalikan ke sistem

void DeAlokasiKota(addressKota *P);
// Tujuan : Mengembalikan memori dari suatu node kota ke sistem
// IS     : P terdefinisi
// FS     : Memori yang ditempati oleh P dikembalikan ke sistem

// =====================================================
// ================= OPERASI TAMBAHAN =================
// =====================================================
int NbElmtPenduduk(ListPenduduk L);
// Tujuan : Menghitung jumlah elemen dalam list penduduk
// IS     : List penduduk mungkin kosong atau berisi elemen
// FS     : Mengembalikan jumlah elemen dalam list penduduk

int NbElmtKota(ListKota L);
// Tujuan : Menghitung jumlah elemen dalam list kota
// IS     : List kota mungkin kosong atau berisi elemen
// FS     : Mengembalikan jumlah elemen dalam list kota

addressPenduduk SearchPenduduk(ListPenduduk L, char *nama);
// Tujuan : Mencari penduduk berdasarkan nama dalam list penduduk
// IS     : List penduduk mungkin kosong atau berisi elemen
// FS     : Mengembalikan address penduduk jika ditemukan, NULL jika tidak

addressKota SearchKota(ListKota L, char *namaKota);
// Tujuan : Mencari kota berdasarkan nama dalam list kota
// IS     : List kota mungkin kosong atau berisi elemen
// FS     : Mengembalikan address kota jika ditemukan, NULL jika tidak

void PrintPenduduk(ListPenduduk L);
// Tujuan : Menampilkan semua elemen dalam list penduduk
// IS     : List penduduk mungkin kosong atau berisi elemen
// FS     : Semua elemen dalam list penduduk ditampilkan ke layar

void PrintKota(ListKota L);
// Tujuan : Menampilkan semua elemen dalam list kota
// IS     : List kota mungkin kosong atau berisi elemen
// FS     : Semua elemen dalam list kota ditampilkan ke layar

ListPenduduk BalikListPenduduk(ListPenduduk L);
// Tujuan : Membalik urutan elemen dalam list penduduk
// IS     : List penduduk mungkin kosong atau berisi elemen
// FS     : Mengembalikan list penduduk dengan urutan terbalik

ListKota BalikListKota(ListKota L);
// Tujuan : Membalik urutan elemen dalam list kota
// IS     : List kota mungkin kosong atau berisi elemen
// FS     : Mengembalikan list kota dengan urutan terbalik

#endif
