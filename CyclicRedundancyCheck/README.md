### Cyclic Redundancy Check

Se introduce un șir de caractere binare și un polinom generator (cu coeficienți 0 și 1).

Se fac următoarele verificări: șirurile să fie binare și lungimea mesajului să fie mai mare decât numărul de coeficienți ai polinomului generator.

Se extinde mesajul cu un număr de 0-uri egal cu gradul polinomului introdus.

Se efectuează succesiv operații de XOR între mesajul extins și coeficienții polinomului, până când lungimea restului obținut este strict mai mică decât lungimea șirului de coeficienți. Se vor afișa rezultatele intermediare ale operației de XOR.

Se execută iarăși operația de sau exclusiv între mesajul extins și restul final obținut, dar poziționarea restului se va face sub finalul mesajului extins. Acest rezultat se va afișa.