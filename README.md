# Tic Tac Toe 1.5
Tic-Tac-Toe 1.5 (juga dikenal sebagai noughts dan crosses) adalah permainan papan strategi untuk dua pemain. Pemain satu disimbolkan dengan ‘X’ dan Pemain dua atau komputer disimbolkan dengan  ‘O’. Kedua pemain bergiliran menandai kotak dalam papan 3×3, 5×5, atau 7×7. Pemain menandai kotak dengan menginputkan nomor yang terdapat di papan permainan. Pemain yang berhasil menempatkan tiga tanda berurutan pada mode 3×3, empat tanda berurutan pada mode permainan 5×5, atau lima tanda berurutan pada mode permainan 7×7 di baris horizontal, vertikal, atau diagonal terlebih dahulu akan memenangkan pertandingan. 

Game tic tac toe yang saya buat memiliki mode melawan komputer. Karakteristik komputer pada game yang saya buat berdasarkan teori Skala Prioritas. Skala prioritas merupakan penentuan urutan kebutuhan dari yang terpenting sampai dengan yang kurang penting. Algoritma prioritas memiliki konsep sesuai dengan namanya mendahulukan dan mengutamakan kondisi terpenting. Kondisi-kondisi pada teori ini di buat oleh saya sendiri berdasarkan pengalaman bermain. Kondisi tersebut dibedakan sesuai mode permainan.
Urutan skala prioritas kondisi pergerakan komputer adalah sebagai berikut: 

#  Mode_3x3     
1. Mengisi kotak kosong di samping dua tanda berurutan horizontal, vertikal, atau diagonal yang bertujuan menutup pergerakan lawan atau memenangkan permainan.

2. Strategi memenangkan permainan dengan kondisi titik tengah kosong   

3. Strategi memenangkan permainan dengan kondisi titik tengah sudah terisi

4. Mengisi kotak kosong yang belum terisi


- Pada tingkat kesulitan Easy, Komputer hanya menjalankan algoritma 4

- Pada tingkat kesulitan Medium, Komputer hanya menjalankan algoritma 1 dan 4

- Pada tingkat kesulitan Hard, Komputer menjalankan semua algoritma
  
# Mode_5x5   
1. Mengisi kotak kosong di samping tiga tanda berurutan horizontal, vertikal, atau diagonal yang bertujuan menutup pergerakan lawan atau memenangkan permainan.    

2. Strategi mengisi kotak kosong tengah yang diapit oleh dua tanda yang sama horizontal, vertikal, atau diagonal yang bertujuan menciptakan dan mencegah pergerakan mematikan. Pergerakan mematikan adalah pergerakan yang membuat lawan mengalami kekalahan.

3. Strategi mengisi kotak kosong di samping dua tanda berurutan horizontal, vertikal, atau diagonal yang terletak pada bagian tengah. Bagian tengah adalah sembilan kotak yang dikelilingi kotak lainnya tanpa ada sisi yang bersebelahan dengan sisi luar. Strategi ini bertujuan menciptakan dan mencegah pergerakan mematikan. 

4. Mengisi kotak kosong di samping dua tanda berurutan horizontal, vertikal, atau diagonal yang bertujuan menutup pergerakan lawan atau memenangkan permainan

5. Mengisi kotak kosong yang dianggap kotak penting

6. Mengisi kotak kosong yang belum terisi

- Pada tingkat kesulitan Easy, Komputer hanya menjalankan algoritma 1, 4, 5, dan 6

- Pada tingkat kesulitan Medium, Komputer hanya menjalankan algoritma 1, 2, 4, 5, 6

- Pada tingkat kesulitan Hard, Komputer menjalankan semua algoritma.

# Mode_7x7     
1. Mengisi kotak kosong di samping empat tanda berurutan horizontal, vertikal, atau diagonal yang bertujuan menutup pergerakan lawan atau memenangkan permainan

2. Strategi mengisi kotak kosong bagian tengah yang diapit tiga tanda dengan pola _X_XX_ atau _XX_X_ pada horizontal, vertikal, atau diagonal yang bertujuan menciptakan dan mencegah pergerakan mematikan    

3. Mengisi kotak kosong di samping tiga tanda berurutan horizontal, vertikal, atau diagonal yang bertujuan menutup pergerakan lawan atau memenangkan permainan    

4. Mengisi kotak kosong yang dianggap kotak penting

5. Mengisi kotak kosong di samping dua tanda berurutan horizontal, vertikal, atau diagonal yang bertujuan menutup pergerakan lawan atau memenangkan permainan 

6. Mengisi kotak kosong yang belum terisi

- Pada tingkat kesulitan Easy, Komputer hanya menjalankan algoritma 1, 4, 5, dan 6

- Pada tingkat kesulitan Medium, Komputer hanya menjalankan algoritma 1, 3, 4, 5, 6

- Pada tingkat kesulitan Hard, Komputer menjalankan semua algoritma.
