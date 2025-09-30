# Macchinetta del caffe'

Questo progetto simula il funzionamento di una macchietta del caffe'.

## Come buildare il progetto

Per buildare il progetto si eseguono questi comandi:
```bash
cmake -S . -B build
cmake --build build
./build/macchinetta
```

Questa serie di comandi crea una cartella build. Successivamente compila il progetto. Infine esegue il file .o. <br>
In caso di errore dopo il comando `cmake --build build` lanciare il comando `rm -rf build`.