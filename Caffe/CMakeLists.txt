cmake_minimum_required(VERSION 3.10)
project(MacchinettaCaffe C)

# aggiunge la cartella include agli header
include_directories(include)

# cerca tutti i file .c in src e sottocartelle
file(GLOB_RECURSE SOURCES "src/*.c")

# crea l'eseguibile
add_executable(macchinetta ${SOURCES})