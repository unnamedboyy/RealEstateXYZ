#include "header.h"

//SOURCE CHILD

DataChild makeDataChild(int no_pro, string jenis, string alamat, float harga) {
	DataChild data;
	
	data.no_pro = no_pro;
	strcpy(data.jenis, jenis);
	data.harga = harga;
	strcpy(data.alamat, alamat);
	
	return data;
}

AddressChild alokasiChild(DataChild data) {
	AddressChild ac;
	ac = (AddressChild) malloc(sizeof(NodeChild));
	
	ac->next = NULL;
	ac->dataChild = data;
	
	return ac;
}

void insertFirstChild(Multilist l, string nama, DataChild data) {
	AddressParent parent = findParent(l, nama);
	
	if(parent != NULL) {
		AddressChild dataBaru = alokasiChild(data);
		dataBaru->next = parent->firstChild;
		
		parent->firstChild = dataBaru;
	}
}

void insertLastChild(Multilist l, string nama, DataChild data) {
	AddressParent parent = findParent(l, nama);
	
	if(parent != NULL) { 
		if(!haveChild(parent)) {
			insertFirstChild(l, nama, data);
		} else {
			AddressChild temp = parent->firstChild;
			AddressChild dataBaru = alokasiChild(data);
			
			while(temp->next != NULL) {
				temp = temp->next;
			}
			
			temp->next = dataBaru;
		}
	}
}

void deleteFirstChild(Multilist l,  string nama) {
	AddressParent parent = findParent(l, nama);
	
	if(parent != NULL){
		if(haveChild(parent)) { 
			AddressChild temp = parent->firstChild;
			parent->firstChild = parent->firstChild->next;
			
			free(temp);
		}
	}
}

void deleteLastChild(Multilist l, string nama) {
	AddressParent parent = findParent(l, nama);
	
	if(parent != NULL) {
		if(haveChild(parent)) {
			if(parent->firstChild->next == NULL) {
				deleteFirstChild(l, nama);
			}else {
				AddressChild temp = parent->firstChild;
				
				while(temp->next->next != NULL){
					temp = temp->next;
				}
				
				free(temp->next);
				temp->next = NULL;
			}
		}
	}
}

void deleteAtChild(Multilist *l, AddressParent parent, int no_pro) {
	AddressChild temp = parent->firstChild;
	AddressChild hapus;
	
	if(!isEmpty(*l)) {
		if(temp->dataChild.no_pro == no_pro) {
			deleteFirstChild(*l, parent->dataParent.nama);
		}else {
			while(temp->next != NULL) {  
				if(temp->next->dataChild.no_pro == no_pro){
					hapus = temp->next;
					temp->next = temp->next->next;
					
					free(hapus);
					hapus = NULL;
					break;
				}
				temp = temp->next;
			}
		}
	}
}

void printChild(AddressChild child){
	printf("\n\n\t\t  === Properties ===");
	printf("\n\t\t[+] No Properties	: %d", child->dataChild.no_pro);
	printf("\n\t\t[+] Jenis		: %s", child->dataChild.jenis);
	printf("\n\t\t[+] Harga		: %.2f", child->dataChild.harga);
	printf("\n\t\t[+] Alamat	: %s", child->dataChild.alamat);
}

void printAllChild(AddressParent parent){
	AddressChild temp = parent->firstChild;
	
	while(temp != NULL){
		printChild(temp);
		
		temp = temp->next;
	}
}

void printAllProperties(Multilist l) {
	AddressParent temp = l.firstParent;
	
	while(temp != NULL) {
		printf("\n\t\t--- Sales %s ---",temp->dataParent.nama);
		printAllChild(temp);
		printf("\n");
		
		temp = temp->next;
	}
}

AddressChild findChild(Multilist l, AddressParent parent, int no_pro) {
	AddressChild temp;
	
	temp = parent->firstChild;
		while(temp != NULL) {
			if(temp->dataChild.no_pro == no_pro){
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
}

void mengundurkanDiri(Multilist *l, AddressParent adrSales ,AddressParent adrSales2){
	AddressChild adrPro,adrPro2,lastChild;

	while(adrSales->firstChild!=NULL){
		adrPro=adrSales->firstChild;
		adrSales->firstChild=adrSales->firstChild->next;
		
		if(!haveChild(adrSales2)){
			adrPro2=alokasiChild(adrPro->dataChild);
			adrPro2->next=adrSales2->firstChild;
			adrSales2->firstChild=adrPro2;
		}else{
			adrPro2=alokasiChild(adrPro->dataChild);
			lastChild=adrSales2->firstChild;
			while(lastChild->next!=NULL){
				lastChild=lastChild->next;
			}
			lastChild->next=adrPro2;
		}
		free(adrPro);
	}
}


