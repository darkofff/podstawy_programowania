# CC to funkcja placeholder dla kompilatora. Ja mam mingw więc używam gcc
CC = gcc

# Najprawdopodobniej ma to dodać kody błędów 
CFLAGS = -Wall -g

# Zmienne co mają pomóc 
# Każdy plik jest najpierw kompilowacy z .c do .o
# .o to blik binarny ale jeszcze nie wykonywalny

# Można wykorzystywać zmienne zamiast nazw plików
#	LIBRARY = libmatrix.a
#	OBJECTS = matrix.o
#	MAIN = main


# start dla programu
all: main 

# z tego co rozumiem to tworzy ostateczy exec, łączy archiwum z programem
# -L. - informacja dla linkera, gdzie powinien szukać biblioteki, "." - oznacza obecny folder
# -lmatrix to nazwa biblioteki, której ma szukać linker. -lmatrix == libmatrix.a
# -o main to działa jak przy zwykłej kompilacji, bez tego plik byłby a.out albo a.exe(na windows)
main: main.o libmatrix.a
	${CC} ${CFLAGS} main.o -L. -lmatrix -o main


# właściwa biblioteka, nazwa musi zaczynać się od lib*
# libmatrix.a to biblioteka a zarazem target w nomenklaturze makefile, 
# a matrix.o to dependency(prerequisite), z którego zostanie stworzona biblioteka
# ar - tworzy, modyfikuje i wyciąga pliki z archiwum
# rsc - argumenty podane do ar, r-replace, c-create, s-index dodany do archiwum, który wspomaga linker (patrz 3 punkt kompilacji)
libmatrix.a: matrix.o
	ar rcs libmatrix.a matrix.o

# tworzy matrx.o z matrix.c
# matrix.h jest potrzebne bo to jest właśnie prerequisite. To znaczy, że musi być up to date.
# ma to sens bo jeśli pliki.h są łączlikiem między programem a biblioteką to muszą zawierać wszystkie te same deklaracje
matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c -o matrix.o

main.o: main.c matrix.h
	$(CC) $(CFLAGS) -c main.c -o main.o



# Proces który powinien się odbyć w Makefile
# 1. plik/i z funkcjami .c -> .o -> lib*.a
# 2. skompilować program.c i połączyć z lib*.a


# Makefile składa się z:
# 1. Target - pliki, które mają być stworzone / akcje do wykonania
# 2. Prerequisites (dependencies) - pliki, które muszą być załączone 
# 3. commands - czyli np. cc

# Jak działa kompilacja
# 1. Najpierw dodawane są biblioteki
# 2. Potem jest właściwa kompilacja z naszego na binarne z rozszerzeniem .o
# 3. 'Linker' łączy pliki obiektowe ( .o ) w jeden wykonywalny plik binarny
