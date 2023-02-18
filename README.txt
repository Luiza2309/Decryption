TASK1:
Salvez cuvintele intr-un vector si verific cu ce litera incepe fiecare.
Cuvintele a: salvez pozitia elementului maxim si ma misc in matrice conform pozitiei.
Cuvintele b: parcurg cuvantul, ignorand litera, si formez k. Iau ultimele 2 caractere din cuvant pentru a forma x-ul. 
Verific daca k este palindrom, respectiv daca x este prim si ma misc in matrice conform valorilor.
ex: "12" => '1'-'0'=1 => k=0+1 => k=1*10 => '2'-'0'=2 => k=10+2 => k=12
Cuvintele c: parcurg cifrele x1x2...xn din k in k ori. 
Daca indicele a trecut de n, atunci se va lua restul impartirii indicelui la n (mod) si se va aduna la suma numarul respectiv indicelui nou obtinut.

TASK2:
Caesar: iau 3 cazuri- daca caracterul este numar, daca este litera mica sau daca este litera mare.
Dau inapoi cate caractere este posibil pana ajunge la '0', 'a' sau 'A' in functie de caz.
Verific daca mai trebuie sa dea inapoi si cate caractere.
Folosesc cheie%10, respectiv cheie%26 deoarece daca da inapoi 10 caractere (la cifre), respectiv 26 de caractere (la litere), 
acesta va ajunge inapoi de unde a plecat, lucru care nu ma intereseaza. Ma intereseaza doar cate caractere da inapoi si ii schimba pozitia.

Vigenere: asemanator cu Caesar, doar ca pentru fiecare caracter verific cate caractere trebuie sa dau inapoi (cheie_extinsa[i]-'A').

Addition: descifrez numerele.
In functie de diferenta de lungime dintre numere voi avea 3 cazuri: primul numar e mai lung, al doilea e mai lung sau sunt egale.
Parcurg de la coada la cap, iar daca cifrele adunate dau mai mare decat 10 voi salva pe pozitia actuala doar ultima cifra din suma, iar pe pozitia urmatoare voi adauga un 1.
 999+
 999
 ---
1998
9+9=8 si unu mai departe; 
9+9=8 si cu unu => 9 si unu mai departe;
9+9=8 si cu unu => 9
0+0=0 si cu unu => 1
=> 1998
Dupa efectuarea adunarii, sterg 0-urile de la finalul si inceputul sumei

TASK3:
Salvez tot textul intr-un string si sterg punctuatia. Iau cuvinte 2 cate 2 si le salvez in dictionar.
Parcurg dictionarul de doua ori in acelasi timp: o data de la inceput la sfarsit si o data de la inceput pana la pozitia ajunsa in primul for pentru a evita 
numararea de 2 ori a secventelor. Nu vreau sa imi adauge la repetari o secventa care a mai fost comparata anterior.
ex: The cat is nice, the dog is nice, the cow is nice.
Compara al doilea "is nice" cu primul, adauga la repetari si iese.
Compara al treilea "is nice" cu primul, adauga la repetari si iese.
Astfel, se evita compararea celui de-al treilea "is nice" cu al doiea, lucru care ar duce la incrementarea eronata a repetarilor.
