# Mano hash funkcija
## Kodo pseudokodas
Mano kodas susideda iš 6 etapų:
1. Įvedama / iš failų nuskaitoma simbolių seka
2. Simbolių seka paverčiama į ASCII
3. Simbolių ASCII yra pridedami vienas prie kito ir sudauginami
4. Iš ASCII kodas paverčiamas į binarinį kodą
5. Hash funkcija - ciklas pakartojamas 5 kartus
   * Bitai apverčiami vienas su kitu
   * Tikrinama ar bitas yra 1 ir jis keičiamas į 1 ar 0
   * Tikrinama ar pirmas bitas yra toks pats kaip ir kodo antros dalies pirmas bitas
   * Blokai po 16 bitų yra apverčiami vieni su kitais
   * Tikrinama ar pirmas bitas yra toks pats kaip ir kodo antros dalies paskutinis bitas
6. Binarinis kodas paverčiamas hex kodu ir gaunamas hash
Taip pat pseudokodą galima peržiūrėti "Pseudokodas.png".

## Programos veikimas
Po programos paleidimo atsidaro meniu, kuriame bus duotas pasirinkimas:
1. Ivesti zodi arba simboli rankiniu budu.
2. Atidaryti failus, sudarytus tik is vieno simbolio.
3. Atidaryti programos sugeneruotus failus, kuriuose yra > 1000 simboliu.
4. Atidaryti du failus su 1000 simboliais, kurie tarpusavy skiriasi tik 1 simboliu.
5. Atidaryti tuscia faila 'tuscias.txt'.
6. Baigti darba.
   
Vartotojas galės padaryti pasirinkimą paspaudžius nurodytus skaičius.

## Eksperimentiniai tyrimai ir rezultatų analizė
### 1. Patikrinimas ar mano hash funkcija atitinka reikalavimams i-iii.
   * 1. Maišos funkcijos įėjimas gali būti bet kokio dydžio simbolių eilutė.
        
     #### Tyrimas
     
     Veiksmingiausias būdas patikrinti ar mano kodas veikia su bet kokio dydžio simbolių eilute - paleisti programą ir parašyti įvestis ranka / nuskaityti įvestis iš failų su skirtingais simbolių skaičiais.
     Turimi failai: _"simbolis_1.txt"_, _"simbolis_2.txt"_, _"simbolis_3.txt"_, _"tekstas_1000.txt"_, _"tekstas_1000_kitas.txt"_, _"tuscias.txt"_ ir yra du programos generuojami failai: _"sugeneruotas1.txt"_ ir     _"sugeneruotas2.txt"_.
      
     #### Rezultatas
     
     ![image](https://github.com/user-attachments/assets/547ff96a-0ffd-4e41-8ed4-e9a913a62d20)
     ![image](https://github.com/user-attachments/assets/2eedba46-41e0-46f0-9b4c-fb02e5a66154)
     ![image](https://github.com/user-attachments/assets/486c8474-044a-4e0f-a3f6-cdeb7b3725db) 
     ![image](https://github.com/user-attachments/assets/fd2491f7-44d4-4c88-a4d2-6fc38e2f037a)
     ![image](https://github.com/user-attachments/assets/9f1d20a6-7018-4602-aae7-1409b41d1c42)
     ![image](https://github.com/user-attachments/assets/f4caabc8-620b-4cd9-875a-9d322b1eb0d2)

      Iš šitų nuotraukų galima padaryti išvadą, kad nesvarbu kokio dydžio yra įėjimo eilute, funkcija veikia ir duoda rezultatą.

   * 2.	Maišos funkcijos išėjimas visuomet yra to paties, fiksuoto, dydžio rezultatas.

     #### Tyrimas

       Veiksmingiausias būdas patikrinti, kad išėjimas yra visuomet fiksuoto dydžio - tai paleisti programą ir parašyti įvestis ranka / nuskaityti įvestis iš failų su skirtingais simbolių skaičiais. Tai reikia tam, kad patikrinti, ar mano išėjimas nepriklauso nuo įėjimo dydžio.

     #### Rezultatas
     
     Remiantis aukščiau pateiktomis nuotraukomis, galima padaryti išvadą, kad mano išeiga visada yra tokio pačio dydžio, 64 bitų hex'as.
     
   * 3.	Maišos funkcija yra deterministinė - tam pačiam įvedimui išvedimas visuomet yra tas pats.
        
     #### Tyrimas
  
     Kad patikrinti ar mano maišos funkcija yra deterministinė, keletą kartų paleisių programą, ranka įrašysiu tą patį žodį "Laime" ir palyginsiu išeigas.
     
     #### Rezultatas
  ![image](https://github.com/user-attachments/assets/a8152450-b8a8-492f-8925-e243d856a640)
  
    1. Rezultatas: da803e22d9cb6a7ccde46deee3edc60490a4d4b9b3143adae29d8d3df16f874e
    2. Rezultatas: da803e22d9cb6a7ccde46deee3edc60490a4d4b9b3143adae29d8d3df16f874e
    3. Rezultatas: da803e22d9cb6a7ccde46deee3edc60490a4d4b9b3143adae29d8d3df16f874e
       
   Kadangi įeigai "Laime" visos 3 išeigos yra identiškos, tai galima padaryti išvadą, kad mano maišos funkcija yra deterministinė.
   
### 2. Patikrinimas ar mano hash'avimo funkcija atitinka 4-ą reikalavimą. 
   Tuo tikslu paėmiau 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 789 eilučių iš failo _"konstitucija.txt"_, suhashinau ir išmatavau kiek laiko visa tai užtruko.

   #### Rezultatai:

   | Eilučių kiekis | 1   | 2   | 4   | 8   | 16   | 32   | 64   | 128   | 256   | 512   | 789   |
   |----------------|-----|-----|-----|-----|------|------|------|-------|-------|-------|-------|
   | Laikas (ms)    |1.380|1.600|3.444|7.167|14.632|29.421|53.420|132.591|244.460|461.397|715.276|
   
  Taip pat rezultatus galima peržiūrėti "HashavimoLaikas.png".

  #### Išvada

  Tyrimo rezultatai parodo, kad mano hash funkcija veikia greitai ir efektyviai, nes 789 eilučių hash'avimas užtruko 0.715s. Tačiau reikia patobulinti mano funkciją tam, kad pasiekti geresnį efektyvumą. Tai reikalinga dėl to, kad tuo atveju, kai bus didesni failai, mano hash funkcija veiks lėčiau nei tikėtasi.

### 3. Patikrinimas ar mano hash'avimo funkcija atitinka 6-ą reikalavimą: ar mano funkcija yra atspari kolizijai.
  Tuo tikslu sukuriau dvi funkcijas: _randomSimboliuGeneravimas_ ir _failuKurimas_. Antroje funkcijoje yra sukuriamas 100000 eilučių failas su random simboliais. Kiekvienoje eilutėje yra 2 poros simbolių sekų. Yra 25000 porų, kurių ilgis 10 simbolių, 25 000 porų, kurių ilgis - 100, 25000 porų - 500, ir 25000 porų - 1000 simbolių. Tam, kad ištirti ar mano kodas yra atsparus kolizijai, lyginau kiekvienos eilutės poros hash'us.

      if (pirmasHash == antrasHash) {
      kolizijuSkaicius++; 
      }

  #### Rezultatas

  Paleidus programą, kiekvieną kartą kuriamas failas _"100000.txt"_ su naujomis poromis. Paleidžiau programą 5 kartus ir kiekvieną kartą gavau atsakymus "Koliziju skaicius: 0". Taigi mano maišos funkcija yra atspari kolizijai.
  
  ![image](https://github.com/user-attachments/assets/aa0e86e1-f049-4ef0-b534-b0cb64a85ff0)

  Šioje nuotraukoje galima pamatyti tiek rezultatą, tiek paskutinių porų hash'us, kas įrodo, kad jie tikrai skiriasi vienas nuo kito.

### 4. Mano gautų hash'ų procentinių "skirtingumų" įvertinimas
### 5. Išvados
