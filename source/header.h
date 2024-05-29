#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

// PERUSAHAAN (case sensitive)
// username : loginAdmin
// password : loginAdmin

// MENU SALES
// username : [NIP]
// password : [NIP]

typedef char string[50];

typedef struct Child* AddressChild;
typedef struct Parent* AddressParent;

typedef struct DataChild{
	int no_pro;
	string jenis;
	string alamat;
	float harga;
} DataChild;

typedef struct DataParent{
	string nama;
	int nip;
	string noTelepon;
	float total_penjualan;
} DataParent;

typedef struct Child{
	DataChild dataChild;
	AddressChild next;
} NodeChild;

typedef struct Parent{
	DataParent dataParent;
	AddressParent next;
	AddressChild firstChild;
} NodeParent;

typedef struct{
	AddressParent firstParent;
} Multilist;

void setcolor(int color);

//Source Parent
void createEmpty(Multilist *l);
bool isEmpty(Multilist l);
bool haveChild(AddressParent ap);
bool onlyOne(AddressParent ap);
bool isUnique(Multilist l, string noTelepon);

DataParent makeDataParent(string nama, int nip, string noTelepon, float total_penjualan);
AddressParent alokasiParent(DataParent data);
AddressParent findParent(Multilist l, string nama);

void insertFirstParent(Multilist *l, DataParent data);
void insertAfterParent(Multilist *l, string nama, DataParent data);
void insertLastParent(Multilist *l, DataParent data);

void deleteFirstParent(Multilist *l);
void deleteAtParent(Multilist *l, string nama);
void deleteLastParent(Multilist *l);
void deleteAllChild(AddressParent parent);

void printParent(AddressParent parent);
void printAllParent(Multilist l);
void printAll(Multilist l);

void sortingProperti(Multilist l,int *jml1,int *jml2);

//Source Child
DataChild makeDataChild(int no_pro, string jenis, string alamat, float harga);
AddressChild alokasiChild(DataChild data);
AddressChild findChild(Multilist l, AddressParent parent, int no_pro);

void insertFirstChild(Multilist l, string nama, DataChild data);
void insertLastChild(Multilist l, string nama, DataChild data);

void deleteFirstChild(Multilist l,  string nama);
void deleteLastChild(Multilist l, string nama);
void deleteAtChild(Multilist *l, AddressParent parent, int no_pro);

void printChild(AddressChild child);
void printAllChild(AddressParent parent);
void printAllProperties(Multilist l) ;

void mengundurkanDiri(Multilist *l, AddressParent adrSales ,AddressParent adrSales2); 

// source UI
void setcolor(int color);
void gotoxy(int x, int y);
void bingkaiBesar(int xSemua, int yAtas, int lebar, int tinggi);
void bingkaiKecil(int xSemua, int yAtas, int lebar, int tinggi);
void bingkaiPilihanUtama(int menuUtama);
void bingkaiPilihanSales(int menuSales);
void bingkaiPilihanLaporan(int menuLaporan);
void peringatan1();
void peringatan2();
void peringatan4();
void bingkaiBesarPerusahaan();
void bingkaiPilihanPerusahaan(int menuPerusahaan);
void tampilSemua(Multilist l);
void tampilPro(Multilist l, AddressParent adrSales);
void bingkaiBesarExit();

// WARNA
#define redX 4
#define greenX 2
#define yellowX 6

// KEYBOARD CODE 
// [Esc] 27
// [Enter] 3
// [Arrow Up] 75
// [Arrow Down] 80


