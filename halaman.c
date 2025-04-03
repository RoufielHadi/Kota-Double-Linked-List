/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "halaman.h"

/* *** Fungsi untuk membersihkan layar *** */
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/* *** Fungsi Tampilan Awal *** */
void welcomeScreen() {
    clearScreen();
    puts("*************************************************************");
    puts("*                    SELAMAT DATANG DI                     *");
    puts("*     PROGRAM MONITORING DAN MANAJEMEN LINKED LIST         *");
    puts("*************************************************************");
    puts("\nTekan Enter untuk melanjutkan...");
    getchar();
}

/* *** Fungsi Menu Utama *** */
void dashboard(ListKota *listKota) {
    int choice;
    do {
        clearScreen();
        puts("************************** MENU UTAMA **************************");
        puts("1. Tambah Data");
        puts("2. Edit Data");
        puts("3. Hapus Data");
        puts("4. Tampilkan Data");
        puts("5. Keluar");
        printf("Pilihan: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                tambahData(listKota);
                break;
            case 2:
                editData(listKota);
                break;
            case 3:
                hapusData(listKota);
                break;
            case 4:
                tampilkanData(listKota);
                break;
            case 5:
                puts("Terima kasih telah menggunakan program ini!");
                break;
            default:
                puts("Pilihan tidak valid! Silakan coba lagi.");
                break;
        }
    } while (choice != 5);
}

/* *** Fungsi Tambah Data *** */
void tambahData(ListKota *listKota) {
    clearScreen();
    puts("************************** TAMBAH DATA **************************");
    puts("1. Tambah Kota");
    puts("2. Tambah Penduduk");
    printf("Pilihan: ");
    int choice;
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        char kota[50];
        printf("Masukkan nama kota: ");
        fgets(kota, sizeof(kota), stdin);
        kota[strcspn(kota, "\n")] = 0;
        Implementasi_Tambah_Kota(listKota, kota);
    } else if (choice == 2) {
        char kota[50], nama[50];
        printf("Masukkan nama kota: ");
        fgets(kota, sizeof(kota), stdin);
        kota[strcspn(kota, "\n")] = 0;
        printf("Masukkan nama penduduk: ");
        fgets(nama, sizeof(nama), stdin);
        nama[strcspn(nama, "\n")] = 0;
        Implementasi_Tambah_Penduduk(listKota, kota, nama);
    } else {
        printf("Pilihan tidak valid!\n");
    }
    printf("Tekan Enter untuk kembali ke menu...");
    getchar();
}

/* *** Fungsi Edit Data *** */
void editData(ListKota *listKota) {
    clearScreen();
    puts("************************** EDIT DATA **************************");
    puts("1. Edit Nama Kota");
    puts("2. Edit Nama Penduduk");
    printf("Pilihan: ");
    int choice;
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        char kotaLama[50], kotaBaru[50];
        printf("Masukkan nama kota yang akan diedit: ");
        fgets(kotaLama, sizeof(kotaLama), stdin);
        kotaLama[strcspn(kotaLama, "\n")] = 0;
        printf("Masukkan nama kota baru: ");
        fgets(kotaBaru, sizeof(kotaBaru), stdin);
        kotaBaru[strcspn(kotaBaru, "\n")] = 0;
        Implementasi_Edit_Kota(listKota, kotaLama, kotaBaru);
    } else if (choice == 2) {
        char kota[50], namaLama[50], namaBaru[50];
        printf("Masukkan nama kota: ");
        fgets(kota, sizeof(kota), stdin);
        kota[strcspn(kota, "\n")] = 0;
        printf("Masukkan nama penduduk yang akan diedit: ");
        fgets(namaLama, sizeof(namaLama), stdin);
        namaLama[strcspn(namaLama, "\n")] = 0;
        printf("Masukkan nama penduduk baru: ");
        fgets(namaBaru, sizeof(namaBaru), stdin);
        namaBaru[strcspn(namaBaru, "\n")] = 0;
        Implementasi_Edit_Penduduk(listKota, kota, namaLama, namaBaru);
    } else {
        printf("Pilihan tidak valid!\n");
    }
    printf("Tekan Enter untuk kembali ke menu...");
    getchar();
}

/* *** Fungsi Hapus Data *** */
void hapusData(ListKota *listKota) {
    clearScreen();
    puts("************************** HAPUS DATA **************************");
    puts("1. Hapus Kota");
    puts("2. Hapus Penduduk");
    printf("Pilihan: ");
    int choice;
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        char kota[50];
        printf("Masukkan nama kota: ");
        fgets(kota, sizeof(kota), stdin);
        kota[strcspn(kota, "\n")] = 0;
        Implementasi_Hapus_Kota(listKota, kota);
    } else if (choice == 2) {
        char kota[50], nama[50];
        printf("Masukkan nama kota: ");
        fgets(kota, sizeof(kota), stdin);
        kota[strcspn(kota, "\n")] = 0;
        printf("Masukkan nama penduduk: ");
        fgets(nama, sizeof(nama), stdin);
        nama[strcspn(nama, "\n")] = 0;
        Implementasi_Hapus_Penduduk(listKota, kota, nama);
    } else {
        printf("Pilihan tidak valid!\n");
    }
    printf("Tekan Enter untuk kembali ke menu...");
    getchar();
}

/* *** Fungsi Tampilkan Data *** */
void tampilkanData(ListKota *listKota) {
    clearScreen();
    puts("************************** TAMPILKAN DATA **************************");
    puts("1. Tampilkan Semua Data");
    puts("2. Tampilkan Data Kota Tertentu");
    puts("3. Statistik Data");
    printf("Pilihan: ");
    int choice;
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        Implementasi_Tampilkan_Semua(listKota);
    } else if (choice == 2) {
        char kota[50];
        printf("Masukkan nama kota: ");
        fgets(kota, sizeof(kota), stdin);
        kota[strcspn(kota, "\n")] = 0;
        Implementasi_Tampilkan_Kota(listKota, kota);
    } else if (choice == 3) {
        printf("\nStatistik Data:\n");
        printf("Jumlah Kota: %d\n", Implementasi_Hitung_Total_Kota(listKota));
        printf("Total Penduduk di Semua Kota: %d\n", Implementasi_Hitung_Total_Penduduk(listKota));
    } else {
        printf("Pilihan tidak valid!\n");
    }
    
    printf("Tekan Enter untuk kembali ke menu...");
    getchar();
}
