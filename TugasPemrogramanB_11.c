#include <stdio.h>
#include <math.h>

int main() {
    // Pengantar program
    printf("\nPrediksi Pertumbuhan Populasi Menggunakan Metode Heun Tanpa Iterasi\n");
    printf("----------------------------------------------------------\n");
    printf("Program ini memprediksi pertumbuhan populasi untuk ODE dP/dt = G*P\n");
    printf("menggunakan versi sederhana dari metode Heun (metode Euler yang diperbaiki).\n");
    printf("Anda dapat menggunakan konstanta yang sudah ditentukan atau memasukkan nilai sendiri.\n");
    printf("Metode Heun memperbaiki metode Euler dengan merata-ratakan kemiringan,\n");
    printf("namun di sini digunakan faktor koreksi yang sudah dihitung agar lebih efisien (tanpa iterasi).\n\n");

    // Notasi singkat:
    // P0 = Populasi awal
    // G  = Laju pertumbuhan per tahun
    // h  = Ukuran langkah (dalam tahun)
    // t  = Waktu total (dalam tahun)
    // P  = Populasi hasil estimasi Heun
    // P_exact = Populasi eksak berdasarkan solusi analitik

    // === INPUT ===
    // Pengguna diminta memilih apakah ingin menggunakan konstanta preset atau nilai input manual
    int option = 0;
    while (option != 1 && option != 2) {
        printf("Pilih opsi:\n");
        printf("1. Gunakan konstanta yang sudah ditentukan (P0 = 6000, G = 0.075, h = 0.5, 20 tahun)\n");
        printf("2. Masukkan nilai sendiri\n");
        printf("Masukkan pilihan Anda (1 atau 2): ");
        scanf("%d", &option);
        if (option != 1 && option != 2) {
            printf("Pilihan tidak valid. Silakan masukkan 1 atau 2.\n\n");
        }
    }

    // Deklarasi variabel utama
    double P0 = 0, G = 0, h = 0, years = 0;
    int steps = 0;

    if (option == 1) {
        // Konstanta yang sudah ditentukan sesuai dengan studi kasus dalam makalah
        P0 = 6000.0;
        G = 0.075;
        h = 0.5;
        years = 20.0;
        printf("\nMenggunakan konstanta yang sudah ditentukan:\n");
        printf("Populasi awal (P0): %.2f\n", P0);
        printf("Laju pertumbuhan (G): %.3f\n", G);
        printf("Ukuran langkah (h): %.2f\n", h);
        printf("Jumlah tahun: %.1f\n\n", years);
    } else {
        // Input manual dengan validasi: semua nilai harus positif
        int valid = 0;
        while (!valid) {
            printf("\nMasukkan populasi awal (P0): ");
            scanf("%lf", &P0);
            printf("Masukkan laju pertumbuhan per tahun (G), misal 0.075 untuk 7.5%%: ");
            scanf("%lf", &G);
            printf("Masukkan ukuran langkah (h), misal 0.5: ");
            scanf("%lf", &h);
            printf("Masukkan jumlah tahun yang ingin diprediksi: ");
            scanf("%lf", &years);

            if (P0 > 0 && G > 0 && h > 0 && years > 0) {
                valid = 1;
            } else {
                printf("\nSemua nilai harus positif. Silakan ulangi input Anda.\n");
            }
        }
        // Tampilkan nilai input yang dimasukkan pengguna
        printf("\nNilai input pengguna:\n");
        printf("Populasi awal (P0): %.2f\n", P0);
        printf("Laju pertumbuhan (G): %.3f\n", G);
        printf("Ukuran langkah (h): %.2f\n", h);
        printf("Jumlah tahun: %.1f\n\n", years);
    }

    // === PERHITUNGAN ===

    // Hitung jumlah langkah penuh dan sisa tahun (jika waktu tidak habis dibagi oleh h)
    steps = (int)(years / h);
    double last_step = years - steps * h;
    int has_partial = last_step > 1e-8;

    // Hitung faktor pengali berdasarkan metode Heun versi tertutup:
    // Faktor ini berasal dari metode Heun khusus untuk ODE linier dP/dt = G*P
    // Rumus: multiplier = 1 + (hG/2)(2 + hG)
    // Ini adalah hasil dari menyederhanakan metode Heun sehingga tidak perlu iterasi
    double multiplier = 1 + (h * G / 2) * (2 + h * G);

    // Cetak header tabel hasil
    printf(" n   |  t (tahun)  |    Populasi (Heun)    |   Populasi (Analitik)   |  Error (%%)\n");
    printf("-------------------------------------------------------------------------------\n");

    // Inisialisasi waktu dan populasi
    double P = P0;
    double t = 0.0;
    int n = 0;

    // Hitung nilai analitik dan error awal (n = 0)
    double P_exact = P0 * exp(G * t);
    double error = 100.0 * fabs(P - P_exact) / P_exact;
    printf("%3d  |%10.2f   |%20.2f   |%22.2f   |%10.4f\n", n, t, P, P_exact, error);

    // Iterasi untuk langkah penuh
    for (int i = 1; i <= steps; i++) {
        n++;
        P *= multiplier;
        t += h;
        P_exact = P0 * exp(G * t); // Solusi eksak: P(t) = P0 * exp(G * t)
        error = 100.0 * fabs(P - P_exact) / P_exact;
        printf("%3d  |%10.1f   |%20.2f   |%22.2f   |%10.4f\n", n, t, P, P_exact, error);
    }

    // Jika ada sisa langkah, lakukan langkah parsial terakhir
    if (has_partial) {
        n++;
        double h_partial = last_step;
        // Gunakan rumus koreksi Heun yang sama dengan h parsial
        double multiplier_partial = 1 + (h_partial * G / 2) * (2 + h_partial * G);
        P *= multiplier_partial;
        t += h_partial;
        P_exact = P0 * exp(G * t);
        error = 100.0 * fabs(P - P_exact) / P_exact;
        printf("%3d  |%10.1f   |%20.2f   |%22.2f   |%10.4f\n", n, t, P, P_exact, error);
    }

    // === OUTPUT RINGKASAN ===
    printf("\nPerhitungan analitik:\n");
    printf("P(t) = P0 * exp(G * t)\n");
    printf("Pada t = %.2f tahun: P(%.2f) = %.2f * exp(%.3f * %.2f) = %.2f\n",
           t, t, P0, G, t, P0 * exp(G * t));

    printf("\nRingkasan:\n");
    printf("Populasi akhir (metode Heun): %.2f\n", P);
    printf("Populasi akhir (analitik):    %.2f\n", P_exact);
    printf("Error absolut:                %.2f\n", fabs(P - P_exact));
    printf("Error relatif:                %.4f%%\n\n", error);

    // Catatan penutup untuk memperjelas konteks metode
    printf("Catatan:\n");
    printf("Metode ini menggunakan bentuk tertutup dari metode Heun karena ODE yang digunakan adalah linier (dP/dt = G*P).\n");
    printf("Untuk kasus ODE yang lebih kompleks (nonlinier), metode Heun biasa memerlukan iterasi dan evaluasi slope pada titik tengah.\n");
    printf("Namun untuk studi kasus ini, metode yang disederhanakan cukup akurat dan efisien.\n\n");

    return 0;
}
