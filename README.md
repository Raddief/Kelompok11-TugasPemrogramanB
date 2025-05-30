
<h1 align="center">Pemprograman B Komputasi Numerik</h1>


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


## Installation Guide

```
git clone https://github.com/Raddief/Kelompok11TugasPemrogramanB.git
```
