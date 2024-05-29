#include "header.h"

void SetColor(char text,char bg)  //mengatur warna tulisan dan background
{
	unsigned short color=bg*16+text;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleOutput,color);
}

void gotoxy(int x, int y) //memaksa koordinat kursor sebelu mengeksekusi code
 {
	COORD set;
    set.X = x;
    set.Y = y;
 
    SetConsoleCursorPosition(
    	GetStdHandle(STD_OUTPUT_HANDLE), set);
}

void bingkaiBesar(int xSemua, int yAtas, int lebar, int tinggi)  //membuat bingkai besar
{ 
	int i;
	
	gotoxy(xSemua,yAtas); for(i=0; i<lebar; i++){
		printf("%c", 219);
	}
	
	gotoxy(xSemua, yAtas+tinggi); for(i=0; i<lebar; i++){
		printf("%c", 219);
	}
			
	for(i=yAtas+1; i< yAtas+tinggi; i++){
		gotoxy(xSemua-1,i);	printf("%c", 222);
		gotoxy(xSemua,i); printf("%c", 221);
		gotoxy(xSemua+lebar-1,i); printf("%c", 222);
		gotoxy(xSemua+lebar,i);	printf("%c", 221);
	}
}

void bingkaiKecil(int xSemua, int yAtas, int lebar, int tinggi) //membuat bingkai kecil
{ 
	int i;

	gotoxy(xSemua,yAtas); printf("%c", 201);
	for(i=0; i<lebar; i++){
		printf("%c", 196);
	}
	printf("%c", 187);
		
	gotoxy(xSemua, yAtas+tinggi); printf("%c", 200);
	for(i=0; i<lebar; i++){
		printf("%c", 196);
	}
	printf("%c", 188);
			
	for(i=yAtas+1; i< yAtas+tinggi; i++){
		gotoxy(xSemua,i); printf("%c", 179);
		gotoxy(xSemua+lebar+1,i); printf("%c", 179);
	}
}

void bingkaiPilihanUtama(int menuUtama)  //membuat bingkai pilihan untuk menu utama
{	
	int i;

	if (menuUtama == 1) {
		SetColor(redX, 0);
	}
	gotoxy(60,22); printf(" LOGIN OWNER");
	gotoxy(52,20); printf("%c", 201);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 187);
		
	gotoxy(52,24); printf("%c", 200);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 188);
			

	for(i=21; i<24; i++){
		gotoxy(52,i); printf("%c", 179);
		gotoxy(91,i); printf("%c", 179);
	}
	SetColor(6, 0);
			

	if (menuUtama == 2) {
		SetColor(redX, 0);
	}
	gotoxy(60,28); printf(" LOGIN SALES ");
	gotoxy(52,26); printf("%c", 201);
	
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 187);
		
	gotoxy(52,30); printf("%c", 200);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 188);
	
	for(i=27; i<30; i++){
		gotoxy(52,i); printf("%c", 179);
		gotoxy(91,i); printf("%c", 179);
	}
	SetColor(6, 0);
				
	if (menuUtama == 3) {
		SetColor(redX, 0);
	}
		
	gotoxy(60,34); printf(" EXIT ");
	gotoxy(52,32); printf("%c", 201);
	
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 187);
		
	gotoxy(52,36); printf("%c", 200);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 188);
			

	for(i=33; i<36; i++){
		gotoxy(52,i); printf("%c", 179);
		gotoxy(91,i); printf("%c", 179);
	}
	SetColor(6, 0);
}


void bingkaiPilihanSales(int menuSales)  //membuat bingkai pilihan untuk menu sales
{
	int i;

	if (menuSales == 1) {
		SetColor(redX, 0);
	}
	gotoxy(60,22); printf(" DAFTAR PROPERTY");
	gotoxy(52,20); printf("%c", 201);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 187);
		
	gotoxy(52,24); printf("%c", 200);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 188);
	
	for(i=21; i<24; i++){
		gotoxy(52,i); printf("%c", 179);
		gotoxy(91,i); printf("%c", 179);
	}
	SetColor(6, 0);
			
	if (menuSales == 2) {
		SetColor(redX, 0);
	}
	gotoxy(60,28); printf(" JUAL PROPERTI ");
	gotoxy(52,26); printf("%c", 201);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 187);
		
	gotoxy(52,30); printf("%c", 200);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 188);
	
	for(i=27; i<30; i++){
		gotoxy(52,i); printf("%c", 179);
		gotoxy(91,i); printf("%c", 179);
	}
	SetColor(6, 0);
}


void peringatan1() //membuat bingkai pesan untuk menu loginperusahaan, menu 1, 3, 5, 7
{
	bingkaiKecil(52, 32, 38, 4);
}

void peringatan2() //membuat bingkai pesan untuk menu 2
{
	bingkaiKecil(52, 36, 38, 4);
}

void peringatan4() //membuat bingkai pesan untuk menu 4
{
	bingkaiKecil(52, 35, 38, 4);
}

void bingkaiBesarPerusahaan() //membuat bingkai besar untuk menu perusahaan
{
	
	bingkaiBesar(45, 1, 54, 49);
}

void bingkaiPilihanPerusahaan(int menuPerusahaan) //membuat bingkai pilihan untuk menu perusahan
{
	int i;
	
	if (menuPerusahaan == 1) {
		SetColor(redX, 0);
	}
	
	gotoxy(60,7); printf(" TAMBAH SALES");
	gotoxy(52,5); printf("%c", 201);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 187);
		
	gotoxy(52,9); printf("%c", 200);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 188);
			
	for(i=6; i<9; i++){
		gotoxy(52,i); printf("%c", 179);
		gotoxy(91,i); printf("%c", 179);
	}
	SetColor(6, 0);
			
	if (menuPerusahaan  == 2) {
		SetColor(redX, 0);
	}
	gotoxy(60,13); printf(" TAMBAH PROPERTI ");
	gotoxy(52,11); printf("%c", 201);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 187);
		
	gotoxy(52,15); printf("%c", 200);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 188);
	
	for(i=12; i<15; i++){
		gotoxy(52,i); printf("%c", 179);
		gotoxy(91,i); printf("%c", 179);
	}
	SetColor(6, 0);
				
	if (menuPerusahaan  == 3) {
		SetColor(redX, 0);
	}
		
	gotoxy(60,19); printf(" EDIT SALES ");
	gotoxy(52,17); printf("%c", 201);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
		printf("%c", 187);
		
	gotoxy(52,21); printf("%c", 200);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 188);
			
	for(i=18; i<21; i++){
		gotoxy(52,i); printf("%c", 179);
		gotoxy(91,i); printf("%c", 179);
	}
	SetColor(6, 0);
			
	if (menuPerusahaan  == 4) {
		SetColor(redX, 0);
	}
		
	gotoxy(60,25); printf(" EDIT PROPERTI ");
	gotoxy(52,23); printf("%c", 201);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 187);

	gotoxy(52,27); printf("%c", 200);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 188);
			
	for(i=24; i<27; i++){
		gotoxy(52,i); printf("%c", 179);
		gotoxy(91,i); printf("%c", 179);
	}
	SetColor(6, 0);
			
	if (menuPerusahaan  == 5) {
		SetColor(redX, 0);
	}
		
	gotoxy(60,31); printf(" HAPUS PROPERTY ");
	gotoxy(52,29); printf("%c", 201);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 187);
		
	gotoxy(52,33); printf("%c", 200);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 188);
	
	for(i=30; i<33 ;i++){
		gotoxy(52,i); printf("%c", 179);
		gotoxy(91,i); printf("%c", 179);
	}
	SetColor(6, 0);
			
	if (menuPerusahaan  == 6) {
		SetColor(redX, 0);
	}
		
	gotoxy(60,37); printf(" LAPORAN ");
	gotoxy(52,35); printf("%c", 201);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 187);
		
	gotoxy(52,39); printf("%c", 200);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 188);
			
	for(i=36; i<39; i++){
		gotoxy(52,i); printf("%c", 179);
		gotoxy(91,i); printf("%c", 179);
	}
	SetColor(6, 0);
			
	if (menuPerusahaan  == 7) {
		SetColor(redX, 0);
	}
		
	gotoxy(60,43); printf(" RESIGN SALES ");
	gotoxy(52,41); printf("%c", 201);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 187);
		
	gotoxy(52,45); printf("%c", 200);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 188);
	
	for(i=42; i<45; i++){
		gotoxy(52,i); printf("%c", 179);
		gotoxy(91,i); printf("%c", 179);
	}
	SetColor(6, 0);
}

void bingkaiPilihanLaporan(int menuLaporan) //membuat bingkai pilihan untuk menu laporan
{
	
	int i;

	if (menuLaporan == 1) {
		SetColor(redX, 0);
	}
	gotoxy(55,22); printf(" LAPORAN DATA SALES");
	gotoxy(52,20); printf("%c", 201);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 187);
		
	gotoxy(52,24); printf("%c", 200);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 188);
			
	for(i=21; i<24; i++){
		gotoxy(52,i); printf("%c", 179);
		gotoxy(91,i); printf("%c", 179);
	}
	SetColor(6, 0);
		
	if (menuLaporan == 2) {
		SetColor(redX, 0);
	}
	gotoxy(55,28); printf(" LAPORAN DATA PROPERTI SALES ");
	gotoxy(52,26); printf("%c", 201);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 187);
		
	gotoxy(52,30); printf("%c", 200);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 188);
	
	for(i=27; i<30; i++){
		gotoxy(52,i); printf("%c", 179);
		gotoxy(91,i); printf("%c", 179);
	}
	SetColor(6, 0);
				
	if (menuLaporan == 3) {
		SetColor(redX, 0);
	}
		
	gotoxy(55,34); printf(" LAPORAN JUMLAH PROPERTI ");
	gotoxy(52,32); printf("%c", 201);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 187);
		
	gotoxy(52,36); printf("%c", 200);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 188);
			
	for(i=33; i<36; i++){
		gotoxy(52,i); printf("%c", 179);
		gotoxy(91,i); printf("%c", 179);
	}
	SetColor(6, 0);
			
	if (menuLaporan == 4) {
		SetColor(redX, 0);
	}
		
	gotoxy(55,40); printf(" EXIT ");
	gotoxy(52,38); printf("%c", 201);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 187);
		
	gotoxy(52,42); printf("%c", 200);
	for(i=0; i<38; i++){
		printf("%c", 196);
	}
	printf("%c", 188);

	for(i=39; i<42; i++){
		gotoxy(52,i); printf("%c", 179);
		gotoxy(91,i); printf("%c", 179);
	}
	SetColor(6, 0);
	
}

void tampilSemua(Multilist l) // tampil laporan lengkap
{
	int i=5, j, k, p, q;
	AddressParent temp = l.firstParent;
	AddressChild tempchild;
	
	SetColor(yellowX, 0);
	
	gotoxy(32,1); printf("LAPORAN DATA SALES");
	gotoxy(25,2); for(p=0; p<40; p++){
		printf("%c", 196);
	}

	gotoxy(7,i); printf("NIP");
	gotoxy(14,i); printf("NAMA SALES");
	gotoxy(30,i); printf("NOMOR TELEPON");
	gotoxy(48,i); printf("PROPERTI");
	gotoxy(80,i); printf("TERJUAL");
	gotoxy(2,i+1); for(p=0; p<85; p++){
		printf("%c", 196);
	}
	
	q = i+3;
	
	while(temp != NULL){ 
	
		gotoxy(7,q); printf("%d", temp->dataParent.nip);
		gotoxy(14,q); printf("%s", temp->dataParent.nama);
		gotoxy(30,q); printf("%s", temp->dataParent.noTelepon);
		gotoxy(80,q); printf("Rp. %.2f", temp->dataParent.total_penjualan);
		tempchild = temp->firstChild;
		j=q;
		if(tempchild == NULL){
			gotoxy(47,j); printf("Tidak ada tanggungan");
		} else {
			while(tempchild != NULL){
				gotoxy(47,j); printf(" No Pro : %d", tempchild->dataChild.no_pro);
				gotoxy(47,j+1); printf(" Jenis : %s", tempchild->dataChild.jenis);
				gotoxy(47,j+2); printf(" Harga : Rp. %.2f", tempchild->dataChild.harga);
				gotoxy(47,j+3); printf(" Alamat : %s", tempchild->dataChild.alamat);
				j+=6;
				tempchild = tempchild->next;
			}
		}

		gotoxy(2,j+1); for(p=0; p<85; p++){
			printf("%c", 196);
		}
		q=j+3;
		temp = temp->next;
	}
	
	for(k=i; k<=q-1; k++){
		gotoxy(11,k); printf("%c", 179);
		gotoxy(27,k); printf("%c", 179);
		gotoxy(45,k); printf("%c", 179);
		gotoxy(77,k); printf("%c", 179);
	}
	
	printf("\n\n");
}

void tampilPro(Multilist l, AddressParent adrSales) // tampil laporan salah satu sales
{
	
	int i=9, j, k, p, q, r;
	AddressParent temp = adrSales;
	AddressChild tempchild;
	
	SetColor(yellowX, 0);
	
	gotoxy(7,4); printf(" NIP		: %d", adrSales->dataParent.nip);
	gotoxy(7,5); printf(" Nama		: %s", adrSales->dataParent.nama);
	gotoxy(7,6); printf(" No.Telepon	: %s", adrSales->dataParent.noTelepon);
	gotoxy(7,7); printf(" Total Penjualan	: Rp. %.2f", adrSales->dataParent.total_penjualan);
	
	gotoxy(32,1); printf("LAPORAN DATA PROPERSTI SALES %s", adrSales->dataParent.nama);
	gotoxy(25,2); for(p=0; p<43; p++){
		printf("%c", 196);
	}

	gotoxy(7,i); printf("PROPERTI TANAH");
	gotoxy(50,i); printf("PROPERTI RUMAH");
	gotoxy(2,i+1); for(p=0; p<85; p++){
		printf("%c", 196);
	}
	
	q=i+3;
	j=q;
	tempchild = temp->firstChild;
	while(tempchild != NULL){
		if(strcmpi(tempchild->dataChild.jenis,"Tanah")==0){
			gotoxy(7,j); printf(" No Pro : %d", tempchild->dataChild.no_pro);
			gotoxy(7,j+1); printf(" Jenis : %s", tempchild->dataChild.jenis);
			gotoxy(7,j+2); printf(" Harga : Rp. %.2f", tempchild->dataChild.harga);
			gotoxy(7,j+3); printf(" Alamat : %s", tempchild->dataChild.alamat);
			j+=6;
		}
		tempchild = tempchild->next;
	} 
	
	q = i+3;
	r=q;
	tempchild = temp->firstChild;
	while(tempchild != NULL){
		if(strcmpi(tempchild->dataChild.jenis,"Rumah")==0){
			gotoxy(50,r); printf(" No Pro : %d", tempchild->dataChild.no_pro);
			gotoxy(50,r+1); printf(" Jenis : %s", tempchild->dataChild.jenis);
			gotoxy(50,r+2); printf(" Harga : Rp. %.2f", tempchild->dataChild.harga);
			gotoxy(50,r+3); printf(" Alamat : %s", tempchild->dataChild.alamat);
			r+=6;
		}
		tempchild = tempchild->next;
	} 
	
	int max;
	
	if(j>=r){
		max = j;
	} else {
		max = r;
	}
	
	for(k=i; k<=max; k++){
		gotoxy(47,k);	printf("%c", 179);
	}
	
	printf("\n\n");
}

void bingkaiBesarExit() // bingkai exit
{
	bingkaiBesar(48, 15, 46, 19); 

	int i, n=0;
				 
	do{		
		gotoxy(61,20); printf("EXIT THE PROGRAM...");
				
		gotoxy(53,22); printf("%c", 201);
		for(i=0; i<34; i++){
			printf("%c", 205);
		}
		printf("%c", 187);
				
		gotoxy(53,23); printf("%c", 186);
		
		SetColor(greenX, 0);
		for(i=0; i<n ; i++){
			printf("%c", 178);
		}
		SetColor(yellowX, 0);
			
		for(i=0; i<34-n ; i++){
			printf("%c", 176);
		}
				
		printf("%c", 186);
				
				
		gotoxy(53,24); printf("%c", 200);
		for(i=0; i<34; i++){
			printf("%c", 205);
		}
		printf("%c", 188);
			
		if(n<32){
			n+=8;
		} else {
			n+=2;
		}
			
		sleep(1);
	} while (n<=34);
		
	gotoxy(59,19); printf("TUGAS BESAR STRUKTUR DATA");
	gotoxy(57,20); printf("THANK YOU, SEE YOU NEXT TIME ^_^");
}
