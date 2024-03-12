[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?style=flat)](https://github.com/ellerbrock/open-source-badges/)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg?logo=github&color=%23F7DF1E)](https://opensource.org/licenses/MIT)
![GitHub last commit](https://img.shields.io/github/last-commit/devancakra/IoT-based-Soil-Moisture-Monitoring-System-using-HTTP-and-UART-communication-protocols)
![Project](https://img.shields.io/badge/Project-Internet%20of%20Things-light.svg?style=flat&logo=arduino&logoColor=white&color=%23F7DF1E)

# IoT-based-Soil-Moisture-Monitoring-System-using-HTTP-and-UART-communication-protocols
<strong>Proyek Tunggal: Sistem Pemantauan Kelembaban Tanah berbasis IoT menggunakan protokol komunikasi HTTP dan UART</strong><br><br>
Sistem IoT berbasis ESP-01 umumnya menggunakan perintah AT untuk dapat melakukan tindakan dalam suatu jaringan. Perintah AT ini diketahui ada banyak. Selain itu, kombinasi perintah yang ada sulit untuk dimengerti bagi seorang pemula. Oleh karena itu, proyek ini dibuat untuk meningkatkan kenyamanan pada sistem IoT berbasis ESP-01. Dalam hal ini, penulis menggunakan protokol UART di sisi papan pengembangan. Proyek ini telah dilaksanakan dan memakan waktu kurang lebih 2 minggu. Ada 2 jenis papan pengembangan yang dipakai. Arduino Uno R3 dipakai untuk mengambil data kelembaban tanah dari sensor yang kemudian dikirim ke ESP-01S melalui komunikasi UART: Software Serial. Sementara itu, ESP-01S digunakan untuk menerima data dari Arduino Uno melalui komunikasi UART: Hardware Serial dan kemudian mengirim data ke Ubidots melalui protokol HTTP.

<br><br>

## Kebutuhan Proyek
| Bagian | Deskripsi |
| --- | --- |
| Papan Pengembangan | • Arduino Uno R3<br>• ESP-01S |
| Editor Kode | Arduino IDE |
| Alat Pemrogram | USB CH340-ESP01 |
| Driver | USB-Serial CH340 |
| Platform IoT | Ubidots |
| Protokol Komunikasi | • Hypertext Transfer Protocol (HTTP)<br>• Universal Asynchronous Receiver-Transmitter (UART) |
| Arsitektur IoT | 3 Lapisan |
| Bahasa Pemrograman | C/C++ |
| Pustaka Arduino | • SoftwareSerial (default)<br>• Ubidots-ESP8266 |
| Sensor | Sensor Kelembaban Tanah Kapasitif (x1) |
| Komponen Lainnya | • Kabel USB tipe B - USB tipe A (x1)<br>• Kabel jumper (1 set)<br>• Adapter ESP-01 (x1) |

<br><br>

## Unduh & Instal
1. Arduino IDE

   <table><tr><td width="810">
         
   ```
   https://www.arduino.cc/en/software
   ```

   </td></tr></table><br>
   
2. USB-Serial CH340

   <table><tr><td width="810">
   
   ```
   https://bit.ly/CH340_Driver
   ```
   
   </td></tr></table>
   
<br><br>

## Rancangan Proyek
<table>
<tr>
<th width="420">Diagram Blok</th>
<th width="420">Infrastruktur</th>
</tr>
<tr>
<td><img src="https://github.com/devancakra/IoT-based-Soil-Moisture-Monitoring-System-using-HTTP-and-UART-communication-protocols/assets/54527592/36612e47-62b8-4eab-8232-b0616c47d8a6" alt="Block-Diagram"></td>
<td><img src="https://github.com/devancakra/IoT-based-Soil-Moisture-Monitoring-System-using-HTTP-and-UART-communication-protocols/assets/54527592/6327e020-3576-42ce-a801-83a1ed5ca29b" alt="Infrastructure"></td>
</tr>
</table>
<table>
<tr>
<th width="420">Diagram Ilustrasi</th>
<th width="420">Pengkabelan</th>
</tr>
<tr>
<td><img src="https://github.com/devancakra/IoT-based-Soil-Moisture-Monitoring-System-using-HTTP-and-UART-communication-protocols/assets/54527592/e0458ee4-b685-4296-b3fc-d4bb20823891" alt="Pictorial-Diagram"></td>
<td><img src="https://github.com/devancakra/IoT-based-Soil-Moisture-Monitoring-System-using-HTTP-and-UART-communication-protocols/assets/54527592/2ec91826-9f04-4548-9ac5-9db08d28738d" alt="Wiring"></td>
</tr>
</table>

<br><br>

## Pengetahuan Dasar
• <strong>Serial Komunikasi</strong>

Pada dasarnya, suatu perangkat itu dapat dikomunikasikan dengan perangkat lain baik secara nirkabel maupun dengan kabel. Komunikasi antar perangkat keras yang umum digunakan salah satunya adalah ``` Komunikasi Serial ```. Dapat diketahui bersama bahwa ``` Komunikasi Serial ``` ini ada tiga jenis, yaitu meliputi: ``` UART (Universal Asynchronous Receiver-Transmitter) ```, ``` SPI (Serial Peripheral Interface) ```, dan ``` I2C (Inter Integrated Circuit) ```. ``` Komunikasi Serial UART ``` memungkinkan setiap perangkat dapat bertindak sebagai ``` master ``` atau ``` slave ``` secara terbatas. ``` Master ``` adalah perangkat utama yang memiliki otoritas penuh atas kontrol Slave, sedangkan ``` Slave ``` adalah perangkat sekunder yang berada di bawah otoritas perangkat Master. Ada dua macam ``` Komunikasi Serial UART ```, yaitu ``` Hardware Serial ``` dan ``` Software Serial ```.  ``` Komunikasi Hardware Serial ``` dapat dilakukan dengan cara menghubungkan pin ``` TX ``` dan pin ``` RX ``` secara ``` menyilang ``` pada masing-masing papan pengembangan, misalnya: ``` RX-TX ```, kemudian ``` TX-RX ```. Pin ``` TX ``` yaitu untuk ``` mengirim data ```, sedangkan pin ``` RX ``` yaitu untuk ``` menerima data ```. ``` Komunikasi Software Serial ``` ini kurang lebih sama dengan ``` Komunikasi Hardware Serial ``` dalam segi pengkabelan, namun ada perbedaan dalam segi pengkodean. Dengan menggunakan ``` Software Serial ``` inilah anda dapat mengatasi masalah keterbatasan pin ``` RX ``` dan ``` TX ``` yang ada di papan pengembangan. Untuk berkomunikasi dengan ``` Software Serial ``` ini cukup mudah, yaitu dengan menggunakan ``` Pin Digital ``` tertentu sebagai ``` pengganti pin TX dan pin RX ```.<br><br>

• <strong>Internet of Things</strong>

Internet of Things (IoT) adalah sebuah konsep dimana suatu hal yang terhubung ke jaringan dapat melakukan satu tindakan atau lebih dalam mencapai suatu tujuan. Tindakan ini diantaranya berupa pengumpulan data, pengiriman data, penerimaan data, atau pengolahan data. Setiap proyek IoT pasti membutuhkan perangkat yang dapat terhubung ke WiFi seperti ESP. ESP terdiri dari 2 jenis, yaitu ESP8266 dan ESP32. Hal ini di pasaran sangat beragam sekali modelnya, untuk itu perlu sekali anda menyesuaikan kembali dengan kebutuhan yang ada di proyek agar tidak menimbulkan kekecewaan.

<br><br>

## Pengaturan Arduino IDE
1. Buka ``` Arduino IDE ``` terlebih dahulu, kemudian buka proyek dengan cara klik ``` File ``` -> ``` Open ``` :

   <table><tr><td width="810">
   
      • ``` Master.ino ```
      
      • ``` Slave.ino ```

   </td></tr></table><br>
   
2. Isi ``` Url Pengelola Papan Tambahan ``` di Arduino IDE

   <table><tr><td width="810">
      
      Klik ``` File ``` -> ``` Preferences ``` -> masukkan ``` Boards Manager Url ``` dengan menyalin tautan berikut :
   
      ```
      http://arduino.esp8266.com/stable/package_esp8266com_index.json
      ```

   </td></tr></table><br>
   
3. ``` Pengaturan Board ``` di Arduino IDE

   <table>
      <tr><th>
         
      i
         
      </th><th width="780">
            
      Cara mengatur board ``` Arduino Uno ```
   
      </th></tr>
      <tr><td colspan="2">

      Klik ``` Tools ``` -> ``` Board ``` -> ``` Arduino AVR Boards ``` -> ``` Arduino Uno ```
              
      </td></tr>
   </table><br><table>
      <tr><th>
         
      ii
         
      </th><th width="775">

      Cara mengatur board ``` ESP-01S ```
            
      </th></tr>
      <tr><td colspan="2">

      • Klik bagian ``` Tools ``` -> ``` Board ``` -> ``` Boards Manager ``` -> Instal ``` esp8266 ```.

      • Kemudian klik ``` Tools ``` -> ``` Board ``` -> ``` ESP8266 Boards ``` -> ``` Generic ESP8266 Module ```.
            
      </td></tr>
   </table><br>
   
4. ``` Ubah Kecepatan Papan ``` di Arduino IDE

   <table>
      <tr><th>
         
      i
         
      </th><th width="780">
            
      Cara mengubah kecepatan board ``` Arduino Uno ```
   
      </th></tr>
      <tr><td colspan="2">

      Klik ``` Tools ``` -> ``` Upload Speed ``` -> ``` 9600 ```
              
      </td></tr>
   </table><br><table>
      <tr><th>
         
      ii
         
      </th><th width="775">

      Cara mengubah kecepatan board ``` ESP-01S ```
            
      </th></tr>
      <tr><td colspan="2">

      Klik ``` Tools ``` -> ``` Upload Speed ``` -> ``` 9600 ```
            
      </td></tr>
   </table><br>
   
5. ``` Instal Pustaka ``` di Arduino IDE

   <table><tr><td width="810">
     
      Unduh semua file zip pustaka. Lalu tempelkan di: ``` C:\Users\Computer_Username\Documents\Arduino\libraries ```

   </td></tr></table><br>

6. ``` Pengaturan Port ``` di Arduino IDE

   <table><tr><td width="810">

      Klik ``` Port ``` -> pilih sesuai dengan port perangkat anda ``` (anda dapat melihatnya di Device Manager) ```
         
   </td></tr></table><br>

7. Ubah ``` Nama WiFi ```, ``` Kata Sandi WiFi ```, dan sebagainya sesuai dengan apa yang anda gunakan saat ini.<br><br>

8. Sebelum mengunggah program, silakan klik: ``` Verify ```.<br><br>

9. Jika tidak ada kesalahan dalam kode program, langkah selanjutnya yaitu menggunakan alat pemrograman ``` ESP-01 ``` sesuai dengan prosedur. Kemudian klik: ``` Upload ```. Sedangkan ``` Arduino Uno ``` dapat dilakukan secara langsung tanpa menggunakan alat pemrograman.<br><br>

10. Jika masih ada masalah saat unggah program, maka coba periksa pada bagian ``` driver ``` / ``` port ``` / ``` alat pemrogram ``` / ``` yang lainnya ```.

<br><br>

## Pengaturan USB CH340-ESP01
<img width="840" src="https://github.com/devancakra/IoT-based-Soil-Moisture-Monitoring-System-using-HTTP-and-UART-communication-protocols/assets/54527592/63c12ea2-d05d-4b60-b6ba-813597fe80af" alt="pinout"><br><br><br>

1. ``` Mode Pemrograman ``` :

   • Pasang ``` ESP-01 ``` ke ``` USB CH340-ESP01 ```.
   
   • Tekan dan tahan tombol yang ada di ``` USB CH340-ESP01 ```, lalu tancapkan pada komputer/laptop.
   
   • Lepaskan tombol ketika perangkat sudah dikenali oleh komputer/laptop.
   
   • Silakan ``` unggah program ```.<br><br>
   
2. ``` Mode Pengoperasian ``` :
   
   • Lepaskan ``` USB CH340-ESP01 ``` dari komputer/laptop.
   
   • Pasang ``` ESP-01 ``` ke ``` Adapter ESP-01 ```. Lakukan pengkabelan seperti yang ada pada diagram ilustrasi.
   
   • Kode program yang telah tertanam dalam ``` board ESP-01 ``` ini siap untuk dioperasikan (sudah tidak ada aktivitas pemrograman lagi).<br><br><br>

<strong>Catatan :</strong>

<table><tr><td width="840">

   • Untuk mengunggah program, selain menggunakan ``` USB CH340-ESP01 ```, anda juga dapat menggunakan alat pemrogram lainnya seperti: ``` USB CP2102 ```, ``` USB CH340 ```, ``` USB FTDI ```, atau dengan ``` USB PL2303 ```.

   • Berdasarkan pengalaman, saya akui bahwa penggunaan ``` USB CH340-ESP01 ``` ini jauh lebih baik daripada alat pemrogram lainnya karena tidak membutuhkan kabel untuk dapat terhubung ke komputer/laptop.

</td></tr></table><br><br>

## Pengaturan Ubidots
1. Memulai Ubidots : 

   <table><tr><td width="810">
   
      • Silakan <a href="https://industrial.ubidots.com/accounts/signin/">Masuk</a> agar dapat mengakses layanan ``` Ubidots ```.
      
      • Jika anda belum memiliki akun ``` Ubidots ``` silakan buat dulu.

   </td></tr></table><br>

2. Membuat devices : 

   <table><tr><td width="810">
   
      • Setelah masuk ke dalam akun -> klik ``` Devices ```.
   
      • Klik ``` + (Create a device) ``` -> lalu pilih ``` Blank Device ```.
   
      • ``` Device name ``` sesuaikan dengan kebutuhan anda.

      • ``` Device label ``` sesuaikan dengan apa yang ada di Ubidots sewaktu berhasil mengirim data pertama kali, dalam hal ini biasanya akan berbentuk ID.

      • Pilih ``` ✅ Checklist ``` untuk menyimpan.

   </td></tr></table><br>

3. Membuat dashboards : 

   <table><tr><td width="810">
   
      • Klik ``` Data ``` -> lalu pilih ``` Dashboards ```.
   
      • Klik ``` Add new Dashboard ```.
   
      • ``` Name ```, ``` Tags ```, ``` Default time range ``` -> sesuaikan dengan kebutuhan anda.

      • ``` Dynamic Dashboard ``` -> ubah menjadi ``` Dynamic (Single Device) ```.

      • ``` Default Device ``` -> pilih device yang ingin ditampilkan.

      • Pengaturan yang lain biarkan saja -> kemudian klik ``` SAVE ```.

   </td></tr></table><br>

4. Membuat widget : 

   <table><tr><td width="810">
   
      • Pastikan anda berada di menu ``` Dashboards ```.
   
      • Klik ``` + Add new widget ```.
   
      • Silakan pilih sesuai dengan kebutuhan anda. Kalau di proyek ini, penulis menggunakan ``` Line chart ``` untuk visualisasi datanya.
   
      • Silakan atur variabel yang ingin ditampilkan pada widget yaitu dengan cara klik ``` + Add Variables ```, kemudian klik ``` ✅ Checklist ``` untuk menyimpan.
   
      • Jika ingin mengubah isi widget, silakan klik simbol ``` pensil ``` -> jika sudah, kemudian klik ``` ✅ Checklist ``` untuk menyimpan.

   </td></tr></table><br>

5. Konfigurasi firmware : 

   <table><tr><td width="810">
   
      • Klik bagian ``` User ``` yang ada di pojok kanan atas -> lalu pilih ``` API Credentials ```.
   
      • Salin ``` Default token ``` -> lalu tempelkan pada kode firmware. Contohnya sebagai berikut:

      <table><tr><td width="780">
   
      ```ino
      const String token = "BBUS-aRZvtYRMM7IWbrKFcICR30YYP7dh5Q"; // define ubidots token
      ```

      </td></tr></table>

   </td></tr></table>

<br><br>

## Memulai
1. Unduh dan ekstrak repositori ini.<br><br>

2. Pastikan anda memiliki komponen elektronik yang diperlukan.<br><br>
   
3. Pastikan komponen anda telah dirancang sesuai dengan diagram.<br><br>
   
4. Konfigurasikan perangkat anda menurut pengaturan di atas.<br><br>
    
5. Selamat menikmati [Selesai].

<br><br>

## Sorotan
<table>
<tr>
<th width="420">Perangkat Keras</th>
<th width="420">Serial Monitor & Platform IoT: Ubidots</th>
</tr>
<tr>
<td><img src="https://github.com/devancakra/IoT-based-Soil-Moisture-Monitoring-System-using-HTTP-and-UART-communication-protocols/assets/54527592/41a13e11-7acd-4943-abb9-d551a63073f8" alt="hardware"></td>
<td><img src="https://github.com/devancakra/IoT-based-Soil-Moisture-Monitoring-System-using-HTTP-and-UART-communication-protocols/assets/54527592/998a5e4b-c96d-4a4e-863b-3f28d0f92023" alt="serialmonitor-iotplatform"></td>
</tr>
</table>

<br><br>

## Apresiasi
Jika anda merasa karya ini bermanfaat, dukunglah karya ini sebagai bentuk apresiasi kepada penulis dengan cara mengeklik tombol ``` ⭐Star ```.

<br><br>

## Penafian
Aplikasi ini dibuat dengan menyertakan sumber-sumber dari pihak ketiga. Pihak ketiga di sini adalah penyedia layanan, yang layanannya berupa pustaka, kerangka kerja, dan lain-lain. Saya ucapkan terima kasih banyak atas layanannya. Telah terbukti sangat membantu dan dapat diimplementasikan.

<br><br>

## LISENSI
LISENSI MIT - Hak Cipta © 2024 - Devan C. M. Wijaya, S.Kom

Dengan ini diberikan izin tanpa biaya kepada siapa pun yang mendapatkan salinan perangkat lunak ini dan file dokumentasi terkait perangkat lunak untuk menggunakannya tanpa batasan, termasuk namun tidak terbatas pada hak untuk menggunakan, menyalin, memodifikasi, menggabungkan, mempublikasikan, mendistribusikan, mensublisensikan, dan/atau menjual salinan Perangkat Lunak ini, dan mengizinkan orang yang menerima Perangkat Lunak ini untuk dilengkapi dengan persyaratan berikut:

Pemberitahuan hak cipta di atas dan pemberitahuan izin ini harus menyertai semua salinan atau bagian penting dari Perangkat Lunak.

DALAM HAL APAPUN, PENULIS ATAU PEMEGANG HAK CIPTA DI SINI TETAP MEMILIKI HAK KEPEMILIKAN PENUH. PERANGKAT LUNAK INI DISEDIAKAN SEBAGAIMANA ADANYA, TANPA JAMINAN APAPUN, BAIK TERSURAT MAUPUN TERSIRAT, OLEH KARENA ITU JIKA TERJADI KERUSAKAN, KEHILANGAN, ATAU LAINNYA YANG TIMBUL DARI PENGGUNAAN ATAU URUSAN LAIN DALAM PERANGKAT LUNAK INI, PENULIS ATAU PEMEGANG HAK CIPTA TIDAK BERTANGGUNG JAWAB, KARENA PENGGUNAAN PERANGKAT LUNAK INI TIDAK DIPAKSAKAN SAMA SEKALI, SEHINGGA RISIKO ADALAH MILIK ANDA SENDIRI.
