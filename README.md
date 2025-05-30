<h1 align="center">Pemrograman B Komputasi Numerik</h1>


<h3 align="center">Kelompok 11</h3>

[**Raddief Ezra Satrio Andaru**](https://github.com/Raddief) - 2306250693

[**Muhammad Rafli**](https://github.com/MRafli127) - 2306250730

[**Muhammad Hilmi Al Muttaqi**](https://github.com/muhmhilmi) - 2306267082

[**Adhikananda Wira Januar**](https://github.com/adhikwj) - 2306267113

### Case Study Chapman Part 7
- [Numerical Methods for Engineers](https://www.mbit.edu.in/wp-content/uploads/2020/05/Numerical_methods_for_engineers_for_engi.pdf)
## Deskripsi Laporan

Laporan ini membahas penggunaan **metode Heun tanpa iterasi** untuk memprediksi pertumbuhan populasi berdasarkan **model eksponensial**, yang menyatakan bahwa laju perubahan populasi sebanding dengan jumlah populasi saat ini. Karena data populasi pada kenyataannya tersedia secara diskrit dan sering kali terpengaruh oleh kondisi dinamis, **metode numerik** menjadi penting sebagai alternatif pendekatan.

Dibandingkan dengan metode Euler biasa, **metode Heun** (yang merupakan bagian dari keluarga **Runge-Kutta orde dua**) menawarkan presisi yang lebih baik dengan mempertimbangkan rata-rata kemiringan antara titik awal dan titik prediksi.

### Parameter Simulasi Case Study

Dalam simulasi ini, digunakan model pertumbuhan populasi eksponensial dengan parameter sebagai berikut:

- **Populasi awal (p₀)**: 6000 orang
- **Laju pertumbuhan (G)**: 0.075 per tahun *(diasumsikan konstan)*
- **Interval waktu (h)**: 0.5 tahun
- **Periode simulasi**: hingga 20 tahun, sehingga menghasilkan **40 langkah iterasi**

### Tujuan

Pemilihan parameter ini bertujuan untuk:
- Merepresentasikan skenario pertumbuhan populasi yang realistis
- Menguji efektivitas metode Heun dalam memodelkan dinamika populasi
- Mendemonstrasikan akurasi metode numerik dalam estimasi bertahap terhadap solusi analitik

Metode ini menjadi pilihan ideal untuk kasus pertumbuhan populasi dengan laju tetap yang memerlukan **efisiensi komputasi** tanpa mengorbankan **akurasi prediksi**.

## Penjelasan Program C

Program C yang disediakan (berjudul `TugasPemrogramanB_11.c`) digunakan untuk memprediksi pertumbuhan populasi dengan **metode Heun tanpa iterasi** pada persamaan diferensial biasa (ODE) berbentuk `dP/dt = G*P`. Program ini membandingkan hasil estimasi numerik dengan solusi analitik (eksak) dan menghitung error-nya.

### Fitur Program:
- **Input Fleksibel:** Pengguna dapat memilih menggunakan parameter preset (studi kasus) atau memasukkan nilai sendiri (populasi awal, laju pertumbuhan, ukuran langkah, dan waktu prediksi).
- **Perhitungan Otomatis:** Program menghitung jumlah langkah penuh dan sisa waktu jika periode simulasi tidak habis dibagi ukuran langkah.
- **Metode Heun Tertutup:** Untuk ODE linier, digunakan rumus faktor pengali khusus sehingga tidak perlu iterasi pada setiap langkah.
- **Tabel Hasil:** Setiap langkah menampilkan waktu, populasi hasil metode Heun, populasi eksak, dan error relatif (%).
- **Ringkasan:** Di akhir, program menampilkan hasil akhir, error absolut dan relatif, serta penjelasan singkat tentang metode yang digunakan.

### Alur Program:
1. **Pengantar dan Pilihan Input:** Menjelaskan metode dan meminta pengguna memilih parameter preset atau input manual.
2. **Validasi Input:** Memastikan semua nilai yang dimasukkan positif.
3. **Perhitungan:** Menggunakan rumus Heun tertutup untuk setiap langkah waktu, serta menghitung solusi analitik untuk perbandingan.
4. **Output:** Menampilkan tabel hasil per langkah dan ringkasan perbandingan metode numerik dan analitik.

### Contoh Output:
```
 n   |  t (tahun)  |    Populasi (Heun)    |   Populasi (Analitik)   |  Error (%)
-------------------------------------------------------------------------------
  0  |      0.00   |             6000.00   |                6000.00   |    0.0000
  1  |      0.5    |             6222.19   |                6222.23   |    0.0001
  2  |      1.0    |             6455.23   |                6455.25   |    0.0000
...
```

### Catatan:
- Program ini efisien untuk ODE linier karena tidak memerlukan iterasi pada setiap langkah.
- Untuk ODE nonlinier, metode Heun biasanya memerlukan evaluasi slope pada titik tengah dan iterasi.

## Installation Guide

```
git clone https://github.com/Raddief/Kelompok11TugasPemrogramanB.git
```
