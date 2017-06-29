#include <iostream>
#include <conio.h>

using namespace std;

int index = 0;
int first_index = 0;

class VendingMachine {
	
	public :
		
		int itemSaya;
		string itemName[15] = {"Teh Kotak","Mizone   ","Teh Pucuk","Aqua     ","Pocari   ","Sprite   ","Fanta    ","Cola cola","Freshtea "};
		int priceItem[15] = {15000,10000,15000,14000,10000,15000,10000,14000,15000};
		int stokItem[15] = {8,5,7,6,5,3,5,5,7};
		int uangSaya[30];
		
		VendingMachine(){
			Rules();
			getch();
			system("cls");
			ListItem();
		}
		
		void Rules(){
			cout<<"=== Berikut Peraturan Menggunakan Mesin Ini ==="<<endl;
			cout<<"\n";
			cout<<"1.Masukkan uang yang sesuai dengan apa yang ingin kalian beli"<<endl;
			cout<<"2.Pilih item yang ingin kalian belikan"<<endl;
			cout<<"3.Pastikan uang kalian sesuai dengan item yang ingin dibelikan"<<endl;
			cout<<"4.Semua inputan pastikan menggunakan number tidak menggunakan alphabet"<<endl;
			cout<<"5.Tekan enter untuk memulai"<<endl;	
		}
		
		void ListItem(){
			char option;
			bool error = true;
			do{
				try{
					system("cls");
					int status = 0;
					int status_item = true;
					cout<<"|========================================================|"<<endl;
					cout<<"|                                                        |"<<endl;
					cout<<"|       List Minuman Vending Machine Jakarta Barat       |"<<endl;
					cout<<"|                                                        |"<<endl;
					cout<<"|--------------------------------------------------------|"<<endl;
					cout<<"| Kode Minuman |    Nama Item    |  Jumlah   |   Harga   |"<<endl;
					cout<<"|--------------------------------------------------------|"<<endl;
					for(int i =0 ; i < 9 ; i++){
						cout<<"|       "<<i<<"      |  "<<itemName[i]<<"      |      "<<stokItem[i]<<"  |    "<<priceItem[i]<<"    |"<<endl;
					}
					cout<<"|--------------------------------------------------------|"<<endl;
					cout<<endl;
					do{			
						if(status == 0){
							cout<<"Masukkan uang  : ";
							if(!(cin>>uangSaya[index])){
								error = false;
								throw error;
							}
							first_index = index;
							index++;
							status = 1;
							cout<<"Pilih kode minuman : ";
							if(!(cin>>itemSaya)){	
								error = false;
								throw error;
							}
							if(itemSaya >= 9 ){
								status_item = false;
								cout<<"\nMaaf untuk minuman tersebut tidak tersedia"<<endl;
							}
							else {
								if(stokItem[itemSaya] == 0){
									status_item = false;
									cout<<"\nMaaf untuk minuman tersebut saat ini sedang kosong"<<endl;
								}
							}							
						}
						else{
							cout<<"Uang yang anda miliki masih kurang"<<endl;
							cout<<"Jumlah uang anda saat ini : "<<totalUangSaya()<<endl;
							cout<<"Masukkan uang : ";
							cin>>uangSaya[index];
							index++;
						}
						cout<<endl;
					}while( totalUangSaya() < priceItem[itemSaya] && status_item != false );
					if(status_item == false){
						cout<<"Pembelian anda dibatalkan"<<endl;
					}
					else{
						stokItem[itemSaya]--;
						cout<<"Pembelian anda telah berhasil"<<endl;
						cout<<"Anda telah membeli "<<itemName[itemSaya]<<" dengan harga "<<priceItem[itemSaya]<<endl<<endl;
					}
					cout<<"Ingin melakukannya kembali (y/n) :";
					cin>>option;
				}
				catch(bool error){
					cout<<"Inputan yang dimasukkan harus angka tidak boleh huruf "<<endl;
				}
			}while( option != 'n' && error == true );
		
		
		}
		
		float totalUangSaya(){
			float totalUang = 0 ;
			for(int i = first_index ; i < index ; i++ ){
				totalUang += uangSaya[i];
			}
			return totalUang;
		}
		
		float totalUangMesin(){
			float totalUangMsn = 0;
			for( int i = 0 ; i < index ; i++ ){
				totalUangMsn += uangSaya[i];
			}
			return totalUangMsn;
		}

	
};

main(){
	VendingMachine Ven;	
	getch();
	
	/* AZHAR PRABUDI */
}
