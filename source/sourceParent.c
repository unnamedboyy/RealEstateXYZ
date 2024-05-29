#include "header.h"

//SOURCE PARENT

void createEmpty(Multilist *l) {
	l->firstParent = NULL;
}

bool isEmpty(Multilist l) {
	return l.firstParent == NULL;
}

bool haveChild(AddressParent ap) {
	return ap->firstChild != NULL;
}

bool onlyOne(AddressParent ap){
	return ap->next==NULL;
}

bool isUnique(Multilist l, string noTelepon) {
	AddressParent temp = l.firstParent;
	
	while(temp != NULL) {
		if(strcmp(temp->dataParent.noTelepon , noTelepon) == 0){
			return false;
		}
		temp = temp->next;
	}
	return true;
}

DataParent makeDataParent(string nama, int nip, string noTelepon, float total_penjualan) {
	DataParent data;
	
	strcpy(data.noTelepon, noTelepon);
	strcpy(data.nama, nama);
	data.nip = nip;
	data.total_penjualan = total_penjualan;
	
	return data;
}

AddressParent alokasiParent(DataParent data) {
	AddressParent ap;
	
	ap = (AddressParent) malloc(sizeof(NodeParent));
	
	ap->next = NULL;
	ap->firstChild = NULL;
	ap->dataParent = data;
	
	return ap;
}

AddressParent findParent(Multilist l, string nama) {
	AddressParent temp = NULL;
	string halo;
	
	temp = l.firstParent;
	while(temp != NULL) {
		while(temp != NULL) {
			strcpy(halo, temp->dataParent.nama);
			if(strcmpi(halo , nama) == 0) {
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}
}

void insertFirstParent(Multilist *l, DataParent data) {
	AddressParent temp = alokasiParent(data);
	
	temp->next = l->firstParent;
	l->firstParent = temp;
}

void insertAfterParent(Multilist *l, string nama, DataParent data) {
	AddressParent dataBaru = alokasiParent(data);
	
	if(!isEmpty(*l)) {
		AddressParent temp = findParent(*l, nama);
		
		if(temp != NULL) { 
		dataBaru->next = temp->next;
		temp->next = dataBaru;
		}
	}
}

void insertLastParent(Multilist *l, DataParent data) {
	AddressParent dataBaru = alokasiParent(data);
	
	if(isEmpty(*l)) {
		insertFirstParent(l, data);
	}else{
		AddressParent temp = l->firstParent;
		
		while(temp->next != NULL) {
			temp = temp->next;
		}
		
		temp->next = dataBaru;
	}
}

void deleteAllChild(AddressParent parent) { 
	AddressChild temp;
	
	while(haveChild(parent)) {
		temp = parent->firstChild;
		parent->firstChild = parent->firstChild->next;
		
		free(temp);
	}
}

void deleteFirstParent(Multilist *l) {
	AddressParent temp = l->firstParent;
	
	if(!isEmpty(*l)) {
		deleteAllChild(temp);
		
		l->firstParent = l->firstParent->next;
		free(temp);
	}
}

void deleteAtParent(Multilist *l, string nama) {
	AddressParent temp = l->firstParent;
	AddressParent hapus;
	
	if(!isEmpty(*l)) {
		if(strcmpi(temp->dataParent.nama,nama)==0) {
			deleteFirstParent(&(*l));
		}else {
			while(temp->next != NULL) {  
				if(strcmpi(temp->next->dataParent.nama,nama)==0){
					hapus = temp->next;
					temp->next = temp->next->next;
					
					deleteAllChild(hapus);
					free(hapus);
					hapus = NULL;
					break;
				}
				temp = temp->next;
			}
		}
	}
	
}

void deleteLastParent(Multilist *l) {
	AddressParent temp = l->firstParent;
	
	if(!isEmpty(*l)) {
		if(temp->next == NULL) {
			deleteFirstParent(l);
		}else {
			while(temp->next->next != NULL) {
				temp = temp->next;
			}
			
			deleteAllChild(temp->next);
			free(temp->next);
			
			temp->next = NULL;
		}
	}
}

void printParent(AddressParent parent){
	AddressChild temp;
	temp=parent->firstChild;
	printf("=== Sales ===");
	printf(" NIP: %d", parent->dataParent.nip);
	printf(" Nama: %s", parent->dataParent.nama);
	printf(" No.Telepon: %s", parent->dataParent.noTelepon);
	printf(" Total Penjualan: Rp.%.2f", parent->dataParent.total_penjualan);
}

void printAllParent(Multilist l) {
	AddressParent temp = l.firstParent;
	
	while(temp != NULL){ 
		printParent(temp);
		
		printf("\n");
		temp = temp->next;
	}
}

void printAll(Multilist l) {
	AddressParent temp = l.firstParent;
	
	while(temp != NULL) {
		printParent(temp);
		
		printAllChild(temp);
		printf("\n");
		
		temp = temp->next;
	}
}

void sortingProperti(Multilist l, int *jml1, int *jml2){
	AddressChild temp2;
	AddressParent parent;
	parent=l.firstParent;
	int sum1=0,sum2=0;
	while(parent!=NULL){
		temp2=parent->firstChild;
		while(temp2!=NULL){
			if(strcmpi(temp2->dataChild.jenis,"Tanah")==0){
				sum1++;
			}else if(strcmpi(temp2->dataChild.jenis,"Rumah")==0){
				sum2++;
			}
			temp2=temp2->next;
		}
		parent=parent->next;
	}
	(*jml1)=sum1;
	(*jml2)=sum2;
}

bool isUniqueTelp(Multilist l, string noTelepon) {
	AddressParent temp = l.firstParent;
	
	while(temp != NULL) {
		if(strcmp(temp->dataParent.noTelepon , noTelepon) == 0){
			return false;
		}
		temp = temp->next;
	}
	return true;
}

bool isUniqueNamaSales(Multilist l, string namaSales) {
	AddressParent temp = l.firstParent;
	
	while(temp != NULL) {
		if(strcmp(temp->dataParent.nama , namaSales) == 0){
			return false;
		}
		temp = temp->next;
	}
	return true;
}

bool isUniqueNip(Multilist l, int nip) {
	AddressParent temp = l.firstParent;
	
	while(temp != NULL) {
		if(temp->dataParent.nip==nip){
			return false;
		}
		temp = temp->next;
	}
	return true;
}

bool isUniqueNoPro(Multilist l, int noPro) {
	AddressParent temp = l.firstParent;
	AddressChild temp2;
	while(temp != NULL) {
		temp2=temp->firstChild;
		while(temp2!=NULL){
			if(temp2->dataChild.no_pro==noPro){
			return false;
			}
			temp2=temp2->next;
		}
		temp = temp->next;
	}
	return true;
}

void clearAt(int x, int y, int len){
	gotoxy(x,y);

	while(len!=0){
		printf(" ");
		len--;
	}
}

