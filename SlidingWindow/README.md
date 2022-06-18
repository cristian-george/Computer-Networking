### Sliding Window Protocol

Avem două calculatoare care trebuie să comunice între ele:
S - calculatorul sursă (va fi un fir de execuție)
D - calculatorul destinație (va fi alt fir de execuție)

Sursa va avea de trimis un șir de caractere către destinație. Va trimite succesiv, din acest șir, subșiruri de lungime specificată de către calculatorul destinație în variabila f.

Destinația va genera aleator valoarea lui f. Sursa nu va face modificări asupra lui f.

În cazul în care se generează o fereastră nulă (f=0), sursa nu răspunde cu mesaj, ci așteaptă până când primește un mesaj cu f nenul de la destinație. Destinația generează o nouă valoare pentru f după ce "doarme" un interval de timp.

La final, când se trimite ultima secvență de caractere, sursa va seta bit-ul FIN pe 1 și se va încheia conexiunea.

La fiecare pas al comunicării, aplicația trebuie să afișeze mesajul trimis de fiecare calculator (similar cu ceea ce se observă în imaginea atașată).
Sursa va afișa și subșirul pe care îl trimite de fiecare dată.

Destinația va afișa la final mesajul complet pe care l-a primit.
