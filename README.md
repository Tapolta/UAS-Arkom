# Proyek UAS: 8-bit Binary Counter dengan Display

Repositori ini berisi kode sumber, dokumen arsitektur, dan data pengujian untuk proyek Ujian Akhir Semester (UAS) mata kuliah **Arsitektur dan Sistem Komputer**.

**Program Studi:** S1 Kecerdasan Artifisial  
**Universitas:** Universitas Negeri Surabaya (UNESA)  

### Anggota Kelompok:
1. Gustavolta Khizqi Ismail - 25032014025
2. Muhammad Fajar Novyanto Ramdhani - 25032014084
3. Angga Farel Kusuma - 25032014017

---

## Deskripsi Proyek
Proyek ini adalah simulasi *Embedded System* berbasis mikrokontroler Arduino Uno yang mengimplementasikan konsep **Digital Logic Design**. Sistem ini berfungsi sebagai *8-bit Binary Counter* yang menghitung nilai desimal dari 0 hingga 255 dan merepresentasikannya ke dalam bentuk biner melalui 8 buah LED *bar display*.

Proyek ini dirancang untuk mendemonstrasikan pemahaman dasar mengenai arsitektur komputer, meliputi:
* **Register 8-bit:** Penyimpanan nilai counter saat ini.
* **Arithmetic Logic Unit (ALU):** Melakukan operasi *Increment* (+1) dan *Decrement* (-1).
* **Control Unit:** Mengatur logika arah (Up/Down), *interrupt* (Reset), dan frekuensi *clock/timing*.
* **I/O Bus:** Mendistribusikan data ke periferal *output* (LED) dan menerima *input* dari periferal (Tombol & Potensiometer).

## Fitur Sistem
* **Auto-Counting:** Menghitung otomatis nilai 8-bit (0-255). Mengalami *overflow* dan *underflow* secara natural.
* **Visual Display:** Output biner ditampilkan secara *real-time* melalui 8 LED merah.
* **Tombol Reset:** Memberikan interupsi untuk segera membersihkan register (kembali ke 0).
* **Tombol Up/Down:** Mengubah arah operasi ALU dari *Increment* menjadi *Decrement*, dan sebaliknya.
* **Kontrol Kecepatan:** Potensiometer digunakan untuk mengatur kecepatan *clock* (interval *delay*) antara 100 ms hingga 2000 ms.

---

## Cara Menjalankan Simulasi (Wokwi)

Karena proyek ini disimulasikan menggunakan [Wokwi](https://wokwi.com/), tidak perlu menginstal perangkat lunak fisik apa pun (Arduino IDE tidak diwajibkan). Buka [Wokwi Kami](https://wokwi.com/projects/466191797786914817) atau Ikuti langkah-langkah berikut:

1.  Buka platform Wokwi di browser.
2.  Buat *project* Arduino Uno baru.
3.  Salin seluruh kode dari file `src/sketch.ino` di repositori ini dan tempelkan ke editor kode Wokwi (`sketch.ino`).
4.  Buka tab `diagram.json` di Wokwi, salin seluruh isi file `src/diagram.json` dari repositori ini, dan tempelkan untuk memuat tata letak komponen.
5.  Klik tombol **"Play"** (Start the simulation) di pojok kanan atas area kode.
6.  **Cara interaksi:**
    * Klik tombol **RESET (MERAH)** untuk mengembalikan LED ke posisi mati (0).
    * Klik tombol **UP / DOWN (HIJAU)** untuk membalikkan arah *counting*.
    * Klik dan putar tuas **POTENSIOMETER** untuk mempercepat atau memperlambat kedipan LED.
    * Buka **Serial Monitor** di bagian bawah Wokwi untuk melihat data operasional yang dikirimkan oleh Control Unit (Nilai Register, Arah, dan *Tick Interval*).

---

## Struktur Repositori
* `src/` — Berisi kode sumber Arduino (`.ino`) dan konfigurasi komponen Wokwi (`diagram.json`).
* `docs/` — Berisi laporan singkat arsitektur sistem, diagram blok, dan *flowchart*.
* `test/` — Berisi data hasil pengujian fungsionalitas dan pengukuran *timing* sistem.

---

## Video Presentasi & Demo
Silakan tonton video presentasi kelompok kami yang menjelaskan secara detail mengenai cara kerja kode, demonstrasi sistem secara *end-to-end*, dan evaluasi arsitektur melalui tautan berikut:

**Link YouTube:** [Klik Disini](https://www.youtube.com/watch?v=6D9feE5vEM8)