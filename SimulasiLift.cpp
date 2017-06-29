#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

class Lift{
	
	public:
	int nlift,nlantai;
	int posisiLift[50];
	int liftTerdekat[50];
	int indexLiftAktif;
	
	Lift(int newnlift,int newnlantai){
		nlift = newnlift;
		nlantai = newnlantai;
		posisiLift[nlift];
	}
	
	
	void setPosisiLift(int index,int posisi){
		posisiLift[index] = posisi;
	}
	
	void liftMenjemput(int posisiAwal){
		cariLiftTerdekat(posisiAwal);
		sortingLift();
		for(int i = 0 ; i < nlift ; i++ ){
			if( liftTerdekat[0] == fabs( posisiLift[i] - posisiAwal ) ){
				cout<<"Lift ke - "<<i<<" akan menuju ke posisi kamu yaitu di lantai "<<posisiAwal<<endl;
				indexLiftAktif = i;
				break;
			}
		}
	}
	
	void liftMengantar(int posisiTujuan){
		setPosisiLift(indexLiftAktif,posisiTujuan);
		cout<<"Lift berhasil mengantarkan kamu ke lantai "<<posisiTujuan<<endl<<endl;
	}
	
	void cariLiftTerdekat(int posisiAwal){
		for(int i =0 ; i < nlift ; i++){
			liftTerdekat[i] = fabs(posisiLift[i] - posisiAwal );
		}
	}
	
	void sortingLift(){
		int tmp;
		for( int i = 1 ; i < nlift ; i++ ){
			for ( int j = 0 ; j < nlift - i ; j++ ){
				if( liftTerdekat[j] > liftTerdekat[j+1] ){
					tmp = liftTerdekat[j];
					liftTerdekat[j] = liftTerdekat[j+1];
					liftTerdekat[j+1] = tmp;	
				}
			}
		}
		
	}
};


main(){
	int nlift,nlantai;
	
	//inisialisai diawal 
	cout<<"Masukkan jumlah lift : ";
	cin>>nlift;
	cout<<"Masukkan jumlah lantai : ";
	cin>>nlantai;
	
	//declare class
	Lift l(nlift,nlantai);
	
	system("cls");
	
	//set posisi lift
	cout<<"Atur posisi lift saat ini"<<endl<<endl;
	for(int i = 0 ; i < nlift ; i++){
		int posisi;
		do{
			cout<<"Posisi lift ke - "<<i<<" saat ini berada dilantai : ";
			cin>>posisi;
			if(posisi > nlantai){
				cout<<"Jumlah lantai yang tersedia hanya "<<nlantai<<" silahkan inputkan kembali"<<endl;
			}
			else{
				l.setPosisiLift(i,posisi);
			}
		}while(posisi > nlantai);
	}
	
	char status;
	do{
		system("cls");	
		//tampilkan ke layar
		cout<<"============== Dashboard Lift ==============="<<endl;
		for(int i = 0 ; i < nlift ;i++ ){
			cout<<"Lift ke - "<<i<<" saat ini sedang berada di lantai "<<l.posisiLift[i]<<endl;
		}
		cout<<endl;
		char statusLift;
		int posisiAwal,posisiTujuan;
			
		do{
			cout<<"Posisi kamu saat ini berada di lantai : ";
			cin>>posisiAwal;
			if( posisiAwal <= nlantai ){
				l.liftMenjemput(posisiAwal);
			}
		}while(posisiAwal > nlantai);
			
		do{
			cout<<"Kamu ingin menuju ke lantai : ";
			cin>>posisiTujuan;
			if( posisiTujuan <= nlantai ){
				l.liftMengantar(posisiTujuan);
			}
		}while(posisiTujuan > nlantai);
		
		cout<<"Apakah ingin menggunakan lift kembali ( y/n ) ?";
		cin>>status;
	}while(status == 'y');
	getch();
}
