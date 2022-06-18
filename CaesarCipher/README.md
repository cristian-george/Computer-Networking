### CaesarCipher

Să se realizeze o aplicaţie care are ca punct de pornire un exemplu din criptografia convenţională, şi anume "Cifrul lui Caesar".
Aplicaţia trebuie să cripteze şi să decripteze cuvinte cu ajutorul acestei metode.
Cheia folosită pentru criptare va fi generată cu ajutorul algoritmului Diffie-Hellman.
Cifrul lui Caesar va cripta doar literele, celelalte caractere din mesaj fiind ignorate.
Criptarea constă în transformarea unei litere în litera care se găseşte cu K poziţii mai la dreapta în alfabet (K fiind cheia).
Decriptarea constă în transformarea unei litere în litera care se găseşte cu K poziţii mai la stânga în alfabet.

Astfel, clientul citeşte un mesaj de la tastatură, îl criptează cu Cifrul lui Caesar, unde cheia este generată cu ajutorul algoritmului Diffie-Hellman, iar apoi îl transmite serverului.
Serverul va afişa atât mesaj criptat, cât şi pe cel decriptat.
Clientul închide conexiunea cu serverul atunci când trimite mesajul "close", iar serverul închiele conexiunea cu clientul atunci când primeşte "close".

Numărul prim p şi rădăcina primitivă a vor fi citite de către client, validate şi apoi trimise către server. Pentru generarea cheii se vor transmite la server valorile p şi a validate de client, după care se vor transmite valorile calculate ale lui YA, respectiv YB, între aplicaţia client şi aplicaţia server.
