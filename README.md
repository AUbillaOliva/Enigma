# Enigma
Encriptador de texto.

Tras establecer una configuración en el funcionamiento del programa, ingresas un texto y verás el resultado encriptado.
Cada espacio (' '), es reemplazado con una X.

# Formula
La formula para encriptar una letra, dependiendo de la posicion de los rotores es:
1. Obtener el número de la letra del rotor 1 (C) mediante la configuracion de este.

    Ejemplo:
    
    CONFIG: 24 - 1 - 3
    
    LETRA A ENCRIPTAR: H
    
    H = O
    
    O = 15
      
    Por lo tanto el numero del rotor 1 (C) mediante su configuracion es: 15.
    
    
2. Al obtener el valor del paso 1, sumarle a este el numero de configuración del rotor 2 (B).

    Ejemplo:
    
    CONFIG: 24 - 1 - 3
    
    VALOR OBTENIDO PASO 1: 15
    
    15 + 1 = 16
    
    
3. Al valor obtenido del paso 2, restale a este el numero de la configuración del rotor 1 (C).

    Ejemplo:
    
    CONFIG: 24 - 1 - 3
    
    VALOR OBTENIDO PASO 2: 16
    
    16 - 3 = 13
    
    
4. El valor obtenido de el paso 3, es la posicion del rotor 2 (B) en donde se encuentra su combinacion entre el rotor 1.


5. Repetir pasos anteriores para encontrar combinacion entre el rotor 2 y el rotor 3.


6. Tras tener la posicion del rotor 3, encontrar la letra encriptada en el alfabeto[pos].

# Texto Encriptrado:

### Ejemplo
Configuración: 
1 - 21 - 19

Texto ingresado: 
Hello World

Texto Encriptado:
HLZX QXUO AWK


