// ====================================================================
// PROYEK UAS ARSITEKTUR DAN SISTEM KOMPUTER - S1 KECERDASAN ARTIFISIAL UNESA
// Judul: 8-bit Binary Counter dengan Kontrol Kecepatan & Arah
// ====================================================================

// [ARSITEKTUR: I/O BUS & PERIPHERAL MAPPING]
// Mendefinisikan jalur pin fisik mikrokontroler yang terhubung ke perangkat luar.
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // Jalur Bus Data Output: Bit 0 (LSB) ke Bit 7 (MSB)
const int pinReset = 10;                        // Jalur Input Control Bus: Tombol Reset
const int pinUpDown = 11;                       // Jalur Input Control Bus: Tombol Arah (Up/Down)
const int pinPot = A0;                          // Jalur Input Analog: Potensiometer (Clock/Speed Control)

// [ARSITEKTUR: REGISTER 8-BIT]
// Variabel 'counterRegister' bertindak sebagai General Purpose Register 8-bit di dalam CPU.
// Tipe data uint8_t mengalokasikan tepat 8-bit memori (nilai 0 - 255).
uint8_t counterRegister = 0; 

// Register internal tambahan untuk menyimpan status kendali sistem
bool isUpDirection = true;
unsigned long lastTickTime = 0;

void setup() {
  // [ARSITEKTUR: CONTROL UNIT - INITIALIZATION]
  // Control Unit mengonfigurasi arah aliran data pada pin I/O
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT); // Mengatur 8 pin LED sebagai output paralel
  }
  
  // Mengonfigurasi tombol input dengan resistor internal pull-up
  pinMode(pinReset, INPUT_PULLUP);  
  pinMode(pinUpDown, INPUT_PULLUP); 
  
  // Mengaktifkan serial monitor untuk simulasi data benchmark/output terukur
  Serial.begin(9600); 
}

void loop() {
  // [ARSITEKTUR: CONTROL UNIT - FETCH & DECODE LOGIC]
  // Control Unit membaca sinyal instruksi dari input eksternal dan mengambil keputusan.
  
  // 1. Logika Interupsi / Reset: Jika tombol reset ditekan (Sinyal LOW)
  if (digitalRead(pinReset) == LOW) {
    // Control Unit memaksa Register untuk dikosongkan (Clear) menjadi 0
    counterRegister = 0; 
    updateLEDOutputs();
    delay(200); // Debounce delay untuk stabilitas tombol
    return;
  }

  // 2. Logika Kendali Arah: Jika tombol Up/Down ditekan
  if (digitalRead(pinUpDown) == LOW) {
    isUpDirection = !isUpDirection; // Mengubah flag arah operasi di Control Unit
    delay(200); // Debounce delay
  }

  // 3. Logika Generator Clock (Speed Control): Membaca nilai Potensiometer
  int potValue = analogRead(pinPot);
  // Mengonversi nilai analog (0-1023) menjadi interval waktu delay (100ms - 2000ms)
  unsigned long tickInterval = map(potValue, 0, 1023, 100, 2000);

  // [ARSITEKTUR: CONTROL UNIT & ALU EXECUTION]
  // Mengatur waktu eksekusi berdasarkan interval clock buatan (tickInterval)
  unsigned long currentMillis = millis();
  if (currentMillis - lastTickTime >= tickInterval) {
    lastTickTime = currentMillis;

    // Control Unit memerintahkan ALU untuk melakukan operasi aritmatika
    if (isUpDirection) {
      // ALU mengeksekusi operasi INCREMENT (+1)
      // Jika register bernilai 255, operasi +1 otomatis meluap (overflow) kembali ke 0
      counterRegister++; 
    } else {
      // ALU mengeksekusi operasi DECREMENT (-1)
      // Jika register bernilai 0, operasi -1 otomatis underflow kembali ke 255
      counterRegister--; 
    }

    // Mengirimkan hasil komputasi ALU dari Register ke Modul I/O
    updateLEDOutputs();
    
    // Output data valid untuk kebutuhan analisis/benchmark di video presentasi
    Serial.print("Register Value: ");
    Serial.print(counterRegister);
    Serial.print(" | Direction: ");
    Serial.print(isUpDirection ? "UP" : "DOWN");
    Serial.print(" | Tick Interval: ");
    Serial.print(tickInterval);
    Serial.println(" ms");
  }
}

// [ARSITEKTUR: I/O INTERFACE - DATA BUS DISTRIBUTOR]
// Fungsi ini bertindak sebagai decoder/antarmuka yang mendistribusikan data 8-bit
// dari register internal menuju pin output fisik secara paralel.
void updateLEDOutputs() {
  for (int i = 0; i < 8; i++) {
    // Memisahkan bit ke-i menggunakan operasi logika shift-right (>>) dan masking bitwise AND (& 1)
    int bitValue = (counterRegister >> i) & 1;
    // Mengirimkan sinyal digital (HIGH/LOW) ke komponen hardware LED
    digitalWrite(ledPins[i], bitValue);
  }
}