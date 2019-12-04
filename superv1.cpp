#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <fstream>

#define True 1
#define False 0

using namespace std;

void menu1();
void menu2();

typedef char typeinfo;
// --> QUEUE <--
typedef struct typequeue *typeptr;
typedef struct typequeue1 *typeptr1;
struct data{
	char  nama[30], alamat[50];
	int tHargaObat, jumlahObat, namaObat;
};
struct simpan{
	char  nama[30], alamat[50];
	int tHargaObat, jumlahObat,  namaObat;
};
struct typequeue{
	typeptr next;
	data info;
};
struct typequeue1{
	typeptr1 prev;
	simpan info2;
};
typeptr Qdepan, Qbelakang;
typeptr1 Qdepan1, Qbelakang1;

void createQueue();
int queueKosong();
void enqueue(char nama2[], char alamat2[], int tHargaObat2);
void dequeue();
void cetakQueue();
void cetakQueueRiwayat();
int Antrian = 0, antrianRiwayat = 0;
char namaHapus[30];
// --> END QUEUE <--

//--> STACK POP <--
void pop();
//--> STACK POP <--

// --> LINKED LIST <--
typedef struct {
	int id;
	char nama[30];
	char alamat[50];
	int notelp;
}typeinfoList;
typedef struct typenode *typeptrList;
struct typenode{
	typeinfoList infoList;
	typeptrList nextList;
	};
typeptrList awal,akhir;
void sisipnode(typeinfoList IB);
void cetakdata();
void hapusnode(int IH);
void carinode(int IC);
// --> END LINKED LIST <--
// ->> FILE <--
void tulisData(ofstream &dataTulis, int &antrianRiwayat, simpan info2);
void bacaDataR();
void bacaData(ifstream &dataMasuk, int &antrianRiwayat, simpan info2, string &namaFile);

string namaFile, namaBatas;
ifstream dataMasuk, batasOutput1;
ofstream dataTulis;
fstream dataKu, batasInput1;

simpan info2;
// --> END FILE <--

int main(){
	createQueue();
	int pilih;
	char kembali;
	do{
		system("cls");
		cout<<" ________________________________________"<<endl;
		cout<<"|                                        |"<<endl;
		cout<<"|      === PROGRAM APOTEK ABADI ===      |"<<endl;
		cout<<"|________________________________________|"<<endl;
		cout<<"|                                        |"<<endl;
		cout<<"| Menu Utama :                           |"<<endl;
		cout<<"| 1. Menu Pelayanan                      |"<<endl;
		cout<<"| 2. Menu Karyawan                       |"<<endl;
		cout<<"| 3. Exit                                |"<<endl;
		cout<<"|________________________________________|"<<endl<<endl;
		cout<<" Pilih Menu : ";cin>>pilih;
		switch(pilih){
			case 1 : 
			{
				menu1();
			}
			break;
			case 2 :
			{
				menu2();
			}
			break;
			break;
			case 3 :
				exit(0);
			break;
			default : 
				cout<<endl<<"Input Yang Anda Masukan SALAH ! "<<endl;
			break;
		}cout<<endl<<"Kembali Ke Menu Utama ? [ y/n ] : ";cin>>kembali;
	}while(kembali == 'y' || kembali == 'Y');
}

void menu1(){
	int pilih1;
	char kembali1;
	int jumlahObat2, antrian, namaObat2, tHargaObat2;
	char nama2[30], alamat2[50];
	do{
		antrian = 1;
		system("cls");
		if(!queueKosong()){
			cetakQueue();
		}
		cout<<" ____________________________"<<endl;
		cout<<"|                            |"<<endl;
		cout<<"|   === Menu Pelayanan ===   |"<<endl;
		cout<<"|____________________________|"<<endl;
		cout<<"|                            |"<<endl;
		cout<<"| Menu :                     |"<<endl;
		cout<<"| 1. Beli Obat               |"<<endl;
		cout<<"| 2. Lihat Daftar Pembeli    |"<<endl;
		cout<<"| 3. Layani Pembeli          |"<<endl;
		cout<<"| 4. Riwayat Pembelian       |"<<endl;
		cout<<"| 5. Pembatalan Pembelian    |"<<endl;
		cout<<"| 6. Exit                    |"<<endl;
		cout<<"|____________________________|"<<endl<<endl;
		cout<<" Pilih menu : ";cin>>pilih1;
		switch(pilih1){
			case 1 :
			{
				cout<<endl<<"---------------------------------------";
				cout<<endl<<"  = Menu Input Pembeli Obat-obatan =";
				cout<<endl<<"---------------------------------------"<<endl;
				if(queueKosong()){
					createQueue();
				}
				while(antrian == 1){
					if(!queueKosong()){
						cetakQueue();
					}
				Antrian++;
				cout<<" Masukkan Nama        : ";cin.ignore();cin.getline(nama2,sizeof(nama2));
				cout<<" Masukkan Alamat      : ";cin.getline(alamat2,sizeof(alamat2));
				cout<<"----------------------------------"<<endl;
				cout<<" Daftar Obat-Obatan : ";
				cout<<endl<<"  1. Alkohol		Rp.4800";
				cout<<endl<<"  2. Bodrex		Rp.6600"; 
				cout<<endl<<"  3. CTM		Rp.900";
				cout<<endl<<"  4. Diapet		Rp.2000";
				cout<<endl<<"  5. Entrostop		Rp.12200";
				cout<<endl<<"----------------------------------";
				cout<<endl<<" Pilih Obat Yang dibeli : ";cin>>namaObat2;
				cout<<" Masukkan Jumlah Obat : ";cin>>jumlahObat2;
				if(namaObat2==1){
					tHargaObat2=4800*jumlahObat2;
					
					}else if(namaObat2==2){
						tHargaObat2=6600*jumlahObat2;
						
						}else if(namaObat2==3){
							tHargaObat2=900*jumlahObat2;
							
							}else if(namaObat2==4){
								tHargaObat2=2000*jumlahObat2;
								
								}else if(namaObat2){
									tHargaObat2=12200*jumlahObat2;
									
									}
				enqueue(nama2,alamat2,tHargaObat2);
				cout<<endl<<" Tekan 1 Untuk Menambah Pembelian || Tekan 0 untuk Kembali ke Menu ";
				cin>>antrian; 
				system("cls");
				}
			}
			break;
			case 2 :
			{
				if(!queueKosong()){
					cetakQueue();
				}else
					cout<<"== Tidak Ada Pembeli !!"<<endl;
			}
			break;
			case 3 : 
			{
				cout<<endl<<"---------------------------------------";
				cout<<endl<<"|       = Menu Layani Pembeli =       |";
				cout<<endl<<"---------------------------------------"<<endl;
				if(!queueKosong()){
					dequeue();
				}else
					cout<<"== Tidak Ada Pembeli !!"<<endl;
			}
			break;
			case 4 :
			{
				//if(Qdepan1 == NULL){
					cout<<"Masukkan Nama File : ";cin>>namaFile;
					cout<<"Masukkan Nama Batas : ";cin>>namaBatas;
					batasOutput1.open(namaBatas, ios::in);
					batasOutput1 >> antrianRiwayat;
					batasOutput1.close();
					cout<<endl<<"---------------------------------------";
					cout<<endl<<"|     = Menu Riwayat Pembelian =      |";
					cout<<endl<<"---------------------------------------"<<endl;
					if(antrianRiwayat != 0){
						bacaData(dataMasuk, antrianRiwayat, info2, namaFile);
					}else
						cout<<"== Belum Ada Pembeli !!"<<endl;
				//} else {
					//bacaDataR();
				//}
			}
			break;
			case 5 :
			{
				cout<<endl<<"---------------------------------------";
				cout<<endl<<"|    = Menu Pembatalan Pembelian =    |";
				cout<<endl<<"---------------------------------------"<<endl;
				if(!queueKosong()){
					pop();
					cout<<" Tidak Jadi Membeli, karena Antrian terlalu lama !!"<<endl<<endl;
				}else
					cout<<"== Belum Ada Pembeli !!"<<endl;
			}
			break;
			case 6 : 
				exit(0);
			break;
		}
		cout<<"Kembali ke Menu Pelayanan ?[ y/n ] : ";cin>>kembali1;
	}while(kembali1 == 'y' || kembali1 == 'Y');
}




// --> QUEUE <--
void createQueue(){
	Qdepan = (typequeue *) malloc(sizeof(typequeue));
	Qdepan = NULL;
	Qbelakang = Qdepan;
	
	//== > Riwayat < ==
	Qdepan1 = (typequeue1 *) malloc(sizeof(typequeue1));
	Qdepan1 = NULL;
	Qbelakang1 = Qdepan1;	
}

int queueKosong(){
	if(Qdepan == NULL){
		return(True);
	}else
		return(False);
}

int queueKosong1(){
	if(Qdepan1 == NULL){
		return(True);
	}else
		return(False);
}

void enqueue(char nama2[], char alamat2[], int tHargaObat2){
	typeptr NB;
	NB = (typequeue *) malloc(sizeof(typequeue));
	strcpy(NB->info.nama,nama2);
	strcpy(NB->info.alamat,alamat2);
	NB->info.tHargaObat = tHargaObat2;
	
	if(Qdepan == NULL){
		Qdepan = NB;
	}else
		Qbelakang->next = NB;
		
	Qbelakang = NB;
	Qbelakang->next = NULL;
}

void dequeue(){
	cout<<endl<<"Masukkan Nama File Untuk menyimpan Riwayat Pembelian : ";cin>>namaFile;
	cout<<"Masukkan Nama File Untuk Simpan Banyak Data : ";cin>>namaBatas;
	dataKu.open(namaFile, ios::app | ios::out); //ios::out untuk membuka file dan menuliskan di dalamnya
	batasInput1.open(namaBatas, ios::trunc | ios::out);
	typeptr hapus;
	if(queueKosong()){
		cout<<" Queue masih kosong !!";
	}else{
		hapus = Qdepan;
		Qdepan = hapus->next;
	
		typeptr1 NB;
		NB = (typequeue1 *) malloc(sizeof(typequeue1));
		strcpy(NB->info2.nama, hapus->info.nama);
		strcpy(NB->info2.alamat, hapus->info.alamat);
		NB->info2.tHargaObat = hapus->info.tHargaObat;
		if(Qdepan1 == NULL)
			Qdepan1 = NB;
		else
			Qbelakang1->prev = NB;
		Qbelakang1 = NB;
		Qbelakang1->prev = NULL;
		antrianRiwayat++;
		batasInput1<<antrianRiwayat;
	
		free(hapus);
		dataKu<<Qbelakang1->info2.nama<<endl;
		dataKu<<Qbelakang1->info2.alamat<<endl;
		dataKu<<Qbelakang1->info2.tHargaObat<<endl;
		Antrian--;
		cout<<"== Pelayanan "<<Qbelakang1->info2.nama<<" Selesai"<<endl;
	
	}
	batasInput1.close();
	dataKu.close();
}

void cetakQueue(){
	typeptr bantu;
	int i = 0;
	bantu = Qdepan;
	cout<<endl<<"                                   == DAFTAR PEMBELI == ";
	cout<<endl<<"================================================================================================"<<endl;
	cout<<setw(4)<<" No "<<setw(15)<<" Nama "<<setw(25)<<" Alamat "<<setw(35)<<" total Harga Obat "<<endl;
	cout<<"------------------------------------------------------------------------------------------------"<<endl;
	do{
		i++;
		cout<<setw(4)<< i <<setw(15)<< bantu->info.nama <<setw(25)<< bantu->info.alamat <<setw(35)<< bantu->info.tHargaObat <<endl;
		bantu = bantu->next;
	}while(bantu!=NULL && i!= Antrian);
	cout<<"------------------------------------------------------------------------------------------------"<<endl;
	cout<<endl<<"Jumlah Antrian : "<<Antrian;
	cout<<endl<<endl;
}

void enqueueR(simpan inputTemp)
{ typeptr1 NB;
  NB=(typequeue1 *) malloc(sizeof(typequeue1));
  NB->info2=inputTemp;
  if (Qdepan1==NULL)
	  Qdepan1=NB;
  else
	  Qbelakang1->prev=NB;
  Qbelakang1=NB;
  Qbelakang1->prev=NULL;
}

void bacaDataR() {
	typeptr1 bantu;
	int i = 0;
	bantu = Qdepan1;
	cout<<endl<<"                                   == RIWAYAT PEMBELIAN == ";
	cout<<endl<<"================================================================================================"<<endl;
	cout<<setw(4)<<" No "<<setw(10)<<" Nama "<<setw(20)<<" Alamat "<<setw(20)<<" total Harga Obat "<<endl;
	cout<<"------------------------------------------------------------------------------------------------"<<endl;
	do{
		i++;
		cout<<setw(4)<< i <<setw(10)<< bantu->info2.nama <<setw(20)<< bantu->info2.alamat <<setw(20)<< bantu->info2.tHargaObat <<endl;
		bantu = bantu->prev;
	}while(bantu != NULL && i != antrianRiwayat);
	cout<<"------------------------------------------------------------------------------------------------"<<endl;
	cout<<endl<<"Jumlah Antrian : "<<Antrian;
	cout<<endl<<endl;
}

void bacaData(ifstream &dataMasuk, int &antrianRiwayat, simpan info2, string &namaFile){
	simpan temp;
	/*cout<<"Masukkan Nama File : ";cin>>namaFile;
	cout<<"Masukkan Nama Batas : ";cin>>namaBatas;*/
	dataMasuk.open(namaFile, ios::in);
	while(!dataMasuk.eof()) {
		dataMasuk >> temp.nama;
		dataMasuk >> temp.alamat;
		dataMasuk >> temp.tHargaObat;
		/*cout << temp.nama << endl;
		cout << temp.alamat << endl;
		cout << temp.tHargaObat << endl;
		cout << "super" << endl;*/
		//if(temp.nama != NULL){
			enqueueR(temp);
		//}
	}
	dataMasuk.close();
	/*batasOutput1.open(namaBatas, ios::in);
	batasOutput1 >> antrianRiwayat;
	batasOutput1.close();*/
	
	
	typeptr1 bantu;
	int i = 0;
	bantu = Qdepan1;
	cout<<endl<<"                                   == RIWAYAT PEMBELIAN == ";
	cout<<endl<<"================================================================================================"<<endl;
	cout<<setw(4)<<" No "<<setw(10)<<" Nama "<<setw(20)<<" Alamat "<<setw(20)<<" total Harga Obat "<<endl;
	cout<<"------------------------------------------------------------------------------------------------"<<endl;
	do{
		i++;
		cout<<setw(4)<< i <<setw(10)<< bantu->info2.nama <<setw(20)<< bantu->info2.alamat <<setw(20)<< bantu->info2.tHargaObat <<endl;
		bantu = bantu->prev;
	}while(bantu != NULL && i != antrianRiwayat);
	cout<<"------------------------------------------------------------------------------------------------"<<endl;
	cout<<endl<<"Jumlah Antrian : "<<Antrian;
	cout<<endl<<endl;
}

//--> END QUEUE <--

//--> STACK POP <--
void pop(){
	typeptr hapus, bantuS;
	if(queueKosong()){
		cout<<"Antrian Masih Kosong !!"<<endl;
		}else{
			bantuS = Qdepan;
			hapus = Qbelakang;
			strcpy(namaHapus,hapus->info.nama);
			if(hapus == Qdepan)
				Qdepan1 = NULL;
				else{
					while(bantuS->next->next != NULL)
						bantuS = bantuS->next;
					Qbelakang = bantuS;
					Qbelakang->next = NULL;
					}
				free(hapus);
			}
			cout<<endl<<namaHapus;
}
//--> STACK POP <--

//--> LINKED LIST <<--
void menu2(){
	int pilihKaryawan, jumlahKar, cari, hapusList;
	char kembali2;
	typeptrList input;
	input = (typenode *) malloc(sizeof(typenode));
	do{
		cout<<" ____________________________"<<endl;
		cout<<"|                            |"<<endl;
		cout<<"|    === Menu Karyawan ===   |"<<endl;
		cout<<"|____________________________|"<<endl;
		cout<<"|                            |"<<endl;
		cout<<"| 1. Tambah Data Karyawan    |"<<endl;
		cout<<"| 2. Tampilkan Data Karyawan |"<<endl;
		cout<<"| 3. Cari Data Karyawan      |"<<endl;
		cout<<"| 4. Hapus Data Karyawan     |"<<endl;
		cout<<"| 5. Exit                    |"<<endl;
		cout<<"|____________________________|"<<endl;
		cout<<endl<<"Pilih Menu : ";cin>>pilihKaryawan;
		switch(pilihKaryawan){
			case 1 : 
				cout<<endl<<"---------------------------------------";
				cout<<endl<<"|       = Menu Input Karyawan =       |";
				cout<<endl<<"---------------------------------------"<<endl;
				cout<<endl<<" Berapa data Karyawan Yang ingin di Input = "; cin >> jumlahKar;
				for	(int i=1; i<=jumlahKar; i++){
					cout<<" Karyawan ke-"<<i;
					cout<<endl<<"  ID Karyawan		: ";cin>>input->infoList.id;
					cout<<"  Nama Karyawan		: ";cin.ignore();cin.getline(input->infoList.nama,sizeof(input->infoList.nama));
					cout<<"  Alamat 		: ";cin.getline(input->infoList.alamat,sizeof(input->infoList.alamat));
					cout<<"  No Telp		: ";cin>>input->infoList.notelp;
					sisipnode(input->infoList);
				}
			break;
			case 2 :
				cout<<endl<<"---------------------------------------";
				cout<<endl<<"|    = Menu Tampil Data Karyawan =    |";
				cout<<endl<<"---------------------------------------"<<endl;
				cetakdata();
			break;
			case 3 :
				cout<<endl<<"---------------------------------------";
				cout<<endl<<"|    = Menu Cari Data Karyawan =      |";
				cout<<endl<<"---------------------------------------"<<endl;
				cout<<endl<< " ID karyawan yang ingin dicari : "; cin >> cari;
				carinode(cari);
			break;
			case 4 :
				cout<<endl<<"---------------------------------------";
				cout<<endl<<"|       = Menu Hapus Karyawan =       |";
				cout<<endl<<"---------------------------------------"<<endl;
				cout<<endl<< " ID karyawan yang akan dihapus : "; cin >> hapusList;
				hapusnode(hapusList);
			break;
			case 5 :
				exit(0);
			break;
			default : 
				cout<<endl<<"== ANDA SALAH MEMASUKKAN MENU !! ";
			break;
		}cout<<endl<<"Kembali ke menu ? [ y/n ] : ";cin>>kembali2;
	}while(kembali2 == 'y' || kembali2 == 'Y');
}

void buatlistbaru()
{
	typeptrList list;
	list=NULL;
	awal=list;
	akhir=list;
}

int listkosong()
{
	if(awal==NULL){
		return (true);
	}
	else {
		return(false);
	}
}

void sisipnode(typeinfoList IB)
{
	typeptrList NB, bantu;
	NB=(typenode *) malloc(sizeof(typenode));
	NB->infoList=IB;
	if(listkosong()){
		awal=NB;
		akhir=NB;
		}else if(IB.id<=awal->infoList.id){
		NB->nextList=awal;
		awal=NB;
		}else{
			bantu=awal;
			while(bantu->nextList!=NULL && IB.id > bantu->nextList->infoList.id){
				bantu=bantu->nextList;
				}
			NB->nextList=bantu->nextList;
			bantu->nextList=NB;
			if(IB.id>akhir->infoList.id)
				akhir=NB;
		}
}

void cetakdata()
{
	typeptrList bantu;
	int i=1;
	bantu=awal;
	while(bantu!=NULL)
	{
		cout<<" Data Karyawan ke- " << i;
		cout << endl << "  ID Karyawan	: " << bantu->infoList.id;
		cout << endl << "  Nama Karyawan	: " << bantu->infoList.nama;
		cout << endl << "  Alamat		: " << bantu->infoList.alamat;
		cout << endl << "  No Telp		: " << bantu->infoList.notelp;
		cout << endl << endl;
		i++;
		bantu=bantu->nextList;
	}
}

void carinode(int IC)
{
	typeptrList bantu;
	bantu=awal;

	while(bantu!=NULL)
	{
			if(bantu->infoList.id==IC)
			{
				cout << endl << "  ID Karyawan	: " << bantu->infoList.id;
				cout << endl << "  Nama Karyawan	: " << bantu->infoList.nama;
				cout << endl << "  Alamat	: " << bantu->infoList.alamat;
				cout << endl << "  No Telp	: " << bantu->infoList.notelp;
				cout<<endl<<endl;
				bantu=bantu->nextList;
			}
			else {
				bantu=bantu->nextList;
			}
	}
}

void hapusnode(int IH)
{
	typeptrList hapus, bantu;
	if(listkosong())
		cout<<"List  masih kosong";
	else if(awal->infoList.id==IH)
	{ hapus=awal;
		awal=hapus->nextList;
		free(hapus); }
	else
	{bantu=awal;
		while(bantu->nextList->nextList!=NULL && IH!=bantu->nextList->infoList.id)
			  bantu=bantu->nextList;
		if(IH==bantu->nextList->infoList.id)
			{hapus=bantu->nextList;
				if(hapus==akhir)
				   {akhir=bantu;
						akhir->nextList=NULL; }
				else
					bantu->nextList=hapus->nextList;
				cout<<endl<<"Data dengan id "<<hapus->infoList.id<<"sudah di hapus.";
				free(hapus);
			}
		else
			cout<<"Data tidak ditemukan!\n"; }
}
// --> END LINKED LIST <--

