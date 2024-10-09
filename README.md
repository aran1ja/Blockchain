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
     ![image](https://github.com/user-attachments/assets/bd338b91-7b26-4c1a-80d7-2119f1deb1ed)

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
  Reikia ištirti ar mano maišos funkcija turi lavinos efektą. Tai reiškia, kad bent minimalus pakeitimas mano įvestyje, turi duoti išvestis, kurios labai skirsis viena nuo kitos. Man pavyko įgyvendinti kodą, todėl padarysiu testą su v0.1 versija ir su v0.2.

  #### Rezultatai
     
v0.1 versija:
| Min hex skirtumas  | Max hex skirtumas  | Vid hex skirtumas  | Min bit skirtumas  | Max bit skirtumas  | Vid bit skirtumas  |
|--------------------|--------------------|--------------------|--------------------|--------------------|--------------------|
| 78.125%            | 100%               | 93.7953%           | 32.0312%           | 62.5%              | 50.0411%           |

v0.2 versija:
| Min hex skirtumas  | Max hex skirtumas  | Vid hex skirtumas  | Min bit skirtumas  | Max bit skirtumas  | Vid bit skirtumas  |
|--------------------|--------------------|--------------------|--------------------|--------------------|--------------------|
| 25%                | 100%               | 92.0849%           | 9.375%             | 62.8906%           | 48.7188%           |
  
Pagal gautus rezultatus galima padaryti išvadą, kad mano maišos funkcija turi gerą lavinos efektą, nes hex vidutinis skirtumas yra virš 90%, o bit skirtumas yra apie 50%. Galima pastebėti, kad v0.2 minimalieji skirtumai yra daug mažesni už minimalius skirtumus v0.1 versijoje. Tai tikriausiai atsitiko dėl to, kad yra skirtingas skaičiavimų ciklų kiekis. Tačiau vidutiniai ir maksimalieji skirtumai parodo, kad programa vis tiek veikia efektyviai.

### 5. Išvados
Patobulinusi kodą ir maišos funkciją, galiu padaryti išvadą, kad ji atitinka visiems reikalavimams. Pasirodo, kad ir v0.1 gerai veikė, tačiau sumažinus ciklų kiekį gavau maišos funkciją, kuri veikia beveik du kartus greičiau už praeitą. Mano maišos funkcijos stiprybės: nėra kolizijų net tarp 100000 porų ir yra didelis skirtingumas tarp tų porų hash kodų, nors jie (simbolių sekų poros) ir skyrėsi tik 1 simboliu.

# Papildomos užduotys
### 1. Mano hash funkcijos palyginimas su SHA256
* SHA256 kodą panaudojau iš svetainės: http://www.zedwood.com/article/cpp-sha256-function.
* Daugiau apie SHA256 sužinojau iš https://infosecwriteups.com/breaking-down-sha-256-algorithm-2ce61d86f7a3.


Turiu du variantus kaip galima palyginti mano funkcijos spartą su SHA256 sparta:
#### Nuskaityti konstitucija.txt failą
Mano hash funkcija:

   | Eilučių kiekis | 1   | 2   | 4   | 8   | 16  | 32  | 64  | 128  | 256  | 512  | 789  |
   |----------------|-----|-----|-----|-----|-----|-----|-----|------|------|------|------|
   | Laikas (ms)    |0.199|0.201|0.401|0.808|2.001|3.600|7.600|16.012|29.217|55.970|89.002|

SHA256:

   | Eilučių kiekis | 1   | 2   | 4   | 8   | 16  | 32  | 64  | 128 | 256 | 512 | 789 |
   |----------------|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|
   | Laikas (ms)    |0    |0    |0    |0.191|0.200|0.219|0.417|0.818|1.817|2.216|3.200|

#### Sukurti įvairių didžių failus (0, 10.000, 50.000, 100.000, 250.000, 500.000)
Tam sukuriau kodą, kuris generuoja nurodytą eilučių kiekį ir kiekvienoje eilutėje yra po 10 simbolių.

Mano hash funkcija:

   | Eilučių kiekis |  0  | 10000   | 50000   | 100000   | 250000  | 500000  |
   |----------------|-----|---------|---------|----------|---------|---------|
   | Laikas (ms)    |  0  | 1036.39 | 5317.59 | 10983.5  | 26172.5 | 60405.1 |

SHA256:

   | Eilučių kiekis |  0  | 10000   | 50000   | 100000   | 250000  | 500000  |
   |----------------|-----|---------|---------|----------|---------|---------|
   | Laikas (ms)    |  0  | 34.5958 | 173.015 | 339.079  | 899.645 | 1859.44 |

   Taip pat rezultatus galima peržiūrėti "ManoHashvsSHA256.png".
   
#### Išvada
Kadangi palyginimui buvo panaudotas tas pats kodas ir tie patys failai, tai rezultatas gaunasi tikslesnis ir objektivesnis: SHA256 hashavo eilutes 29-32.5 kartų greičiau negu mano maišos funkcija.

### 2. Patikrinimas ar neįmanoma atgaminti pradinio įvedimo - patikrinti hiding ir puzzle- friendliness savybes
#### Hiding
**Hash hiding** - tai technika, naudojama užkirsti kelią tiesioginiam hash vertės atskleidimui. Tai daroma, kad būtų apsaugoti duomenys, kad net jei hash yra atskleistas, būtų sunku atkurti originalius duomenis. Tam tisklui panaudojau druską (angl. salt).

**Druska** - atsitiktinis duomenų rinkinys, kuris pridedamas prie simbolių sekos prieš ją užhashuojant. Pagrindinė druskos funkcija yra padidinti saugumą ir apsaugoti nuo atakų. Mano druskos kodas:

      string druskosPridejimas(int ilgis) {
          char simboliai[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
          string druska;
      
          for (int i = 0; i < ilgis; i++) {
              druska += simboliai[rand() % (sizeof(simboliai) - 1)]; 
          }
      
          return druska;
      }
      
      string hashFunkcijaSuDruska(string simboliu_seka) {
              int ascii_suma = 0; 
              int daugiklis = 1; 
      
              string druska = druskosPridejimas(16);
              string simboliu_seka_su_druska = simboliu_seka + druska;
              int ilgis = 8 * simboliu_seka_su_druska.size();
      
              // Zodis isverciamas i ASCII
              for (char simbolis : simboliu_seka_su_druska) {
                  ascii_suma += (int)simbolis * daugiklis;
                  daugiklis++;
              }
      
              bitset<256> binarinis_kodas((int)ascii_suma);
              bitset<256> binarinis_kodas_kopija = binarinis_kodas; 
              for (int i = 0; i < 3; i++)
              {
                  bitaiKeiciasiVietomis(binarinis_kodas_kopija);
              }
              
              string hexKodas = hexPadarymas(binarinis_kodas_kopija);
              //cout << "Hash kodas su druska hex pavidalu:    " << hex << hexKodas << endl;
              return druska + hexKodas;
      }

Tam, kad patikrinti mano hash funkcijoje realizuotą hiding savybę, nusprendžiau nuskaityti 100.000 identiškų string porų. Yra 25000 porų po 10 simbolių, po 100, 500 ir 1000. Jeigu druska gerai veikia, tai tarp hex'ų turėtų būti 100.000 kolizijų, kas įrodytų dar kartą, kad mano maišos funkcija yra deterministinė. Tačiau tarp hex'ų su druska turėtų būti 0 kolizijų.

#### Rezultatai
![image](https://github.com/user-attachments/assets/28ec889e-9f45-429a-a310-000246d09123)

#### Išvada
Pagal rezultatus galima padaryti išvadą, kad mano maišos funkcija turi gerą deterministinę ir hiding savybes, nes kiekvienai identiškai porai stringų yra 100.000 hex kolizijų ir 0 hex + druskos kolizijų. Tai reiškia, kad kiekvienai tai pačiai įvesčiai yra tokia pati hex išvestis. Tačiau druska pakeičia hex taip, kad praktiškai neįmanoma atgaminti pradinio įvedimo ar jo hex'o.

#### Puzzle-friendliness
**Puzzle-friendliness** reiškia, kad net ir maži pradinės įvesties pokyčiai sukelia didelius pokyčius hash vertėse. Todėl nuspendžiau padaryti daug labai panašių įvesčių ir patikrinti, ar yra bent 2 tokie patys hex su druska. Jei visais atvejais kolizijų nėra, tai rodo, kad net ir nedideli įvesties pakeitimai sukuria unikalius hash rezultatus. Tai įrodytų, kad mano funkcija turi puzzle-friendliness savybę.

Tam, kad patikrinti mano hash funkcijoje realizuotą puzzle-friendliness savybę, nusprendžiau padaryti 100.000 string porų, kurie skirtusi 1 skaičiumi: labas0, labas1, labas2 itt.

#### Rezultatai
![image](https://github.com/user-attachments/assets/7cd377ed-6b43-44d3-81ff-456bee338654)

#### Išvada
Pagal rezultatus galima padaryti išvadą, kad mano maišos funkcija turi puzzle-friendliness savybes, nes nors kiekviena įvestis labai mažai keitėsi, tačiau jokių kolizijų tarp 100.000 eilučių nebuvo aptikta. Todėl pagalvojau, kad galimai, yra per mažai eilučių ir patikrinau 1.000.000 eilučių ir rezultatas buvo toks pat: 0 kolizijų.

Taigi, mano funkcija turi hiding ir puzzle-friendliness savybes, kas įrodo, kad mano iš hash funkcijos rezultato praktiškai neįmanoma atgaminti pradinio įvedimo.

### 3. Hash funkcijų integravimas į mano programą
Sukuriau failą "Intergruotas.cpp" kur iš pradžių įtraukiau 5 kodus. Tų kodų savininkų github nuorodos (įskaitant mano):

      * https://github.com/aran1ja/Blockchain/tree/v0.2
      * https://github.com/robke0224/blockchain
      * https://github.com/EligMaa/blockchain_darbas_1/tree/v0.1
      * https://github.com/kamzob/Blockchain/tree/v0.2
      * https://github.com/paulynaa/Blockchain/tree/v0.2

tačiau vienas man neveikė (Robertos), todėl galutiniame rezultate yra 4 kodai.

Nusprendžiau iš pradžių paleisti kiekvieną kodą atskirai ir įvertinti kiek laiko užima "konstitucija.txt" eilučių hashavimas, ar pasitaiko kolizijos ir kokio efektyvumo yra lavinos efektas. Po rezultatų palyginimo išreitinguosiu kieno kodas yra efektyviausias.

_**"Integruotas.cpp"**_ paleidžia 4 kodus atskirai ir priklauso nuo "ManoHash.h", "rugiles_hash.h", "kamiles_hash.h", "paulinos_hash.h".

_**"ViskasViename.cpp"**_ paleidžia 1 kodą, kuriame yra sujungtos 4 maišos funkcijos ir priklauso nuo "bendras_hash.h".

#### Adriana
1. Failo "konstitucija.txt" eilučių hashavimo laikas.
   
   | Eilučių kiekis | 1   | 2   | 4   | 8   | 16  | 32  | 64  | 128  | 256  | 512  | 789  |
   |----------------|-----|-----|-----|-----|-----|-----|-----|------|------|------|------|
   | Laikas (ms)    |0.185|0.199|0.400|0.801|1.800|3.218|7.816|17.200|30.417|58.101|89.017|

2. Kolizijų kiekis: 0.
3. Skirtumas bitų ir hex'ų lygmenyje

   | Min hex skirtumas  | Max hex skirtumas  | Vid hex skirtumas  | Min bit skirtumas  | Max bit skirtumas  | Vid bit skirtumas  |
   |--------------------|--------------------|--------------------|--------------------|--------------------|--------------------|
   | 25%                | 100%               | 92.0766%           | 9.375%             | 62.8906%           | 48.7091%           |

#### Rugilė
1. Failo "konstitucija.txt" eilučių hashavimo laikas.
   
   | Eilučių kiekis  | 1   | 2   | 4   | 8   | 16   | 32   | 64  | 128  | 256  | 512  |
   |-----------------|-----|-----|-----|-----|------|------|-----|------|------|------|
   | Laikas (ms)     |  0  |  0  |  0  |  0  |0.4004|0.1996|0.400|1.4038|2.4126|6.4182|

2. Kolizijų kiekis: 0.
3. Skirtumas bitų ir hex'ų lygmenyje

   | Min hex skirtumas  | Max hex skirtumas  | Vid hex skirtumas  | Min bit skirtumas  | Max bit skirtumas  | Vid bit skirtumas  |
   |--------------------|--------------------|--------------------|--------------------|--------------------|--------------------|
   | 75%                | 100%               | 93%                | 37%                | 65%                | 50%                |
   
#### Kamilė
1. Failo "konstitucija.txt" eilučių hashavimo laikas.
   
   | Eilučių kiekis  | 1   | 2   | 4   | 8   | 16  | 32  | 64   | 128  | 256  | 512  |
   |-----------------|-----|-----|-----|-----|-----|-----|------|------|------|------|
   | Laikas (ms)     |  0  |  0  |  0  |  0  |  0  | 0.2 |0.6042|1.2028|2.7976|6.5992|

2. Kolizijų kiekis: 0.
3. Skirtumas bitų ir hex'ų lygmenyje

   | Min hex skirtumas  | Max hex skirtumas  | Vid hex skirtumas  | Min bit skirtumas  | Max bit skirtumas  | Vid bit skirtumas  |
   |--------------------|--------------------|--------------------|--------------------|--------------------|--------------------|
   | 68.75%             | 100%               | 93.4453%           | 36.3281%           | 62.1094%           | 49.8915%           |
   
#### Paulina
1. Failo "konstitucija.txt" eilučių hashavimo laikas.
   
   | Eilučių kiekis | 1   | 2   | 4   | 8   | 16  | 32  | 64  | 128 | 256 | 512 | 789 |
   |----------------|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|
   | Laikas (ms)    |1.997|1.002|1.000|1.999|1.002|2.004|2.000|0.999|1.999|2.960|3.999|

2. Kolizijų kiekis: 0.
3. Skirtumas bitų ir hex'ų lygmenyje

   | Min hex skirtumas  | Max hex skirtumas  | Vid hex skirtumas  | Min bit skirtumas  | Max bit skirtumas  | Vid bit skirtumas  |
   |--------------------|--------------------|--------------------|--------------------|--------------------|--------------------|
   | 30%                | 100%               | 87.41%             | 12.5%              | 87.50%             | 49.18%             |

#### Rezultatai
Rezultatus galima peržiūrėti "Palyginimas1.png" ir "Palyginimas2.png". Visuose koduose nėra kolizijų.
- Palyginimas1
Padarykime lentelę su rezultatais

   | Vardas     | 1   | 2   | 4   | 8   | 16   | 32       | 64      | 128     | 256     | 512     | 789     |
   |------------|-----|-----|-----|-----|------|----------|---------|---------|---------|---------|---------|
   | Adriana    |0.185|0.199|0.400|0.801|1.800 |3.218     |7.816    |17.200   |30.417   |58.101   |89.017   |
   | Rugilė     |**0**|**0**|**0**|**0**|0.4004|**0.1996**|**0.400**|1.4038   |2.4126   |6.4182   |  -      |
   | Kamilė     |**0**|**0**|**0**|**0**|**0** | 0.2      |0.6042   |1.2028   |2.7976   |6.5992   |  -      |
   | Paulina    |1.997|1.002|1.000|1.999|1.002 |2.004     |2.000    |**0.999**|**1.999**|**2.960**|**3.999**|
  
  Pagal duotą lentelę gerai matosi kieno kodas nuskaitė greičiau tam tikrą eilučių kiekį. Taigi laimi tas, kuri daugiau pajuodintų (reiškia geriausių kategorijoje) rezultatų.

  Rezultatas:
  
   | Vardas  | Vieta |
   |---------|-------|
   | Rugilė  | 1     | 
   | Kamilė  | 2     | 
   | Paulina | 3     | 
   | Adriana | 4     |

- Palyginimas2
Padarykime lentelę su rezultatais

   | Vardas  | Vid bit | Max bit | Min bit | Vid hex   | Max hex | Min hex |
   |---------|---------|---------|---------|-----------|---------|---------|
   | Adriana | 48.7091 | 62.8906 |  9.375  | 92.0766   | **100** | 25      |
   | Rugilė  | **50**  | 65      | **37**  | 93        | **100** | **75**  |
   | Kamilė  | 49.8915 | 62.1094 | 36.3281 |**93.4453**| **100** | 68.75   |
   | Paulina | 49.18   | **87.5**| 12.5    | 87.41     | **100** | 30      |

  Pagal duotą lentelę gerai matosi kieno rodyklės yra geriausios kurioje kategorijoje. Taigi laimi tas, kuri daugiau pajuodintų (reiškia geriausių kategorijoje) rezultatų.

  Rezultatas:
  
   | Vardas  | Vieta |
   |---------|-------|
   | Rugilė  | 1     | 
   | Kamilė  | 2     | 
   | Paulina | 2     | 
   | Adriana | 3     |

  #### Išvada
  Apibendrinus rezultatus iš abiejų palyginimų, darosi akivaizdu, kad pagal visus rezultatus, galutinis reitingiavimas atrodo taip:

   | Vardas  | Vieta |
   |---------|-------|
   | Rugilė  | 1     | 
   | Kamilė  | 2     | 
   | Paulina | 3     | 
   | Adriana | 4     |

-------------------------------------------------------------------------------------------------------------

#### Apjungto kodo rezultatas
1. Failo "konstitucija.txt" eilučių hashavimo laikas.
   
   | Eilučių kiekis | 1   | 2   | 4   | 8   | 16  | 32  | 64  | 128  | 256  | 512  | 789   |
   |----------------|-----|-----|-----|-----|-----|-----|-----|------|------|------|-------|
   | Laikas (ms)    |0.216|0.199|0.599|0.984|2.218|4.553|8.977|18.554|39.908|80.489|121.574|

   Palyginus net su lėčiausiai veikiančiomis programomis iš anksčiau nurodytos lentelės, ši programa veikia net dar lėčiau. Taip įvyko dėl to, kad labai daug yra skaičiavimų.

3. Kolizijų kiekis: 0.
4. Skirtumas bitų ir hex'ų lygmenyje

   | Min hex skirtumas  | Max hex skirtumas  | Vid hex skirtumas  | Min bit skirtumas  | Max bit skirtumas  | Vid bit skirtumas  |
   |--------------------|--------------------|--------------------|--------------------|--------------------|--------------------|
   | 18.75%             | 100%               | 93.5486%           | 7.8125%            | 64.0625%           | 49.7146%           |

   Palyginus su geriausiais rezultatais praeitos programos, tai čia geresnis tik vidutinis hex skirtumas.

  Įrodymas:
  ![image](https://github.com/user-attachments/assets/0cd00b1d-15ff-4091-9bf7-e462159ca19c)

  Taigi, programa apjungia 4 skirtingas maišos funkcijas, tačiau ji netapo efektyvesnė nei laiko atžvilgiu, nei kokybiškumo (ji turi geresnį vidutinį skirtumą, tačiau ji geresnė tik 0.1033%).

