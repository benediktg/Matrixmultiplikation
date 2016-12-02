# Matrixmultiplikation
Forschungspraktikum BA, Parallele und Verteilte Systeme

Befehl zum Kompilieren:
```sh
bin/create_random_matrix.py 1024  # erstellt zwei 1024×1024-Matrizen
make -j4  # -j4 ist optional, ggf. noch -B, um garantiert zu rekompilieren und neue Matrizen zu erstellen
```
Anschließend kann man das Programm mit `./a.out` ausführen oder mit `./a.out 8` eine Terminierungsgröße angeben.
