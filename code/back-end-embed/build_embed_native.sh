ocamlopt -output-obj -o embed_native.o embed_me1.ml embed_me2.ml
gcc -Wall -I `ocamlc -where` -L `ocamlc -where` -lasmrun -ltermcap -o final_out.native embed_native.o main.c
./final_out.native
