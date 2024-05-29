#include "header.h"

int main(int argc, char *argv[]) {	
	Multilist l;
	AddressParent adrSales, adrSales2, adrSalesTemp;

	AddressChild adrPro,adrPro2;
	//Sales
	int menuUtama = 1, menuPerusahaan = 1 , menuSales = 1, menuLaporan = 1, index, i, n, nip, jml1=0,  jml2=0;
	string username, password, nama, noTelepon, cari, cari2;
	char pilihan, pilihan2, pilihan3, validasi;
	
	//Properti
	int noPro;
	float harga;
	string jenis,alamat;
	
	//Umum
	string namaAsal, namaTujuan;
	
	createEmpty(&l);
	SetColor(yellowX,0);
	
	do{
		gotoxy(58,17); printf("SELAMAT DATANG DI PERUSAHAAN");
		gotoxy(65,18); printf("REALESTATEXYZ");
		bingkaiBesar(48, 14, 48, 32);
		
		bingkaiKecil(52, 38, 38, 6);
		gotoxy(60,40); printf("[Enter] = Akses Menu");
		gotoxy(60,41); printf("[Arrow] = Pilih Menu");
		gotoxy(60,42); printf("[Esc]   = Kembali");

		do{
			bingkaiPilihanUtama(menuUtama);
			pilihan=getch();
			
			if(pilihan==72){
				if(menuUtama==1){ 
					menuUtama=3;
				} else {
					menuUtama-=1;
				}
			}

			if(pilihan==80){ 
				if(menuUtama==3){
					menuUtama=1;
				} else {
					menuUtama+=1;
				}
			}	
		}while(pilihan!=13);
		
		switch(menuUtama){
			case 1:
				system("cls");
				gotoxy(60,18); printf("SILAHKAN LOGIN AS OWNER");
				bingkaiBesar(48, 16, 48, 25);
				bingkaiKecil(52, 20, 38, 10);
				gotoxy(55,23); printf(" Username : "); fflush(stdin); gets(username);
                gotoxy(55,26); printf(" Password : "); fflush(stdin); gets(password);
                if (strcmp(username, "loginAdmin") != 0 || strcmp(password, "loginAdmin") != 0){
                	SetColor(redX,0);
	                gotoxy(54,34); printf("Kombinasi username dan password salah");
	                peringatan1();
	                SetColor(yellowX,0);
	                getch();
				} else {
					SetColor(greenX,0);
	                gotoxy(57,34); printf("Berhasil login sebagai owner");
	                peringatan1();
	                SetColor(yellowX,0);
					getch();
					do{
						system("cls");
						gotoxy(60,3); printf("SELAMAT DATANG BANG OWNER ");
						bingkaiBesarPerusahaan();
							do{
								//menu utama perusahaan
								bingkaiPilihanPerusahaan(menuPerusahaan);
								pilihan2=getch();
									
								if(pilihan2==72)
								{
									if(menuPerusahaan==1){
										menuPerusahaan=7;
									} else {
										menuPerusahaan-=1;
									}
								}
						
								if(pilihan2==80)
								{
									if(menuPerusahaan==7){
										menuPerusahaan=1;
									} else {
										menuPerusahaan+=1;
									}
								}	
							}while(pilihan2!=13 && pilihan2!=27);
							
							if (pilihan2==27){
								break;
							}
					 
						switch(menuPerusahaan){
							case 1:
									system("cls");
									gotoxy(63,18); printf("INPUT DATA SALES");
									bingkaiBesar(48, 16, 48, 24);
									bingkaiKecil(52, 20, 38, 10);
									
									do{
										gotoxy(55,23); printf("Input NIP: "); scanf("%d", &nip);
										if(nip == 0){
											SetColor(redX,0);
		                					gotoxy(54,34); printf("NIP Tidak Boleh Kosong");
		               						peringatan1();
		           						    SetColor(yellowX,0);
		           						    clearAt(53, 23, 100);
		           						    bingkaiBesar(48, 16, 48, 24);
											bingkaiKecil(52, 20, 38, 10);
										} else if (!isUniqueNip(l, nip)){
											SetColor(redX,0);
		                					gotoxy(54,34); printf("NIP sudah terdaftar");
		               						peringatan1();
		           						    SetColor(yellowX,0);
											clearAt(53, 23, 100);
											bingkaiBesar(48, 16, 48, 24);
											bingkaiKecil(52, 20, 38, 10);						  	
										} else {
											break;
										}									
									} while (nip == 0 || !isUniqueNip(l, nip));

									
									do{
										gotoxy(55,25); printf("Input Nama: "); fflush(stdin); gets(nama);
										if(strlen(nama) == 0){
											SetColor(redX,0);
		                					gotoxy(54,34); printf("Nama tidak boleh kosong");
		               						peringatan1();
		           						    SetColor(yellowX,0);
		       						  		clearAt(53, 25, 100);
			           						bingkaiBesar(48, 16, 48, 24);
											bingkaiKecil(52, 20, 38, 10);
										} else if (!isUniqueNamaSales(l, nama)){
											SetColor(redX,0);
		                					gotoxy(54,34); printf("Nama sudah terdaftar");
		               						peringatan1();
		           						    SetColor(yellowX,0);
		       						  		clearAt(53, 25, 100);
			           						bingkaiBesar(48, 16, 48, 24);
											bingkaiKecil(52, 20, 38, 10);
										} else {
											break;
										}
									} while(strlen(nama) == 0 || !isUniqueNamaSales(l, nama));
									
									do {
										gotoxy(55,27); printf("Input No.Telepon	: "); fflush(stdin); gets(noTelepon);
										if (strlen(noTelepon) < 10 || strlen(noTelepon) > 12){
											SetColor(redX,0);
		                					gotoxy(54,34); printf("Nomor Harus 10 <= n <=12");
		               						peringatan1();
		           						    SetColor(yellowX,0);
		           						    clearAt(53, 27, 100);
			           						bingkaiBesar(48, 16, 48, 24);
											bingkaiKecil(52, 20, 38, 10);	
										} else if (!isUniqueTelp(l, noTelepon)){
											SetColor(redX,0);
		                					gotoxy(54,34); printf("No Telp sudah terdaftar");
		               						peringatan1();
		           						    SetColor(yellowX,0);
		           						    clearAt(53, 27, 100);
			           						bingkaiBesar(48, 16, 48, 24);
											bingkaiKecil(52, 20, 38, 10);		
										} else {
											break;
										}
									} while (strlen(noTelepon) < 10 || strlen(noTelepon) > 12 || !isUniqueTelp(l, noTelepon));
										
									insertFirstParent(&l, makeDataParent(nama, nip, noTelepon, 0));
									SetColor(greenX,0);
									clearAt(53, 34, 38);
		             				gotoxy(54,34); printf("Berhasil input data");
		                			peringatan1();
		               				SetColor(yellowX,0);
		               				
		               		getch();
							break;
								
							case 2:
								if(!isEmpty(l)){
									system("cls");
									gotoxy(63,18); printf("INPUT DATA PROPERTI");
									bingkaiBesar(48, 16, 48, 28);
									bingkaiKecil(52, 20, 38, 14);
									gotoxy(55,23); printf("Cari nama sales: "); fflush(stdin); gets(nama);
									
									adrSales = findParent(l, nama);
									 
									if(adrSales != NULL){
										do{
											gotoxy(55,25); printf("Input No Properties: "); scanf("%d", &noPro);
											if(noPro<=0){
												SetColor(redX,0);
	                							gotoxy(58,38); printf("No Properties harus > 0 ");
	               								peringatan2();
	           						   			SetColor(yellowX,0);
	           						   			clearAt(53, 25, 100);
	           						   			bingkaiBesar(48, 16, 48, 28);
												bingkaiKecil(52, 20, 38, 14);
											} else if (!isUniqueNoPro(l, noPro)){
												SetColor(redX,0);
			                					gotoxy(58,38); printf("No Pro sudah terdaftar");
			               						peringatan2();
			           						    SetColor(yellowX,0);
			           						    clearAt(53, 25, 100);
	           						   			bingkaiBesar(48, 16, 48, 28);
												bingkaiKecil(52, 20, 38, 14);
											} else {
												break;
											}
										} while (noPro<=0 || !isUniqueNoPro(l, noPro));
										
										do{
											gotoxy(55,27); printf("Input Jenis [Tanah | Rumah]: "); fflush(stdin); gets(jenis);
											if(strlen(jenis) ==0) {
												SetColor(redX,0);
	                							gotoxy(58,38); printf("Jenis Tidak Boleh Kosong");
	               								peringatan2();
	           						   			SetColor(yellowX,0);
	           						   			clearAt(53, 27, 100);
	           						   			bingkaiBesar(48, 16, 48, 28);
												bingkaiKecil(52, 20, 38, 14);
											}else if(strcmpi(jenis, "Tanah")==0) {
												strcpy(jenis, "Tanah");
												break;
											}else if (strcmpi(jenis, "Rumah")==0){
												strcpy(jenis, "Rumah");
												break;
											} else {
												SetColor(redX,0);
	                							gotoxy(58,38); printf("Jenis Tidak Valid");
	               								peringatan2();
	           						   			SetColor(yellowX,0);
	           						   			clearAt(53, 27, 100);
	           						   			bingkaiBesar(48, 16, 48, 28);
												bingkaiKecil(52, 20, 38, 14);
											}
										} while (strlen(jenis) ==0 || strcmpi(jenis, "Rumah")!=0 || strcmpi(jenis, "Tanah")!=0);
										
										do{
											gotoxy(55,29); printf("Input Harga: Rp. "); scanf("%f", &harga);
											if(harga<=0) {
												SetColor(redX,0);
	               								gotoxy(58,38); printf("Harga Properties harus > 0");
	               								peringatan2();
	           						   			SetColor(yellowX,0);
	           						   			clearAt(53, 29, 100);
	           						   			bingkaiBesar(48, 16, 48, 28);
												bingkaiKecil(52, 20, 38, 14);
											} else {
												break;
											}
										} while (harga<=0);
										
										do{
											gotoxy(55,31); printf("Input Alamat: "); fflush(stdin); gets(alamat);
											if(strlen(alamat) ==0) {
												SetColor(redX,0);
	                							gotoxy(58,38); printf("Alamat tidak bole kosong ");
	               								peringatan2();
	           						   			SetColor(yellowX,0);
	           						   			clearAt(53, 31, 100);
	           						   			bingkaiBesar(48, 16, 48, 28);
												bingkaiKecil(52, 20, 38, 14);
											} else {
												break;
											}
										} while (strlen(alamat) ==0);
										
										insertFirstChild(l, nama, makeDataChild(noPro, jenis, alamat, harga));
										SetColor(greenX,0);
										clearAt(58, 38, 35);
	                					gotoxy(58,38); printf("Berhasil Input Propeties ");
	               						peringatan2();
	           							SetColor(yellowX,0);
									}else{
										SetColor(redX,0);
	                					gotoxy(58,38); printf("Sales Tidak Ditemukan ");
	               						peringatan2();
	           							SetColor(yellowX,0);
									}
								}else{
									SetColor(redX,0);
									gotoxy(60,47); printf("Belum ada sales terdaftar");
									SetColor(yellowX,0);
								}
								
							getch();								
							break;
								
							case 3:
								if(!isEmpty(l)) {
									system("cls");
									gotoxy(65,18); printf("EDIT DATA SALES");
									bingkaiBesar(48, 16, 48, 25);
									bingkaiKecil(52, 20, 38, 10);
									gotoxy(55,23); printf("Input nama sales: "); fflush(stdin); gets(nama);

									adrSales= findParent(l, nama);
									
									if(adrSales != NULL){
										bingkaiBesar(96, 16, 48, 25);
										bingkaiKecil(100, 20, 38, 10);
										gotoxy(105,18); printf(" DETAIL SALES %s SEBELUMNYA", adrSales->dataParent.nama);
										gotoxy(102,22); printf(" NIP: %d", adrSales->dataParent.nip);
										gotoxy(102,24); printf(" Nama: %s", adrSales->dataParent.nama);
										gotoxy(102,26); printf(" No.Telepon: %s", adrSales->dataParent.noTelepon);
										gotoxy(102,28); printf(" Total Penjualan: Rp.%.2f", adrSales->dataParent.total_penjualan);											
										do{	
											gotoxy(55,25); printf("Ganti nama: "); fflush(stdin); gets(nama);																							
											if(strlen(nama) == 0){
												SetColor(redX,0);
		                						gotoxy(60,34); printf("Nama Tidak Boleh Kosong");
		               							peringatan1();
		           						 		SetColor(yellowX,0);
		           						 		clearAt(53, 25, 38);
		           						 		bingkaiBesar(48, 16, 48, 25);
												bingkaiKecil(52, 20, 38, 10);
												bingkaiBesar(96, 16, 48, 25);
												bingkaiKecil(100, 20, 38, 10);
											} else if (!isUniqueNamaSales(l, nama)){
												SetColor(redX,0);
						                		gotoxy(60,34); printf("Nama sudah terdaftar");
						               			peringatan1();
						           				SetColor(yellowX,0);
						           				clearAt(53, 25, 38);
						       					bingkaiBesar(48, 16, 48, 25);
												bingkaiKecil(52, 20, 38, 10);
												bingkaiBesar(96, 16, 48, 25);
												bingkaiKecil(100, 20, 38, 10);
											} else {
												break;
											}
										}while (strlen(nama) == 0 || !isUniqueNamaSales(l, nama));
													
										do{	
											gotoxy(55,27); printf("Ganti No.Telepon	: "); fflush(stdin); gets(noTelepon);											
											if(isUnique(l, noTelepon) == false) {
												SetColor(redX,0);
												clearAt(53, 34, 40);
		                						gotoxy(60,34); printf("Nomor Harus Unik");
		               							peringatan1();
		           					 			SetColor(yellowX,0);
		           					 			clearAt(53, 27, 38);
					       						bingkaiBesar(48, 16, 48, 25);
												bingkaiKecil(52, 20, 38, 10);
												bingkaiBesar(96, 16, 48, 25);
												bingkaiKecil(100, 20, 38, 10);
											}else if (strlen(noTelepon) < 10 || strlen(noTelepon) >12){
												SetColor(redX,0);
		                						gotoxy(60,34); printf("Nomor harus 10 <= n < =12");
		               							peringatan1();
		           					 		    SetColor(yellowX,0);
		           					 		    clearAt(53, 27, 38);
						       					bingkaiBesar(48, 16, 48, 25);
												bingkaiKecil(52, 20, 38, 10);
												bingkaiBesar(96, 16, 48, 25);
												bingkaiKecil(100, 20, 38, 10);
											} else if (!isUniqueTelp(l, noTelepon)){
												SetColor(redX,0);
						                		gotoxy(60,34); printf("No Telp sudah terdaftar");
						               			peringatan1();
						           			    SetColor(yellowX,0);
						       					clearAt(53, 27, 38);
						       					bingkaiBesar(48, 16, 48, 25);
												bingkaiKecil(52, 20, 38, 10);
												bingkaiBesar(96, 16, 48, 25);
												bingkaiKecil(100, 20, 38, 10);
											} else {
												break;
											}
										} while (isUnique(l, noTelepon) == false || strlen(noTelepon) < 10 || strlen(noTelepon) >12 || !isUniqueTelp(l, noTelepon));
												
										strcpy(adrSales->dataParent.noTelepon, noTelepon);
										strcpy(adrSales->dataParent.nama, nama);;
											
										SetColor(greenX,0);
										clearAt(53, 34, 40);
	                					gotoxy(60,34); printf("Edit Sales Berhasil");
	               						peringatan1();
	           					 		SetColor(yellowX,0);
									}else{
										SetColor(redX,0);
	                					gotoxy(60,34); printf("Sales Tidak Ditemukan ");
	               						peringatan1();
	           						 	SetColor(yellowX,0);
									}
								}else {
									SetColor(redX,0);
									gotoxy(60,47); printf("Belum ada sales terdaftar");
									SetColor(yellowX,0);
								}
								
							getch();
							break;
								
							case 4:
								if(!isEmpty(l)) {
									system("cls");
									gotoxy(60,18); printf("EDIT DATA PROPERTI");
									bingkaiBesar(48, 16, 48, 25);
									bingkaiKecil(52, 20, 38, 13);
									gotoxy(55,23); printf("Cari sales: "); fflush(stdin); gets(nama);
									
									adrSales= findParent(l, nama);
									
									if(adrSales != NULL && adrSales->firstChild != 0){											
										gotoxy(55,25); printf("Cari properti: "); scanf("%d", &noPro);
										adrPro= findChild(l, adrSales, noPro);
																	
										if(adrPro != NULL){
											bingkaiBesar(96, 16, 48, 25);
											bingkaiKecil(100, 20, 38, 10);
											gotoxy(110,18); printf(" DETAIL PROPERTI SEBELUMNYA");
											gotoxy(102,22); printf(" No Properti: %d", adrPro->dataChild.no_pro);
											gotoxy(102,24); printf(" Jenis: %s", adrPro->dataChild.jenis);
											gotoxy(102,26); printf(" Alamat: %s", adrPro->dataChild.alamat);
											gotoxy(102,28); printf(" Harga: Rp.%.2f", adrPro->dataChild.harga);
												
											do{
												gotoxy(55,27); printf("Input jenis [Tanah/Rumah]: "); fflush(stdin); gets(jenis);
												if(strlen(jenis) ==0) {
													SetColor(redX,0);
	               									gotoxy(60,37); printf("Jenis Tidak Boleh Kosong");
	               									peringatan4();
	           						 				SetColor(yellowX,0);
	           						 				clearAt(53, 27, 38);
	           						 				bingkaiBesar(48, 16, 48, 25);
													bingkaiKecil(52, 20, 38, 13);
													bingkaiBesar(96, 16, 48, 25);
													bingkaiKecil(100, 20, 38, 10);
												}else if(strcmpi(jenis, "Tanah")==0) {
													strcpy(jenis, "Tanah");
													break;
												}else if (strcmpi(jenis, "Rumah")==0){
													strcpy(jenis, "Rumah");
													break;
												} else {
													SetColor(redX,0);
	                								gotoxy(60,37); printf("Jenis Tidak Valid");
	               									peringatan4();
	           						 				SetColor(yellowX,0);
	           						 				clearAt(53, 27, 38);
	           						 				bingkaiBesar(48, 16, 48, 25);
													bingkaiKecil(52, 20, 38, 13);
													bingkaiBesar(96, 16, 48, 25);
												}
											}while (strlen(jenis) ==0 || strcmpi(jenis, "Tanah")!=0 || strcmpi(jenis, "Rumah")!=0);
												
											do{
												gotoxy(55,29); printf("Input harga: "); scanf("%f", &harga);
												if(harga <= 0) {
													SetColor(redX,0);
	                								gotoxy(60,37); printf("Harga Properties harus > 0");
	               									peringatan4();
	           						 				SetColor(yellowX,0);
	           						 				clearAt(53, 29, 38);
	           						 				bingkaiBesar(48, 16, 48, 25);
													bingkaiKecil(52, 20, 38, 13);
													bingkaiBesar(96, 16, 48, 25);
												} else {
													break;
												}
											} while (harga <= 0);
												
											do{
												gotoxy(55,31); printf("Input alamat: "); fflush(stdin); gets(alamat);
												if(strlen(alamat) ==0) {
													SetColor(redX,0);
	                								gotoxy(60,37); printf("Alamat Tidak Boleh Kosong");
	               									peringatan4();
	           						 				SetColor(yellowX,0);
	           						 				clearAt(53, 31, 38);
	           						 				bingkaiBesar(48, 16, 48, 25);
													bingkaiKecil(52, 20, 38, 13);
													bingkaiBesar(96, 16, 48, 25);
												} else {
													break;
												}
											} while (strlen(alamat) ==0);
												
											strcpy(adrPro->dataChild.jenis,jenis);
											strcpy(adrPro->dataChild.alamat,alamat);
											adrPro->dataChild.harga=harga;
												
											SetColor(greenX,0);
	                						gotoxy(60,37); printf("Edit Sales Berhasil");
	               							peringatan4();
	           						 		SetColor(yellowX,0);
	           						 		getch();
	           						 		break;
											
											} else {
												SetColor(redX,0);
	                							gotoxy(60,37); printf("Properties Tidak Ditemukan");
	               								peringatan4();
	           						 			SetColor(yellowX,0);
	           						 			getch();
	           						 			break;
											}	
									}else if (adrSales != NULL && adrSales->firstChild == 0){
										SetColor(redX,0);
	                					gotoxy(60,37); printf("Properties Kosong");
	               						peringatan4();
	           						 	SetColor(yellowX,0);
	           						 	getch();
	           						 	break;
									}else{
										SetColor(redX,0);
	                					gotoxy(60,37); printf("Sales Tidak Ditemukan");
	               						peringatan4();
	           						 	SetColor(yellowX,0);
	           						 	getch();
	           						 	break;
									}
								}else {
									SetColor(redX,0);
									gotoxy(60,47); printf("Belum ada sales terdaftar");
									SetColor(yellowX,0);
								}
								
							getch();
							break;
								
							case 5:
								if(!isEmpty(l)){
									system("cls");
									gotoxy(60,18); printf("HAPUS PROPERTI");
									bingkaiBesar(48, 16, 48, 25);
									bingkaiKecil(52, 20, 38, 13);
									gotoxy(55,23); printf("Cari sales: "); fflush(stdin); gets(nama);
										
									adrSales= findParent(l, nama);
										
									if(adrSales != NULL && adrSales->firstChild != 0){
										gotoxy(55,25); printf("Cari properti: "); scanf("%d", &noPro);
										adrPro = findChild(l,adrSales,noPro);
										if(adrPro!=NULL){
											gotoxy(54,27); printf("Yakin ingin menghapus [Y/N]?"); validasi=getch();
											if(validasi == 'y' || validasi == 'Y'){
												SetColor(greenX,0);
		               							gotoxy(60,37); printf("Berhasil Hapus");
		               							peringatan4();
		           						 		SetColor(yellowX,0);
		           						 		deleteAtChild(&l,adrSales,noPro);
	           						 		} else {
	           						 			SetColor(redX,0);
		               							gotoxy(60,37); printf("Batal menghapus");
		               							peringatan4();
		           						 		SetColor(yellowX,0);
											}
										}else{
											SetColor(redX,0);
	               							gotoxy(60,37); printf("Properti tidak ditemukan");
	               							peringatan4();
	           						 		SetColor(yellowX,0);
										}
									}else if (adrSales != NULL && adrSales->firstChild == NULL){
										SetColor(redX,0);
	               						gotoxy(60,37); printf("Sales belum punya properties");
	               						peringatan4();
	           						 	SetColor(yellowX,0);
									}else{
										SetColor(redX,0);
	                					gotoxy(60,37); printf("Sales Tidak ditemukan");
	               						peringatan4();
	           						 	SetColor(yellowX,0);	 	
									}
								}else{
									SetColor(redX,0);
									gotoxy(60,47); printf("Belum ada sales terdaftar");
									SetColor(yellowX,0);
								}
								
							getch();
							break;
														
							case 6: 
								do{
									system("cls");
									gotoxy(60,18); printf("---=== LAPORAN PERUSAHAAN ===---\n");
									bingkaiBesar(48, 16, 48, 31);
									SetColor(yellowX,0);
									do{
										
										bingkaiPilihanLaporan(menuLaporan);
										pilihan=getch();
											
										if(pilihan==72){
											if(menuLaporan==1){ 
												menuLaporan=4;
											} else {
												menuLaporan-=1;
											}
										}
							
										if(pilihan==80){ 
											if(menuLaporan==4){
												menuLaporan=1;
											} else {
												menuLaporan+=1;
											}
										}
									} while(pilihan != 13 && pilihan != 27);
									
									if (pilihan==27){
										break;
									}
									
									switch(menuLaporan){
									
										case 1:
											if(!isEmpty(l)) {
												system("cls");
												tampilSemua(l);
											}else {
												SetColor(redX,0);
												gotoxy(60,44); printf("[ Tidak Ada Sales Terdaftar ");
												SetColor(yellowX,0);	
											}	
											getch();								
											break;
											
										case 2:
											if(!isEmpty(l)) {
												system("cls");
												gotoxy(60,18); printf(" LOGIN LAPORAN SALES");
												bingkaiBesar(48, 16, 48, 25);
												bingkaiKecil(52, 20, 38, 10);
												gotoxy(55,23); printf(" Input Nama Sales : "); fflush(stdin); gets(nama);
												adrSales= findParent(l, nama);
												
												if(adrSales != NULL && adrSales->firstChild != NULL){
													SetColor(greenX,0);
	             								   	gotoxy(57,34); printf("Sales ditemukan, lanjutkan....");
	              								  	peringatan1();
	             								   	SetColor(yellowX,0);
	             								   	getch();
	             								   	system("cls");
													tampilPro(l, adrSales);
												}else if (adrSales != NULL && adrSales->firstChild == NULL){
													SetColor(redX,0);
	             								   	gotoxy(55,34); printf("Sales ini belum punya properties");
	              								  	peringatan1();
	             								   	SetColor(yellowX,0);
												}else if(adrSales == NULL){
													SetColor(redX,0);
	             								   	gotoxy(57,34); printf("Sales Tidak Ditemukan");
	              								  	peringatan1();
	             								   	SetColor(yellowX,0);
												}
											}else {
												SetColor(redX,0);
												gotoxy(60,44); printf("[ Tidak Ada Sales Terdaftar ]");
												SetColor(yellowX,0);
											}
											getch();
											break;
											
										case 3:
											if(!isEmpty(l)) {
												system("cls");
												gotoxy(60,18); printf("LAPORAN JUMLAH PROPERTIES");
												bingkaiBesar(48, 16, 48, 26);
												bingkaiKecil(52, 20, 38, 8);
												bingkaiKecil(52, 31, 38, 8);
												
												sortingProperti(l,&jml1,&jml2);
												gotoxy(55,24); printf("Jumlah Properti Jenis Tanah: %d",jml1);
												gotoxy(55,35); printf("Jumlah Properti Jenis Rumah: %d",jml2);
											}else {
												SetColor(redX,0);
												gotoxy(60,44); printf("[ Tidak Ada Sales Terdaftar ]");
												SetColor(yellowX,0);
											}
											getch();
											break;
											
										case 4:
											break;
											
									} 
								}while(menuLaporan !=4);
							break;
								
							case 7:
								if(!isEmpty(l)){
									system("cls");
									gotoxy(65,18); printf("RESIGN SALES");
									bingkaiBesar(48, 16, 48, 25);
									bingkaiKecil(52, 20, 38, 10);
									gotoxy(57,23); printf("Input Nama Sales Yang");
									gotoxy(57,24); printf("Ingin Mengundurkan Diri: "); fflush(stdin); gets(namaAsal);
									adrSales= findParent(l, namaAsal);
									adrSalesTemp=l.firstParent;																							
									if(adrSales!=NULL){
										gotoxy(57,26); printf("Yakin Ingin Resign Diri [Y/N]?"); validasi=getch();
										if(validasi == 'y' || validasi == 'Y'){
											if(adrSalesTemp->next==NULL){
												SetColor(greenX,0);
	                							gotoxy(54,34); printf("Sales berhasil mengundurkan diri");
	               								peringatan1();
	           						    		SetColor(yellowX,0);
												deleteFirstParent(&l);
											}else{
												if(haveChild(adrSales)){
													do{
														gotoxy(57,27); printf("Input Nama Sales Tujuan : ");fflush(stdin);gets(namaTujuan);
											            adrSales2= findParent(l, namaTujuan);
											            if(adrSales2!=NULL &&adrSales!=adrSales2){
															SetColor(greenX,0);
				                							gotoxy(54,34); printf("Sales berhasil mengundurkan diri");	
				               								peringatan1();
				           						    		SetColor(yellowX,0);										                
															mengundurkanDiri(&l,adrSales ,adrSales2);
															deleteAtParent(&l,namaAsal);
															break;
														}else if(adrSales2!=NULL && adrSales2==adrSales){
															SetColor(redX,0);
	                										gotoxy(54,34); printf("Tidak bisa memindahkan properti");
	               											peringatan1();
	           					    						SetColor(yellowX,0);
	       					  								break;
														}else{
															SetColor(redX,0);
	                										gotoxy(54,34); printf("Sales Tujuan Tidak Ditemukan");
	               											peringatan1();
	           						    					SetColor(yellowX,0);
	           						    					break;
														}
													}while(adrSales2==NULL || adrSales==adrSales2);
												}else{
													SetColor(greenX,0);
	                								gotoxy(54,34); printf("Sales berhasil mengundurkan diri");
	               									peringatan1();
	           						    			SetColor(yellowX,0);
													deleteAtParent(&l,namaAsal);
												}
											}
										} else{
											SetColor(redX,0);
		                					gotoxy(54,34); printf("Tidak jadi mengundurkan diri");
		               						peringatan1();
		           						   	SetColor(yellowX,0);
										}
									}else{
										SetColor(redX,0);
	                					gotoxy(54,34); printf("Sales Tidak Ditemukan");
	               						peringatan1();
	           						    SetColor(yellowX,0);	
									}
								}else{
									SetColor(redX,0);
									gotoxy(66,47); printf("List Masih Kosong");
									SetColor(yellowX,0);
								}
							getch();
							break;
						}
						
					}while(menuPerusahaan != 27);						   	
				}
				system("cls");
			break;
				
			case 2:
				system("cls");
				gotoxy(60,18); printf("	SILAHKAN LOGIN AS SALES");
				bingkaiBesar(48, 16, 48, 25);
				bingkaiKecil(52, 20, 38, 9);
				gotoxy(55,23); printf(" Username : "); fflush(stdin); gets(username);
                gotoxy(55,26); printf(" Password : "); fflush(stdin); gets(password);
                adrSales= findParent(l, username);
                if(adrSales==NULL){
                	SetColor(redX,0);
                	gotoxy(54,34); printf("username tidak terdaftar");
	                peringatan1();
	                SetColor(yellowX,0);
	                getch();
				} else {
	                if (strcmpi(username, adrSales->dataParent.nama) != 0 || strcmpi(password, adrSales->dataParent.nama) != 0){
		                SetColor(redX,0);
		                gotoxy(53,34); printf("Kombinasi username dan password salah");
		                peringatan1();
		                SetColor(yellowX,0);
		                getch();
					} else {
		                SetColor(greenX,0);
		                gotoxy(57,34); printf("Berhasil login sebagai sales");
		                peringatan1();
		                SetColor(yellowX,0);
						getch();
						
						do{
							system("cls");
							gotoxy(60,18); printf("SELAMAT DATANG BANG [%s] ", adrSales->dataParent.nama);
							bingkaiBesar(48, 16, 48, 20);
								do{
									bingkaiPilihanSales(menuSales);
									pilihan2=getch();
										
									if(pilihan2==72){
										if(menuSales==1){
											menuSales=2;
										} else {
											menuSales-=1;
										}
									}
							
									if(pilihan2==80){
										if(menuSales==2){
											menuSales=1;
										} else {
											menuSales+=1;
										}
									}	
								}while(pilihan2!=13 && pilihan2!=27);
							
								if (pilihan2==27){
									break;
								}
							
								switch(menuSales){
								case 1:
									if(!isEmpty(l)) {
										system("cls");
										tampilPro(l, adrSales);
										getch();
									}else {
										gotoxy(60,47); printf("Sales Masih Kosong!");
									} 
									break;
									
								case 2:	
									if(!isEmpty(l)) {
										if(adrSales != NULL && adrSales->firstChild != 0){
											system("cls");
											bingkaiBesar(48, 16, 48, 20);
											gotoxy(60,20); printf("MENJUAL PROPERTI ");
											gotoxy(52,22); printf("Input No Properties: "); scanf("%d", &noPro);
											
											adrPro= findChild(l, adrSales, noPro);
												
											if(adrPro != NULL){
												gotoxy(52,24); printf("Yakin Ingin Menjual [Y/N]?"); validasi=getch();
												if(validasi == 'y' || validasi == 'Y'){	
													adrSales->dataParent.total_penjualan = adrSales->dataParent.total_penjualan + adrPro->dataChild.harga;
													deleteAtChild(&l, adrSales, noPro);
													SetColor(greenX,0);
													bingkaiKecil(52, 27, 38, 6);
													gotoxy(54,30); printf("Berhasil Jual Properti");
													SetColor(yellowX,0);
													getch(); 	
												} else{
													SetColor(redX,0);
													bingkaiKecil(52, 27, 38, 6);
													gotoxy(54,30); printf("Batal Jual Properties");
													SetColor(yellowX,0);
													getch(); 
												}
											} else {
												SetColor(redX,0);
												bingkaiKecil(52, 27, 38, 6);
												gotoxy(54,30); printf("Properti Tidak Ditemukan!");
												SetColor(yellowX,0);
												getch();
											}			
										}else if (adrSales != NULL && adrSales->firstChild == 0){
											SetColor(redX,0);
											gotoxy(60,33); printf("[ Properties Masih Kosong ]");
											SetColor(yellowX,0);
											getch();
										}
									}else {
										gotoxy(60,45); printf("Properties Kosong!");
										getch();
									} 
								break;
									
								case 27:
										gotoxy(60,47); printf("KEMBALI");	
								break;	
								getch();
								}	
						}while(menuSales != 27);							   	
					}
				}
				system("cls");
				break;
				
			case 3:
				system("cls");
				int warnaa=1, durasi=0;
				bingkaiBesarExit();
				gotoxy(52,28); printf("Lana Marcel Argya Nataniel - 220711681");
				gotoxy(55,29); printf("Eulogius Kurdeo Hesay - 220711689");
				gotoxy(57,30); printf("Kaisar Simatupang - 220711836");
				bingkaiBesar(48, 15, 46, 19); 
				
				do{
					SetColor(warnaa,0);
					gotoxy(54,26); printf("NAMA ANGGOTA YANG BERHASIL BERTAHAN");
					sleep(1);
					
					if(warnaa <= 30){
						warnaa++;
					} else{
						warnaa = 0;
					}
					 durasi+=1;
				} while(durasi <=30);
			break;
		}
	}while(menuUtama != 3);
	return 0;
}
