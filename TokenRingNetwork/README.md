### Token Ring Network

Să se simuleze activitatea unei rețele Token Ring formată din 10 calculatoare.

Transmiterea de mesaje într-o astfel de rețea presupune existența unui unic jeton care se deplasează pe mediul de comunicație din calculator în calculator, într-un singur sens. 

Jetonul este caracterizat prin: adresa IP a calculatorului sursă, adresa IP a calculatorului destinație, mesaj, un câmp care sa indice daca jetonul este liber sau ocupat, un câmp care să indice dacă jetonul a ajuns la destinație sau nu. 

Calculatorul va avea un buffer și o adresă IP, ambele de tip string. Sursa și destinația se vor identifica pe baza adresei IP și se vor genera aleator. Adresa IP este formată din 4 numere cuprinse între 0 si 255, separate prin „.” și care identifică în mod unic calculatoarele din rețea
(Ex. de adresa IP: 192.168.10.25).

Orice calculator poate încerca la un moment dat, în mod concurent, să preia jetonul pentru a-l încărca și a-l trimite la un calculator destinație. Jetonul poate fi preluat doar în cazul în care este liber. Dacă jetonul este ocupat, atunci calculatorul care îl solicită va trebui să mai aștepte un timp până să verifice din nou dacă jetonul este liber sau nu. 

În cazul în care jetonul este preluat de către un calculator și încărcat cu mesaj, acesta se va deplasa din calculator în calculator, până când va ajunge la destinație; cu alte cuvinte, fiecare calculator verifică dacă propria adresă IP este aceeași cu adresa IP de destinație din jeton.

Destinația care preia jetonul va copia mesajul în propriul buffer și va schimba proprietatea jetonului care spune că mesajul a ajuns la destinație și apoi îl va lăsa sa meargă mai departe până ajunge înapoi la sursă. Sursa este cea care golește câmpurile jetonului și îl setează ca fiind liber.

După ce jetonul a fost setat ca fiind liber, poate fi preluat de oricare calculator din rețea, deplasându-se tot din calculator în calculator până la noua sursă.

Simularea va avea un număr fixat de pași sau poate fi lăsată să cicleze la infinit, iar calculatoarele sursă și destinație se vor genera în mod aleator la fiecare pas. (Atenție! Verificați ca sursa și destinația să nu fie același calculator.)

La fiecare pas al simulării, se va afișa fiecare calculator prin care circulă jetonul, iar la calculatorul destinație se va afișa și bufferul cu mesajul preluat din jeton.

Mesajul transmis poate fi citit la fiecare pas al simulării, poate fi declarat în program sau se poate citi dintr-un fișier cu mesaje text.
