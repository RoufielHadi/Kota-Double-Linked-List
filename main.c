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
#include "implementasi.h"
#include "halaman.h"

int main() {
    // Initialize the city list
    ListKota listKota;
    CreateListKota(&listKota);
    
    // Display welcome screen
    welcomeScreen();
    
    // Start the main program dashboard
    dashboard(&listKota);
    
    // Clean up before exiting
    DeleteListKota(&listKota);
    
    return 0;
}
