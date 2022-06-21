#include <iostream>
#include <stdlib.h>
#include <string>
#define max 20
using namespace std;

void tampilkan_barang();
int main();
struct tumpukan{
    int atas;
    int nobarang[max];
    string namabarang[max];
    int hargabarang[max];

}T;

void awal()
{
    T.atas = -1;
}

int kosong()
{
    if(T.atas == -1)
    return 1;
    else
    return 0;
}

int penuh()
{
     if(T.atas == max-1)
     return 1;
     else
     return 0;
}

void input_barang(string namabarang, int hargabarang, int nobarang)
{
    if(kosong() == 1)
    {
        T.atas++;
        T.nobarang[T.atas] = nobarang;
        T.namabarang[T.atas] = namabarang;
        T.hargabarang[T.atas] = hargabarang;
        cout<<"\n"<<T.namabarang[T.atas]<<" Sudah masuk ke rak no "<< T.atas+1<<endl;
    }
    else if(penuh() == 0)
    {
         T.atas++;
        T.nobarang[T.atas] = nobarang;
        T.namabarang[T.atas] = namabarang;
        T.hargabarang[T.atas] = hargabarang;
        cout<<"\n"<<T.namabarang[T.atas]<<" Sudah masuk ke rak no "<< T.atas+1<<endl;
    }
    else
        cout<<"\nMaaf rak sudah penuh";
}

void tampilkan_barang()
{
    if(kosong() == 0)
    {
        for(int i = 0; i <= T.atas; i++)
        {
            cout<<"\n Barang terletak di rak no "<< i+1 <<endl;
            cout<<"Nama barang  : "<<T.namabarang[i] <<endl;
            cout<<"Harga        : Rp. "<<T.hargabarang[i]<<endl;
            cout<<"Kode Barang  : "<<T.nobarang[i]<<endl;
        }
    }
    else
        cout<<"\nRak masih kosong\n";
}

void edit()
{
    if(kosong() == 0)
    {
        int ganti, i;
        tampilkan_barang();

        cout<<"\n\nMasukkan kode barang yang akan diubah = ";
        cin>>ganti;
        cin.ignore();

        for (i = 0; i <= T.atas + 1; i++)
        {
            if(ganti == T.nobarang[i])
            {
                cout<<"Masukkan nama barang baru = ";
                getline(cin, T.namabarang[i]);
                cout<<"Masukkan harga barang baru = ";
                cin>>T.hargabarang[i];
                cout<<"Masukkan kode barang baru = ";
                cin>>T.nobarang[i];
                cout<<"\n\nData berhasil diubah\n";
            }else if(i > T.atas)
                cout<<"\nBarang tidak ditemukan"<<endl;   
        }
    }else
    cout<<"\nRak masih kosong\n";
}

void hapus()
{
    if(kosong() == 0)
    {
        tampilkan_barang();

        string tempnama;
        int temp, tempno, kode;
        int berhasil = 0;
        int i, j;
        int tempharga;
        cout<<"\nMasukan kode barang yang akan dihapus : ";
        cin>>kode;
        for(i = 0; i < T.atas + 1; i++)
        {
            for(j = 0; j < T.atas + 1; j++)
            {
                if(kode == T.nobarang[j])
                {
                    tempno = T.nobarang[j];
                    T.nobarang[j] = T.nobarang[j+1];
                    T.nobarang[j+1] = temp;

                    tempnama = T.nobarang[j];
                    T.namabarang[j] = T.namabarang[j+1];
                    T.namabarang[j+1] = temp;

                    berhasil = 1;
                }
            }
        }
        if(berhasil == 1)
        {
             cout<<"\nBarang berhasil dihapus\n";
        }
    }else
    {
        cout<<"\nRak masih kosong\n";
    }
}

void bersih()
{
    T.atas = -1;
    cout<<" ";
}


void sorting_nama()
{
    int i,j, tempno;
    string tempnama;
    int tempharga;

    for(i = 0; i < T.atas; i++)
    {
        for(j = 0; j < (T.atas-1); j++)
        {
            if(T.namabarang[j] > T.namabarang[j+1])
            {
                tempnama = T.namabarang[j];
                T.namabarang[j] = T.namabarang[j+1];
                T.namabarang[j+1] = tempnama;

                tempno = T.nobarang[j];
                T.nobarang[j] = T.nobarang[j+1];
                T.nobarang[j+1] = tempno;

                tempharga = T.hargabarang[j];
                T.hargabarang[j] = T.hargabarang[j+1];
                T.hargabarang[j+1] = tempharga;
            }
        }
    }
    system("cls");
    cout<<"\nBarang setelah diurutkan menurut Nama Barang "<<endl;
    tampilkan_barang();
}

void sorting_kode()
{
	int i, j, tempno;
	string tempnama;
	int tempharga;
	
	for (i = 0; i < T.atas; i++)
	{
		for (j = 0; j < (T.atas-i); j++)
		{
			if(T.nobarang[j] > T.nobarang[j+1])
			{
				tempno = T.nobarang[j];
				T.nobarang[j] = T.nobarang[j+1];
				T.nobarang[j+1] = tempno;
				
				tempnama = T.namabarang[j];
				T.namabarang[j] = T.namabarang[j+1];
				T.namabarang[j+1] = tempnama;
				
				tempharga = T.hargabarang[j];
				T.hargabarang[j] = T.hargabarang[j+1];
				T.hargabarang[j+1] = tempharga;
			}
		}
	}
	system("cls");
	cout << "\nBarang setelah diurutkan menurut Kode Barang" << endl;
	tampilkan_barang();
}

void sorting_harga()
{
	int i,j, tempno;
	string tempnama;
	int tempharga;
	for(i = 0; i < T.atas; i++)
	{
		for(j = 0; j < (T.atas-1); j++)
		{
			if(T.hargabarang[j] > T.hargabarang[j+1])
			{
				tempharga = T.hargabarang[j];
				T.hargabarang[j] = T.hargabarang[j+1];
				T.hargabarang[j+1] = tempharga;
				
				tempno = T.nobarang[j];
				T.nobarang[j] = T.nobarang[j+1];
				T.nobarang[j+1] = tempno;
				
				tempnama = T.namabarang[j];
				T.namabarang[j] = T.namabarang[j+1];
				T.namabarang[j+1] = tempharga;
			}
		}
	}
	system("cls");
	cout << "\nBarang setelah diurutkan menurut Harga" << endl;
	tampilkan_barang();
}

void search_nama()
{
	if(kosong() == 0)
	{
		string cari;
		
		cout << "Masukkan Nama Barang yang dicari : ";
		getline(cin,cari);
		
		for(int i = 0; i <= T.atas+1; i++)
		{
			if(cari == T.namabarang[i])
			{
				cout<< "\nBarang ada pada rak no "<<i+1<<endl;
				cout<< "Nama barang  : "<<T.namabarang[i]<<endl;
				cout<< "Harga        : "<<T.hargabarang[i]<<endl;
				cout<< "Kode barang  : "<<T.nobarang[i]<<endl;
			}else if(i > T.atas)
			{
				cout<<"\nPencarian selesai"<<endl;
				break;
			}
		}
	}else
		cout<<"\nRak masih kosong\n";
}

void search_kode()
{
	if(kosong() == 0)
	{
		int cari;
		
		cout<<"Masukan Kode barang yang dicari : ";
		cin>>cari;
		
		for(int i = 0; i <= T.atas+1; i++)
		{
			if(cari == T.nobarang[i])
			{
				cout<<"\nBarang ada pada rak no "<<i+1<<endl;
				cout<<"Kode barang  : "<<T.nobarang[i]<<endl;
				cout<<"Nama barang  : "<<T.namabarang[i]<<endl;
				cout<<"Harga        : "<<T.hargabarang[i]<<endl;
			}else if(i > T.atas)
			{
				cout<<"\nPencarian selesai"<<endl;
				break;	
			}
		}
	}else
		cout<<"\nRak masih kosong\n";
}


void search_harga()
{
    if(kosong()==0)
    {
        int cari;

        cout<<"Masukkan Harga Barang yang Dicari : ";
        cin>>cari;

        for(int i=0;i<=T.atas+1;i++)
        {
            if(cari == T.hargabarang[i])
            {
                cout<<"\nBarang ada pada rak no "<<i+1<<endl;
                cout<<"Nama barang  : "<<T.namabarang[i]<<endl;
                cout<<"Harga        : "<<T.hargabarang[i]<<endl;
                cout<<"Kode barang  : "<<T.nobarang[i]<<endl;
            }else if(i>T.atas)
            {
                cout<<"\nPencarian selesai"<<endl;
                break;
            }
        }
    }else
        cout<<"\nEtalase kosong\n";
}

void menu_sorting()
{
    int pilihan;

    cout<<"1. Mengurutkan Menurut Nama Barang\n";
    cout<<"2. Mengurutkan Menurut Kode Barang\n";
    cout<<"3. Mengurutkan Menurut Harga Barang\n";
    cout<<"4. Kembali ke Menu Awal\n";
    cout<<"Masukkan pilihan : ";
    cin>>pilihan;

    switch (pilihan)
    {
        case 1:
            sorting_nama();
            break;
        
        case 2:
            sorting_kode();
            break;
        
        case 3:
            sorting_harga();
            break;
        
        case 4:
            int main();
            break;
    }
}

void menu_search()
{
    int pilihan;

    cout<<"1. Mencari Menurut Nama Barang\n";
    cout<<"2. Mencari Menurut Kode Barang\n";
    cout<<"3. Mencari Menurut Harga Barang\n";
    cout<<"4. Mencari ke Menu Awal\n";
    cout<<"Masukkan pilihan : ";
    cin>>pilihan;
    cin.ignore();

    switch (pilihan)
    {
        case 1:
            search_nama();
            break;
        
        case 2:
            search_kode();
            break;
        
        case 3:
            search_harga();
            break;
        
        case 4:
            int main();
            break;
    }
}

int main(){

    awal();
    system("cls");

    int pilihan, n, nobarang[max];
    string namabarang[max];
    int hargabarang[max];

    do
    {
    cout<<"==================================================="<<endl;
    cout<<"|           FINAL PROJECT KELOMPOK 7              |"<<endl;
    cout<<"|    MAULANA RIZKY RAHMADHANI (21.11.4465)        |"<<endl;
    cout<<"|       MUHAMMAD QURAIS SIHAB (21.11.4407)        |"<<endl;
    cout<<"|           ALEX FREDY SUJITO (21.11.4403)        |"<<endl;
    cout<<"|          BAGUS ADHI LAKSANA (21.11.4439)        |"<<endl;
    cout<<"|            RAIHAN MAULUDANA (21.11.4453)        |"<<endl;
    cout<<"|             PROGRAM WAREHOUSE TECHNO            |"<<endl;
    cout<<"==================================================="<<endl;
    cout<<" "<<endl;
    cout<<" "<<endl;
    cout<<"1. Input Barang"<<endl;
    cout<<"2. Hapus Barang"<<endl;
    cout<<"3. Tanpilkan Barang"<<endl;
    cout<<"4. Urutkan Barang"<<endl;
    cout<<"5. Cari Barang"<<endl;
    cout<<"6. Edit Barang"<<endl;
    cout<<"7. Bersihkan Barang"<<endl;
    cout<<"8. Keluar"<<endl;
    cout<<"Masukan pilihan : ";
    cin>>pilihan;

    switch(pilihan)
    {
        case 1:

        system("cls");

        cout << "INPUT BARANG"<< endl;
        cout << "Masukan banyak barang yang akan dimasukkan ke Rak (max 20) : ";
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            cin.ignore();
            cout << "Masukkan barang ke-"<< i+1;
            cout << "Nama Barang :";
            getline(cin, namabarang[i]);

            cout << "Harga barang   : ";
            cin >>hargabarang[i];
            cin.ignore();
            
            cout<< "Kode Barang : ";
            cin >> nobarang[i];

            input_barang(namabarang[i], hargabarang[i], nobarang[i]);
        }
        break;

        case 2:

        system("cls");

        cout << "HAPUS BARANG"<<endl;
        hapus();
        break;

        case 3:

        system("cls");

        cout << "TAMPILKAN BARANG"<<endl;
        tampilkan_barang();
        break;

        case 4:

        system("cls");

        cout << "MENGURUTKAN BARANG"<<endl;
        menu_sorting();
        break;

        case 5:

        system("cls");

        cout << "MENCARI BARANG"<<endl;
        menu_search();
        break;

        case 6:

        system("cls");

        cout << "MENGEDIT BARANG"<<endl;
        edit();
        break;

        case 7:

        system("cls");

        cout << "RAK SUDAH BERSIH"<<endl;
        break;

        case 8:

        system("cls");

        cout<<"======================="<<endl;
        cout<<"===  TERIMA KASIH   ==="<<endl;
        cout<<"======================="<<endl;
        cout<<endl;    
    }
    cout << endl;
    system("pause");
    system("cls");
    }
    while (pilihan != 8);
}
