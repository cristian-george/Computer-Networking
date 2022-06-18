### Two Dimensional Parity

Se introduce un șir format din litere și eventual spații. Șirul va fi transformat sub formă de caractere binare prin transformarea codurilor ASCII ale literelor/spațiilor introduse. Fiecare literă și fiecare spațiu va fi codificat în binar pe câte 7 poziții.

Mesajul transformat astfel va fi poziționat într-o matrice cu 7 coloane și număr de linii variabil (în funcție de lungimea mesajului introdus).
Se vor calcula biții de paritate pe fiecare linie și fiecare coloana astfel (pentru un număr par de 1 pe o linie/coloană atunci se va adăuga un 0 pe ultima coloană/linie, iar pentru un număr impar de 1 se va adăuga un 1). Bitul semnificativ este bitul din colțul dreapta-jos al matricei.

Se va simula coruperea mesajului prin generarea aleatoare a unei poziții a unui caracter binar al mesajului. În funcție de poziția generată, se va modifica bitul de pe acea poziție.

Destinația va reface calculul biților de paritate bidimensională și va identifica bitul corupt.

Destinația va afișa apoi poziția coruptă.
