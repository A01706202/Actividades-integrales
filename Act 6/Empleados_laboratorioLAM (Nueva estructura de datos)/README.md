**Shell Sort**
-----------------
Es una mejora del Insert Sort, donde se comparan los elementos separados por un espacio de varias posiciones, al tiempo que se los intercambian si corresponde. A medida que los pasos aumentan, disminuye el tamaño de los saltos. Así que es útil cuando los datos se encuentres cercanos o lejanos

Se utilizaría para acomodar listas de tamaño moderado, gracias a su velocidad aceptable y codificación sencilla.

Un ejemplo real sería cuando se tiene que acomodar los registros que contaron que tipo de auto pasó por una calle concurrida durante un día, en donde los datos son muy revueltos y con espacios de varias posiciones.


Análisis de complejidad
-----------------
Es O(n(log(n))^2), gracias a los saltos que da para intercambiar los elementos separados y por los ciclos for que realiza.


Bibliografía
-------
5.10. El ordenamiento de Shell — Solución de problemas con algoritmos y estructuras de datos. (2014). Runestone.Academy. https://runestone.academy/runestone/static/pythoned/SortSearch/ElOrdenamientoDeShell.html

Algoritmo de Ordenamiento Shell - EcuRed. (2020). Ecured.Cu. https://www.ecured.cu/Algoritmo_de_Ordenamiento_Shell

ShellSort - GeeksforGeeks. (2014, June 16). GeeksforGeeks. https://www.geeksforgeeks.org/shellsort/
