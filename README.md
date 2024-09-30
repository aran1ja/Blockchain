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
  **Čia yra klaidų. Žiūrėti gerus skaičiavimus žemiau.**

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
  Reikia ištirti ar mano maišos funkcija turi lavinos efektą. Tai reiškia, kad bent minimalus pakeitimas mano įvestyje, turi duoti išvestis, kurios labai skirsis viena nuo kitos. Kadangi man nepavyko įgyvendinti kodo, kuris tirtų skirtingas įvestis ir skaičiuotų procentinį "skirtingumą" bitų lygmenyje ir hex'ų lygmenyje, išvestų minimalią, maksimalią ir vidurkines "skirtingumo" reikšmes, nusprendžiau padaryti tai įvedama žodžius ranka. Poros, kurias tikrinsiu:

      Laime laime
      Adriana adriana
      labaslabaslabaslabaslabas !abaslabaslabaslabaslabas
      6d46eS464S64d5s6 6d46eS474S64d5s6 
      bambambambim bambimbambim 
      lalalalalalalalalalalalalalalalalala aalalalalalalalalalalalalalalalalala

  #### Rezultatai

      Laime
      0111001011100001111101101000111110111100101100011011100101000111010110110101110000101000110011011001110100101011001001010000100100100000011000111011011111000111011101111011011000100111101100110011111001010110110100111001101101000100011111000000000101011011
      da803e22d9cb6a7ccde46deee3edc60490a4d4b9b3143adae29d8d3df16f874e
      
      laime
      0010110110011000110011101101111101010100000001100100010111010000101000101111101011000101011001101111110111010010110100001101001001000111110111000100100010100101111111111100101010111100011001000001101000110110111111111100110001100000100110101110001100100011
      c4c7590633ff6c58263d53ffa5123be24b0b4bbf66a35f450ba2602afb7319b4
      
      Adriana
      1000110110001110001000101000100000010000000100001101110111100101101100001011011110000101100100010001111011100011101011011100001101110111101001110000001010001001101100011010011001010111001001010111110100100001101100001001100001010100110000110011000100101000
      148cc32a190d84bea4ea658d9140e5eec3b5c77889a1ed0da7bb0808114471b1
      
      adriana
      1101110010011011101110110111111011101111010011100110001001110001101110111110010111010101100100100110011011011010000010011010010010111110110101011110110000010111011010000110100101110011001100101110101000110111110011000111110100011001111011100111010101010100
      2aae7798be33ec574cce9616e837ab7d25905b6649aba7dd8e4672f77eddd93b
      
      labaslabaslabaslabaslabas
      1000110100100010110011001011111010001111011100101001011011111000100101011101111101110111100111000010001111100101100101011000011010100101100011001111100010011011010000001100000001011010000010010001100101010111111110010100111110110110000001110001010010000001
      8128e06df29fea98905a0302d91f31a561a9a7c439eefba91f694ef17d3344b1
      
      !abaslabaslabaslabaslabas
      0111101001001001100101101101011111010110110000010000111010110010001111111101011101110111101011011110111110100001110011000001010000001010010110101000100011001010000101011010011100000001101111110111100111101100100100000100001111101100000111001100011110101011
      d5e33837c209379efd80e5a853115a50283385f7b5eeebfc4d70836beb69925e
      
      6d46eS464S64d5s6
      1100100001110100110110010111101000010000111100000111011001110110010001110000010110110101011001111001100100010001101001010000000110100100101010100100011010101101111111001010111111101111100101111110100011100100011000110010101011110110100010011100010001001110
      7223916f54c62717e9f7f53fb562552580a58899e6ada0e26e6e0f085e9b2e13
      
      6d46eS474S64d5s6
      0001001010101010111011111011100001101100101011111101010000010100011100011110011111010111000010011010001110111001111110000011001100010010000000001001010000001111111111011011111101110010110001100001001011101001011101000000011001000000101110100100001110001000
      11c25d02602e9748634efdbff0290048cc1f9dc590ebe78e282bf5361df75548
      
      bambambambim
      0101100001011000101101010000111010010100001011000110000110010000001101000111001000001101010111101110001010101001000010000111011000011111001111110001100111100100000000010001111100101110111111110110010010100100010010010100110101000110011111010010100101110001
      8e94be62b2922526ff74f8802798fcf86e1095477ab04e2c0986342970ad1a1a
      
      bambimbambim
      1111111110011001010001111011010000011111101011101010111010001100101001001010000001100011000001011111101101010011011010111000000000111111011010100101101101010000110010111011010100001010011000110000011111000000011111101010101010010010111010010011100010011010
      591c9749557e03e0c650add30ada56fc01d6cadfa0c60525317575f82de299ff
      
      lalalalalalalalalalalalalalalalalala
      0010100100110000111011000110011110100010010011100101100101100000100011011110001010001011110001010011011011011100001001101011110000100000010110011101100000101101010111001010101110100100000110011100001111111000111100011000100101101100100101101001011101011100
      3ae96936918f1fc39825d53ab41b9a043d643b6ca3d147b1069a7245e6370c94
      
      aalalalalalalalalalalalalalalalalala
      0010111001111111111001001111000101011100101000010110001111100111110100111101011111000100001010100110001000111010010111010011010000100111101110101111010010010101000101000010000011110101110100101011100010101000110010011011011001100110101100101000100010000101
      a1114d666d93151d4baf0428a92f5de42cba5c465423ebcbe7c6853a8f27fe74

| Min hex skirtumas  | Max hex skirtumas  | Vid hex skirtumas  | Min bit skirtumas  | Max bit skirtumas  | Vid bit skirtumas  |
|--------------------|--------------------|--------------------|--------------------|--------------------|--------------------|
| 3.125%             | 9.375%             | 5.469%             | 42.969%            | 51.953%            | 49.023%            |
  
Pagal gautus rezultatus galima padaryti išvadą, kad mano maišos funkcija turi gerą lavinos efektą. Tačiau reikia atsižvelgti į tai, kad dėl žmogiškaus faktorio, skaičiavimuose gali būti klaidų. Ir labai didelė tikimybė, kad patikrinus 100000 eilučių porų, rezultatai labai skirsis nuo pateiktųjų.

### 5. Išvados
Mano hash funkcija atitinka visiems reikalavimams. Tačiau ji galėtų veikti daug greičiau. Ir reikėtų sukurti programą, kuri geriau patikrintų lavinos efektą. Taip pastebjau, kad įrašant ranka simbolius, pvz "A" ir nuskaitant tą patį simbolį, gaunu skirtingus hex'us.

# Mano hash funkcija - patobulinimas
## Kodo pseudokodas
Kodo pseudokodas nelabai pasikeitė dėl tam tikrų priežasčių, kurias nurodysių žemiau. Pasikeitimus pažymėsiu **bold**:

Mano kodas susideda iš 6 etapų:
1. Įvedama / iš failų nuskaitoma simbolių seka
2. Simbolių seka paverčiama į ASCII
3. Simbolių ASCII yra pridedami vienas prie kito ir sudauginami
4. Iš ASCII kodas paverčiamas į binarinį kodą
5. Hash funkcija - ciklas pakartojamas **3 kartus**
   * Bitai apverčiami vienas su kitu
   * Tikrinama ar bitas yra 1 ir jis keičiamas į 1 ar 0 - **naudojama flip() funkcija**
   * Tikrinama ar pirmas bitas yra toks pats kaip ir kodo antros dalies pirmas bitas
   * Blokai po 16 bitų yra apverčiami vieni su kitais
   * Tikrinama ar pirmas bitas yra toks pats kaip ir kodo antros dalies paskutinis bitas
6. Binarinis kodas paverčiamas hex kodu ir gaunamas hash
   
Pseudokodą galima peržiūrėti "Pseudokodas2.png".

## Eksperimentiniai tyrimai ir rezultatų analizė
Kadangi buvo nors ir minimalūs kodo pakeitimai, tačiau reikėtų vėl patikrinti, ar maišos funkcija atitinka visiems reikalavimams. Tam, kad tyrimai būtų padaryti teisingai, pakartoju visą tai, ką dariau aukščiau, tad visi tyrimų aprašymai pateikti viršuje. Čia pateiksiu naujus rezultatus.

### 1. Patikrinimas ar mano hash funkcija atitinka reikalavimams i-iii.
   * 1. Maišos funkcijos įėjimas gali būti bet kokio dydžio simbolių eilutė.
      
     #### Rezultatas
     
     ![image](https://github.com/user-attachments/assets/4e90e486-a7d7-43ed-a642-20778d906e18)
     ![image](https://github.com/user-attachments/assets/a52d1085-a714-41fb-b69d-9fd411432434)
     ![image](https://github.com/user-attachments/assets/8896624d-3016-4fb4-a71f-c6291c3b6f75)
     ![image](https://github.com/user-attachments/assets/2e2bab28-78a3-400b-ad00-18ea38f3d379)

      Iš šitų nuotraukų galima padaryti išvadą, kad 1 reikalavimas neišnyko po kodo pakeitimo.

   * 2.	Maišos funkcijos išėjimas visuomet yra to paties, fiksuoto, dydžio rezultatas.

     #### Rezultatas
     
     Remiantis i punkte pateiktomis nuotraukomis, galima padaryti išvadą, kad mano išeiga visada yra tokio pačio dydžio, 64 bitų hex'as.
     
   * 3.	Maišos funkcija yra deterministinė - tam pačiam įvedimui išvedimas visuomet yra tas pats.
     
     #### Rezultatas
     
    Anksetesnis rezultatas: da803e22d9cb6a7ccde46deee3edc60490a4d4b9b3143adae29d8d3df16f874e
    Dabartinis rezultatas:
    1. Rezultatas: 893db9500c2938ca9e274e6151c62fdeb6349238aff1adf35d103cacba1e959f
    2. Rezultatas: 893db9500c2938ca9e274e6151c62fdeb6349238aff1adf35d103cacba1e959f
    3. Rezultatas: 893db9500c2938ca9e274e6151c62fdeb6349238aff1adf35d103cacba1e959f
       
   Kadangi įeigai "Laime" visos 3 išeigos yra identiškos, tai reiškia, kad mano maišos funkcija yra deterministinė. Pastebime, kad ankstesnis hash ir dabartinis labai skiriasi vienas nuo kito.
   
### 2. Patikrinimas ar mano hash'avimo funkcija atitinka 4-ą reikalavimą. 
   Tuo tikslu paėmiau 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 789 eilučių iš failo _"konstitucija.txt"_, suhashinau ir išmatavau kiek laiko visa tai užtruko.
   **Svarbu! Praeitą kartą buvo padarytą klaida** - mano hash funkcijoje numatyta, kad reikia išvesti visas hex reikšmes į ekraną, todėl gavosi rezultatai su tokiais dideliais laikais. Todėl perdarysiu savo eksperimentą ir parašysiu rezultatus kodo v0.1 versijos ir truputį pamodifikuoto. Taip pat yra pataisyta klaida - praeitą kartą, kai buvo paleidžiama hashFunkcija, pirmas hashas skyrėsi nuo kitų. Dabar jau neskiriasi. Taigi skaičiuosiu v0.1 taip, kaip turi būti - kur hex yra identiški visais atvėjais toms pačioms eilutėms.

   #### Rezultatai:
   v0.1 versijos skaičiavimai:

   | Eilučių kiekis | 1   | 2   | 4   | 8   | 16  | 32  | 64   | 128  | 256  | 512   | 789   |
   |----------------|-----|-----|-----|-----|-----|-----|------|------|------|-------|-------|
   | Laikas (ms)    |0.216|0.403|0.602|1.408|3.400|6.016|11.799|27.185|52.213|100.156|152.616|
   
   v0.2 versijos skaičiavimai:
   
   | Eilučių kiekis | 1   | 2   | 4   | 8   | 16  | 32  | 64  | 128  | 256  | 512  | 789  |
   |----------------|-----|-----|-----|-----|-----|-----|-----|------|------|------|------|
   | Laikas (ms)    |0.199|0.201|0.401|0.808|2.001|3.600|7.600|16.012|29.217|55.970|89.002|

   Kaip matosi iš šitų lentelių, skirtumas yra - daug kur skaičiai skiriasi apie 40-45% tarpusavy, tačiau jeigu būtų hashuojami didesni failai, tai skirtumas dar labiau būtų jaučiamas. Dabartinis rezultatas mane labiau tenkina, nes 789 eilučių suhashuojama per 0.089s kas yra greitai.
   
  Taip pat rezultatus galima peržiūrėti "HashavimoLaikas2.png".

  #### Išvada

  Tyrimo rezultatai parodo, kad mano hash funkcija dabar veikia dar greičiau ir efektyviau nors pakeitimai buvo minimalūs.

### 3. Patikrinimas ar mano hash'avimo funkcija atitinka 6-ą reikalavimą: ar mano funkcija yra atspari kolizijai.
  
  #### Rezultatas
  ![image](https://github.com/user-attachments/assets/b8a52700-542a-48be-979d-5ab7a90229b2)

Iš to seka, kad mano maišos funkcija yra atspari kolizijai. Čia matomi paskutinių porų hash'ai, kas įrodo, kad jie tikrai skiriasi vienas nuo kito.

### 4. Mano gautų hash'ų procentinių "skirtingumų" įvertinimas
  Reikia ištirti ar mano maišos funkcija turi lavinos efektą. Tai reiškia, kad bent minimalus pakeitimas mano įvestyje, turi duoti išvestis, kurios labai skirsis viena nuo kitos. Kadangi man nepavyko įgyvendinti kodo, kuris tirtų skirtingas įvestis ir skaičiuotų procentinį "skirtingumą" bitų lygmenyje ir hex'ų lygmenyje, išvestų minimalią, maksimalią ir vidurkines "skirtingumo" reikšmes, nusprendžiau padaryti tai įvedama žodžius ranka. Poros, kurias tikrinsiu:

   

  #### Rezultatai

      

| Min hex skirtumas  | Max hex skirtumas  | Vid hex skirtumas  | Min bit skirtumas  | Max bit skirtumas  | Vid bit skirtumas  |
|--------------------|--------------------|--------------------|--------------------|--------------------|--------------------|
| 3.125%             | 9.375%             | 5.469%             | 42.969%            | 51.953%            | 49.023%            |
  
Pagal gautus rezultatus galima padaryti išvadą, kad mano maišos funkcija turi gerą lavinos efektą. Tačiau reikia atsižvelgti į tai, kad dėl žmogiškaus faktorio, skaičiavimuose gali būti klaidų. Ir labai didelė tikimybė, kad patikrinus 100000 eilučių porų, rezultatai labai skirsis nuo pateiktųjų.

### 5. Išvados
Mano hash funkcija atitinka visiems reikalavimams. Tačiau ji galėtų veikti daug greičiau. Ir reikėtų sukurti programą, kuri geriau patikrintų lavinos efektą. Taip pastebjau, kad įrašant ranka simbolius, pvz "A" ir nuskaitant tą patį simbolį, gaunu skirtingus hex'us.
