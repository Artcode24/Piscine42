#!/bin/bash

LIB_NAME="libft.a"

SRC_FILES="ft.c"

echo "Compilation des fichiers sources en objets..."
cc -Wall -Wextra -Werror -c $SRC_FILES

echo "Creation de la bibliotheque $LIB_NAME..."
ar rcs $LIB_NAME *.o

echo "Nettoyage des fichiers objets..."
rm -f *.o

echo "Bibliotheque creee avec succes."