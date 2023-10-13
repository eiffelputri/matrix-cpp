#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;
int batas_baris, batas_kolom;
float matriks[50][50], hasil[50][50];
char ulang, hitung_lagi;

void reset(){
    for(int i = 0; i < batas_baris; i++){
        for(int j = 0; j < batas_kolom; j++){
            hasil[i][j] = 0;
        }
    }
}

void penjumlahanMatriks(){
    // loop hitung lagi
    do{
        cout << "Masukkan batas baris dan kolom: "; cin >> batas_baris >> batas_kolom;
        cout << "\n";

        // loop input
        do{
            cout << "Masukkan nilai matriks: \n";
            for(int i = 0; i < batas_baris; i++){
                for(int j = 0; j < batas_kolom; j++){
                    cin >> matriks[i][j];
                }
            }
            cout << "\n";

            // proses sum
            for(int i = 0; i < batas_baris; i++){
                for(int j = 0; j < batas_kolom; j++){
                    hasil[i][j] = hasil[i][j] + matriks[i][j];
                }
            }

            cout << "Mau input matriks lagi?(Y/T) "; cin >> ulang;
        }while(ulang == 'Y' || ulang == 'y');
        cout << "\n";

        // hasil
        cout << "Hasil Penjumlahan Matriks: \n";
        for(int i = 0; i < batas_baris; i++){
            for(int j = 0; j < batas_kolom; j++){
                cout << "\t" << hasil[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "\n";

        cout << "Mau hitung matriks lagi?(Y/T) "; cin >> hitung_lagi;
        reset();
    }while(hitung_lagi == 'Y' || hitung_lagi == 'y');
    cout << "Press Enter to Continue...";
}

void penguranganMatriks(){
    float matriks_awal[50][50];

    // pengulangan hitung_lagi
    do{
        cout << "Masukkan batas baris dan kolom: "; cin >> batas_baris >> batas_kolom;
        cout << "\n";

        cout << "Masukkan nilai matriks pertama: \n";
        for(int i = 0; i < batas_baris; i++){
            for(int j = 0; j < batas_kolom; j++){
            cin >> matriks_awal[i][j];
            }
        }
        cout << "\n";

        // proses ke-1
        for(int i = 0; i < batas_baris; i++){
            for(int j = 0; j < batas_kolom; j++){
                hasil[i][j] = matriks_awal[i][j] - hasil[i][j];
            }
        }

        // pengulangan input
        do{
            cout << "Masukkan nilai matriks: \n";
            for(int i = 0; i < batas_baris; i++){
                for(int j = 0; j < batas_kolom; j++){
                cin >> matriks[i][j];
                }
            }
            cout << "\n";

            // proses ke-2
            for(int i = 0; i < batas_baris; i++){
                for(int j = 0; j < batas_kolom; j++){
                    hasil[i][j] = hasil[i][j] - matriks[i][j];
                }
            }

            cout << "Mau input matriks lagi?(Y/T) "; cin >> ulang;
        }while(ulang == 'Y' || ulang == 'y');
        cout << "\n";

        // hasil
        cout << "Hasil Pengurangan Matriks: " << endl;
        for(int i = 0; i < batas_baris; i++){
            for(int j = 0; j < batas_kolom; j++){
                cout << "\t" << hasil[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "\n";
        cout << "Mau hitung matriks lagi?(Y/T) "; cin >> hitung_lagi;
        reset();
    }while(hitung_lagi == 'Y' || hitung_lagi == 'y');
    cout << "Press Enter to Continue...";
}

void perkalianMatriks(){
    string jenis_kali;
    int bilangan, batas_baris_1, batas_kolom_1, batas_baris_2, batas_kolom_2;
    float matriks_1[50][50], matriks_2[50][50];

    // pengulangan hitung_lagi
    do{
        coba_lagi:
        cout << "Ingin menghitung perkalian skalar atau antar matriks?(Skalar/Antar) "; cin >> jenis_kali;
        cout << "\n";
        if(jenis_kali == "Skalar" || jenis_kali == "skalar"){
            cout << "Masukkan bilangan: "; cin >> bilangan;
            cout << "\n";
            cout << "Masukkan batas baris dan kolom: "; cin >> batas_baris >> batas_kolom;
            cout << "Masukkan nilai matriks: \n";
            for(int i = 0; i < batas_baris; i++){
                for(int j = 0; j < batas_kolom; j++){
                    cin >> matriks[i][j];
                }
            }
            cout << "\n";

            // proses
            cout << "Hasil kali matriks dengan bilangan " << bilangan << ": \n";
            for(int i = 0; i < batas_baris; i++){
                for(int j = 0; j < batas_kolom; j++){
                    hasil[i][j] = bilangan * matriks[i][j];
                    cout << "\t" << hasil[i][j] << "\t";
                }
                cout << "\n";
            }
            cout << "\n";
        }
        else if(jenis_kali == "Antar" || jenis_kali == "antar"){
            lagi:
            cout << "Masukan batas baris dan kolom matriks pertama: "; cin >> batas_baris_1 >> batas_kolom_1;
            cout << "Masukan batas baris dan kolom matriks kedua: "; cin >> batas_baris_2 >> batas_kolom_2;
            cout << "\n";
            // jika kolom matriks 1 dan baris matriks 2 tidak sama
            if(batas_kolom_1 != batas_baris_2){
                cout << "Kolom matriks pertama dan baris matriks kedua tidak sama, coba lagi..."; _getch();
                cout << "\n\n";
                goto lagi;
            }
            else{
                cout << "Masukkan nilai matriks pertama: \n";
                for(int i = 0; i < batas_baris_1; i++){
                    for(int j = 0; j < batas_kolom_1; j++){
                        cin >> matriks_1[i][j];
                    }
                }
                cout << "\n";

                cout << "Masukkan nilai matriks kedua: \n";
                for(int i = 0; i < batas_baris_2; i++){
                    for(int j = 0; j < batas_kolom_2; j++){
                        cin >> matriks_2[i][j];
                    }
                }
                cout << "\n";

                // inisialisasi ke 0
                for(int i = 0; i < batas_baris_1; ++i){
                    for(int j = 0; j < batas_kolom_2; ++j){
                        hasil[i][j]=0;
                    }
                }

                // proses
                for(int i = 0; i < batas_baris_1; ++i){
                    for(int j = 0; j < batas_kolom_2; ++j){
                        for(int k = 0; k < batas_kolom_1; ++k){
                            hasil[i][j] += matriks_1[i][k] * matriks_2[k][j];
                        }
                    }
                }

                cout << "Hasil Perkalian antar Matriks: \n";
                for(int i = 0; i < batas_baris_1; ++i){
                    for(int j = 0; j < batas_kolom_2; ++j){
                        cout << "\t" << hasil[i][j] << "\t";
                    }
                    cout << "\n";
                }
                cout << "\n";
            }
        }
        else{
            cout << "Pilihan tidak ada, coba lagi...";
            _getch();
            system("cls");
            goto coba_lagi;
        }
        cout << "Mau menghitung matriks lagi?(Y/T) "; cin >> hitung_lagi;
        reset();
    }while(hitung_lagi == 'Y' || hitung_lagi == 'y');
    cout << "Press Enter to Continue...";
}

void transposeMatriks(){
    float transpose[50][50];
    do{
        cout << "Masukkan batas baris dan kolom: "; cin >> batas_baris >> batas_kolom;
        cout << "\n";

        cout << "Masukkan nilai matriks: \n";
        for(int i = 0; i < batas_baris; i++){
            for(int j = 0; j < batas_kolom; j++){
                cin >> matriks[i][j];
            }
        }
        cout << "\n";

        // proses
        for(int i = 0; i < batas_baris; i++){
            for(int j = 0; j < batas_kolom; j++){
                transpose[j][i] = matriks[i][j];
            }
        }

        cout << "Hasil Transpose Matriks: \n";
        for(int i = 0; i < batas_kolom; i++){ // rumus batas dibalik
            for(int j = 0; j < batas_baris; j++){
                cout << "\t" << transpose[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << "\n";

        cout << "Mau transpose matriks lagi?(Y/T) "; cin >> hitung_lagi;
    }while(hitung_lagi == 'Y' || hitung_lagi == 'y');
    cout << "Press Enter to Continue...";
}

void kofaktorMatriks(float matriks[50][50], float tampung[50][50], int p, int q, int n){
    int i = 0, j = 0;
    // Loop u/. setiap elemen matriks
    for (int batas_baris = 0; batas_baris < n; batas_baris++){
        for (int batas_kolom = 0; batas_kolom < n; batas_kolom++){
            // menampung matriks kofaktor yg baris dan kolomnya bukan yg dihilangkan
            // cout << "\t"<< matriks[batas_baris][batas_kolom] << "\t";
            if (batas_baris != p && batas_kolom != q){
                tampung[i][j++] = matriks[batas_baris][batas_kolom];

                // baris terisi, index baris bertambah dan mereset index kolom
                if (j == n - 1){
                    j = 0;
                    i++;
                }
            }
        } // cout << endl;
    } // cout << endl;
}

// Fungsi rekursif u/. mencari determinan
int determinanMatriks(float matriks[50][50], int n){ // n -> ordo matriks[][]
    int hasilDet = 0; // Inisialisasi awal
    //  Kondisi dimana matriks memiliki 1 elemen saja
    if (n == 1){
        return matriks[0][0];
    }

    float tampung[50][50]; // untuk menampung kofaktor

    int sign = 1; // menampung tanda perkalian 1

    // Loop u/. setiap elemen baris pertama (f -> first)
    for (int f = 0; f < n; f++){
        // Memanggil kofaktor dari matriks[0][f]
        kofaktorMatriks(matriks, tampung, 0, f, n);
        hasilDet += sign * matriks[0][f] * determinanMatriks(tampung, n - 1);

        // [+ - + -]
        sign = -sign;
    }
    // cout << "Hasil det: " << hasilDet << endl;
    return hasilDet;
}

void adjointMatriks(float matriks[50][50], float adjointMtrx[50][50]){
    if (batas_baris && batas_kolom == 1) { // A(invers) = (1/det) * Adj
        adjointMtrx[0][0] = 1;
        return;
    }

    // var. tampung = menampung kofaktor matriks
    float sign = 1, tampung[50][50];

    for (int i = 0; i < batas_baris; i++) {
        for (int j = 0; j < batas_kolom; j++) {
            // Memanggil fungsi kofaktor
            kofaktorMatriks(matriks, tampung, i, j, batas_baris);

            // kofaktor ke adj -> C11 = -1^2 * (); C12 = -1^3 * (); dst.
            sign = ((i + j) % 2 == 0) ? 1 : -1;

            // transpose matriks
            adjointMtrx[j][i] = (sign) * (determinanMatriks(tampung, batas_baris - 1));
        }
    }
}

bool inverseMatriks(float matriks[50][50], float inverseMtrx[50][50]){
    // Kondisi jika determinan matriks = 0 (matriks singular)
    int det = determinanMatriks(matriks, batas_baris);
    if (det == 0) {
        cout << "Matriks singular, tidak bisa inverse";
        return false;
    }

    // Mencari adjoint
    float adjoint[50][50];
    adjointMatriks(matriks, adjoint);

    // Rumus inverse =  adj[][]/determinan
    for (int i = 0; i < batas_baris; i++)
        for (int j = 0; j < batas_kolom; j++)
            inverseMtrx[i][j] = adjoint[i][j] / float(det);

    return true;
}

void hasilDeterminanMatriks(){
    do{
        lagi:
        cout << "Masukkan batas baris dan kolom: "; cin >> batas_baris >> batas_kolom;
        cout << "\n";
        if(batas_baris != batas_kolom){
            cout << "Baris dan kolom matriks tidak sama, coba lagi..."; _getch();
            cout << "\n\n";
            goto lagi;
        }
        else{
            cout << "Masukkan nilai matriks: \n";
            for(int i = 0; i < batas_baris; i++){
                for(int j = 0; j < batas_kolom; j++){
                    cin >> matriks[i][j];
                }
            }
            cout << "\n";

            cout << "Hasil Determinan Matriks: " << determinanMatriks(matriks, batas_baris) << "\n";
        }
        cout << "\n";
        cout << "Mau cari determinan matriks lagi? "; cin >> hitung_lagi;
    }while(hitung_lagi == 'Y' || hitung_lagi == 'y');
    cout << "Press Enter to Continue...";
}

void hasilAdjointMatriks(){
    float adj[50][50];
    do{
        lagi:
        cout << "Masukkan batas baris dan kolom: "; cin >> batas_baris >> batas_kolom;
        cout << "\n";
        if(batas_baris != batas_kolom){
            cout << "Baris dan kolom matriks tidak sama, coba lagi..."; _getch();
            cout << "\n\n";
            goto lagi;
        }
        else{
            cout << "Masukkan nilai matriks: \n";
            for(int i = 0; i < batas_baris; i++){
                for(int j = 0; j < batas_kolom; j++){
                    cin >> matriks[i][j];
                }
            }
            cout << "\n";

            cout << "Hasil Adjoint Matriks: \n";
            adjointMatriks(matriks, adj);
            for(int i = 0; i < batas_baris; i++){
                for(int j = 0; j < batas_kolom; j++){
                    cout << "\t" << adj[i][j] << "\t";
                }
                cout << "\n";
            }
        cout << "\n";
        cout << "Mau cari adjoint matriks lagi? "; cin >> hitung_lagi;
        }
    }while(hitung_lagi == 'Y' || hitung_lagi == 'y');
    cout << "Press Enter to Continue...";
}

void hasilInverseMatriks(){
    float inverse[50][50];
    do{
        lagi:
        cout << "Masukkan batas baris dan kolom: "; cin >> batas_baris >> batas_kolom;
        cout << "\n";
        if(batas_baris != batas_kolom){
            cout << "Baris dan kolom matriks tidak sama, coba lagi..."; _getch();
            cout << "\n\n";
            goto lagi;
        }
        else{
            cout << "Masukkan nilai matriks: \n";
            for(int i = 0; i < batas_baris; i++){
                for(int j = 0; j < batas_kolom; j++){
                    cin >> matriks[i][j];
                }
            }
            cout << "\n";

            cout << "Hasil Inverse Matriks: \n";
            if(inverseMatriks(matriks, inverse)){
                for(int i = 0; i < batas_baris; i++){
                    for(int j = 0; j < batas_kolom; j++){
                        cout << "\t" << inverse[i][j] << "\t";
                    }
                    cout << "\n";
                }
            }
        cout << "\n";
        cout << "Mau cari inverse matriks lagi? "; cin >> hitung_lagi;
        }
    }while(hitung_lagi == 'Y' || hitung_lagi == 'y');
    cout << "Press Enter to Continue...";
}

int main()
{
    int pil;
    do
    {
        system("cls");
        cout<<endl;
        cout<<" +-------------------------------+"<<endl;
        cout<<" |        PROGRAM MATRIKS        |"<<endl;
        cout<<" |         A11.2021.13374        |"<<endl;
        cout<<" |===============================|"<<endl;
        cout<<" | 1. Penjumlahan Matriks        |"<<endl;
        cout<<" | 2. Pengurangan Matriks        |"<<endl;
        cout<<" | 3. Perkalian Matriks          |"<<endl;
        cout<<" | 4. Transpose Matriks          |"<<endl;
        cout<<" | 5. Determinan Matriks         |"<<endl;
        cout<<" | 6. Adjoint Matriks            |"<<endl;
        cout<<" | 7. Inverse Matriks            |"<<endl;
        cout<<" | 8. Exit                       |"<<endl;
        cout<<" +-------------------------------+"<<endl;
        cout<<" Masukan Pilihan : ";cin >> pil;
        switch(pil){
            case 1: system("cls");
                penjumlahanMatriks();
                break;
            case 2: system("cls");
                penguranganMatriks();
                break;
            case 3: system("cls");
                perkalianMatriks();
                break;
            case 4: system("cls");
                transposeMatriks();
                break;
            case 5: system("cls");
                hasilDeterminanMatriks();
                break;
            case 6: system("cls");
                hasilAdjointMatriks();
                break;
            case 7: system("cls");
                hasilInverseMatriks();
                break;
            case 8: system("cls");
                return 0;
                break;
            default : system("cls");
            {
                cout<<"\n Maaf, Pilihan yang anda pilih tidak tersedia!";
                break;
            }
        }
        _getch();
    }while(pil!=9);
    return 0;
}
