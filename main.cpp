/* menghitung Billing Warnet*/
//PemrogramanDasar
//Much Kholiqul Rosidin
//NIM 20051397058
//2020B

#include <iostream>
#ifdef __WINDOWS__
#include <conio.h>
#endif

#ifdef __linux__
#include <curses.h>
#endif

using namespace std;


void hashOut(){

    for(int i = 0; i <= 75; i++){

        cout << "#";

    }

    cout << endl;
}

int textOut(string text){

    cout << text;
    return 0;

}


int main(void){

    bool retry = false;
    //string key = '';
    tm* j1;
    tm* j2;
    const int det = 3600;
    int tarifPerjam = 5000;
    int jumlahJam, jumlahMenit, jumlahDetik, totalInSecond, j1s, j1m, j1h, j2s, j2m, j2h, jumlahBayar;


    hashOut();
    textOut("Selamat Datang di Program Sederhana menghitung tarif pemakaian billing \n");
    hashOut();
    hashOut();
    textOut("\n");
    textOut("Apakah Anda Ingin Memulai Billing? (tekan enter jika iya)");
    textOut("\n\n");
    if(cin.get() =='\n'){
        time_t thistme = time(NULL);
        tm* localtmm = localtime(&thistme);
        hashOut();
        textOut("Billing dimulai ...... \n");
        hashOut();
        j1 = localtmm;
        j1s = j1->tm_sec;
        j1m = j1->tm_min;
        j1h = j1->tm_hour;

        textOut("Tekan Enter jika ingin menghentikan billing");
        if(cin.get() == '\n'){
            time_t thistime = time(NULL);
            tm* localtm = localtime(&thistime);
            j2 = localtm;
            j2s = j2->tm_sec;
            j2m = j2->tm_min;
            j2h = j2->tm_hour;
            jumlahJam = j2h - j1h;
            jumlahMenit = j2m - j1m;
            jumlahDetik = j2s - j1s;
            totalInSecond = jumlahJam * det + jumlahMenit * 60 + jumlahDetik;
            jumlahJam = totalInSecond / det;
            jumlahMenit = (totalInSecond % det) / 60;
            jumlahDetik = (totalInSecond % det) % 60;
            jumlahBayar = tarifPerjam / det * totalInSecond;

            textOut("\n\n");
            hashOut();
            hashOut();
            cout << "anda telah menggunakan billing selama " << jumlahJam << " Jam " << jumlahMenit << " Menit " << jumlahDetik << " Detik" << endl;
            cout << "total bayar anda sesudah menggunakan billing yaitu Rp. " << jumlahBayar << ",-" << endl;
            hashOut();
        }
    } else if(cin.get() != '\n'){

    textOut("Penghitungan dibatalkan. Terimakasih sudah memakai program sederhana ini!");

    }

    return 0;
}

