# Dokumen Pengujian Sistem: 8-bit Binary Counter

Dokumen ini berisi pencatatan hasil pengujian fungsional (I/O dan Control Unit) serta pengujian metrik kinerja pada simulator Wokwi. Data terukur di bawah ini digunakan sebagai bahan analisis sistem.

## 1. Pengujian Representasi Biner (Register ke Output LED)
Pengujian ini memastikan bahwa nilai desimal dalam register 8-bit diterjemahkan dengan benar ke dalam bentuk biner pada 8 LED bar (LED 7 = MSB, LED 0 = LSB).

| Nilai Desimal (Register) | Nilai Biner Seharusnya | Tampilan LED (MSB -> LSB) | Status (Pass/Fail) |
| :--- | :--- | :--- | :--- |
| 0 | `00000000` | ⚫⚫⚫⚫⚫⚫⚫⚫ | [ ] |
| 1 | `00000001` | ⚫⚫⚫⚫⚫⚫⚫🔴 | [ ] |
| 2 | `00000010` | ⚫⚫⚫⚫⚫⚫🔴⚫ | [ ] |
| 85 | `01010101` | ⚫🔴⚫🔴⚫🔴⚫🔴 | [ ] |
| 127 | `01111111` | ⚫🔴🔴🔴🔴🔴🔴🔴 | [ ] |
| 255 | `11111111` | 🔴🔴🔴🔴🔴🔴🔴🔴 | [ ] |

*(Keterangan: 🔴 = LED Menyala/HIGH, ⚫ = LED Mati/LOW)*

## 2. Pengujian Logika Control Unit (Tombol I/O)
Pengujian ini memastikan respons mikrokontroler terhadap sinyal dari perangkat input eksternal dan penanganan kondisi memori (Overflow/Underflow).

| Komponen | Aksi / Kondisi | Hasil yang Diharapkan | Hasil Aktual | Status |
| :--- | :--- | :--- | :--- | :--- |
| **Tombol Reset** | Ditekan saat counter berjalan di angka acak | Register langsung di-clear ke 0 (Semua LED mati) | ... | [ ] |
| **Tombol Reset** | Ditekan dan ditahan | Register terkunci di angka 0 dan tidak berjalan | ... | [ ] |
| **Tombol Up/Down** | Ditekan 1 kali saat arah UP | Arah hitungan (ALU) berubah menjadi DOWN (Decrement) | ... | [ ] |
| **Tombol Up/Down** | Ditekan 1 kali saat arah DOWN | Arah hitungan (ALU) kembali menjadi UP (Increment) | ... | [ ] |
| **Batas Overflow** | Counter UP melewati 255 | Register memutar nilai (overflow) kembali ke 0 | ... | [ ] |
| **Batas Underflow**| Counter DOWN melewati 0 | Register memutar nilai (underflow) kembali ke 255 | ... | [ ] |

## 3. Pengujian Clock / Timing (Data Terukur)
Pengujian ini dilakukan dengan memantau output pada *Serial Monitor* untuk memvalidasi interval eksekusi (clock buatan) yang dihasilkan oleh potensiometer.

| Posisi Potensiometer | Nilai Analog (0-1023) | Interval Waktu yang Diharapkan | Interval Aktual (via Serial Monitor) | Status |
| :--- | :--- | :--- | :--- | :--- |
| Putaran Penuh Kiri (Min) | 0 | 100 ms / tick | ... ms | [ ] |
| Putaran Tengah (Mid) | ~512 | ~1050 ms / tick | ... ms | [ ] |
| Putaran Penuh Kanan (Max)| 1023 | 2000 ms / tick | ... ms | [ ] |