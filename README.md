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
   

