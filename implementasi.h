/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#ifndef IMPLEMENTASI_H
#define IMPLEMENTASI_H

#include "linked.h"

/* *** PROTOTYPE *** */

/* *** Fungsi Entry (Tambah Data) *** */
void Implementasi_Tambah_Kota(ListKota *listKota, const char *namaKota);
/* Tujuan  : Menambahkan kota baru ke dalam linked list jika belum ada */
/* IS      : List kota mungkin kosong atau berisi beberapa kota */
/* FS      : Kota baru ditambahkan ke dalam linked list */

void Implementasi_Tambah_Penduduk(ListKota *listKota, const char *namaKota, const char *namaPenduduk);
/* Tujuan  : Menambahkan penduduk ke dalam linked list dari kota tertentu */
/* IS      : Kota sudah ada dalam linked list */
/* FS      : Penduduk baru ditambahkan ke dalam linked list kota yang sesuai */

/* *** Fungsi Delete (Hapus Data) *** */
void Implementasi_Hapus_Kota(ListKota *listKota, const char *namaKota);
/* Tujuan  : Menghapus kota beserta seluruh penduduknya */
/* IS      : Kota sudah ada dalam linked list */
/* FS      : Kota dan seluruh penduduknya dihapus dari linked list */

void Implementasi_Hapus_Penduduk(ListKota *listKota, const char *namaKota, const char *namaPenduduk);
/* Tujuan  : Menghapus penduduk dari linked list dalam kota tertentu */
/* IS      : Kota dan penduduk yang ingin dihapus sudah ada dalam linked list */
/* FS      : Penduduk tertentu dihapus dari linked list kota yang sesuai */

/* *** Fungsi Tampilkan Data *** */
void Implementasi_Tampilkan_Semua(const ListKota *listKota);
/* Tujuan  : Menampilkan seluruh kota beserta daftar penduduknya */
/* IS      : List kota mungkin kosong atau berisi beberapa kota */
/* FS      : Semua data kota dan penduduk ditampilkan */

void Implementasi_Tampilkan_Kota(const ListKota *listKota, const char *namaKota);
/* Tujuan  : Menampilkan penduduk dari kota tertentu */
/* IS      : Kota yang dicari sudah ada dalam linked list */
/* FS      : Daftar penduduk dari kota yang dicari ditampilkan */

/* *** Fungsi Tambahan *** */
int Implementasi_Hitung_Penduduk_Kota(const ListKota *listKota, const char *namaKota);
/* Tujuan  : Menghitung jumlah penduduk di satu kota */
/* IS      : Kota sudah ada dalam linked list */
/* FS      : Jumlah penduduk dalam kota dikembalikan sebagai output */

int Implementasi_Hitung_Total_Kota(const ListKota *listKota);
/* Tujuan  : Menghitung total jumlah kota dalam linked list */
/* IS      : List kota mungkin kosong atau berisi beberapa kota */
/* FS      : Jumlah kota dalam linked list dikembalikan sebagai output */

int Implementasi_Hitung_Total_Penduduk(const ListKota *listKota);
/* Tujuan  : Menghitung total seluruh penduduk dari semua kota */
/* IS      : List kota mungkin kosong atau berisi beberapa kota dengan penduduknya */
/* FS      : Jumlah seluruh penduduk dalam semua kota dikembalikan sebagai output */

/* *** Fungsi Edit Data *** */
void Implementasi_Edit_Kota(ListKota *L, const char *namaKotaLama, const char *namaKotaBaru);
/* Tujuan  : Mengubah nama kota */
/* IS      : Kota dengan namaKotaLama ada dalam list */
/* FS      : Nama kota diubah menjadi namaKotaBaru */

void Implementasi_Edit_Penduduk(ListKota *L, const char *namaKota, const char *namaPendudukLama, const char *namaPendudukBaru);
/* Tujuan  : Mengubah nama penduduk dalam suatu kota */
/* IS      : Kota dan penduduk dengan namaPendudukLama ada dalam list */
/* FS      : Nama penduduk diubah menjadi namaPendudukBaru */

#endif

