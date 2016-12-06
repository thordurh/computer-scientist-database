Skil 1-b
---
Project source can be downloaded from https://github.com/bergros16/Verkefni_2.git
---
Authors
---
Bergrós Gígja Þorsteinsdóttir    
Eva Sif Einarsdóttir  
Hera Hjaltadóttir  
Kristinn Godfrey Guðnason  
Sigurður Sturla Bjarnason  
Þórður Örn Helgason  

Instructors(Minions)
---
Alex Kári Ívarsson  
Ingibergur Sindri Stefnisson

Todo
---
- [ ] Forkröfur
  - [ ] Þarf að skipta gagnalagi út fyrir SQL repository (sterklega mælt með því að nota SQLite). Ath. að þetta er krafa sem verður að uppfylla til að fá einkunn fyrir verkefnið.
  - [x] Nota skal Qt Creator við smíði kerfisins
  - [x] Kerfið verður að geta allt sem hægt var í fyrsta verkefninu, þar á meðal að kerfið sé lagskipt!
- [ ] 20%  Notandi þarf að geta skráð þekktar tölvur úr sögu tölvunarfræðinnar. Það sem þarf að vera hægt að skrá er:
  - [ ] Nafn
  - [ ] Byggingarár
  - [ ] Tegund tölvu (Mekkanísk, Elektrónísk, Smáravélar (þ.e. þær sem nota transistora), etc.)
  - [ ] Var hún byggð eða ekki?
- [ ] 10% Þegar listi af tölvum er birtur notandanum þá fær hann að ráða hvernig honum er raðað.
- [ ] 10% Notandi þarf að geta leitað að tölvu.
- [ ] 30% Notandi þarf að geta tengt saman tölvur og persónur:
  - [ ] Hver persóna getur verið tengd mörgum tölvum
  - [ ] Hver tölva getur verið tengt mörgum persónum
  - [ ] Þessar tengingar þarf að vera hægt að skoða og viðhalda, nákvæm útfærsla er í höndum sérhvers hóps
- [ ] 10% Kóðinn skal vera lesanlegur, vel formaður, vel skjalaður, og viðhaldanlegur, og að samræmi sé í forritunarstíl, til dæmis:
  - [ ] Rétt inndreginn
  - [ ] Samræmi í staðsetningu á slaufusvigum
  - [ ] Stíll við nafnagiftir á breytum, föllum og klösum (t.d. að velja PascalCasing, camelCasing, snake_casing o.s.frv.)
  - [ ] Athugasemdir lýsandi en í hófi. Lýsa af hverju kóðinn er eins og hann er, en ekki hvað hann gerir
  - [ ] o.s.frv.
- [ ] 20% Bónus: hvers konar aukavirkni
  - [x] Hægt að vinna með first name og last name

Now:
---
Beggó: Skipta gagnalaginu út í SQL

Kiddi: SQL joins

[//]: # (This is a comment, it will not be included) Eva: Skipta gagnalagi út fyrir SQL repository)

[//]: # (bæta við Qt forritið að adda tölvum)

[//]: # (Hera:)

[//]: # (Þórður)



Our Formatting rules
---

```
Við ætlum að skrifa c++ kóðann í camelCase en skrifa klasanöfnin með PascalCase t.d.

firstName = "Stulli";
lastName  = "Johnson";

```

```
SQL kóði er skrifaður með snake_case t.d

CREATE TABLE person (
  id PRIMARY KEY,
  first_name text NOT NULL,
  last_name text NOT NULL
  );
```

Restin af verkefnalýsingu - þarf ekki mikið að spá í þessu eins og er
---
Athugið að misbrestir á forkröfum eða hópastarfi geta komið til frádráttar við einkunnagjöf.

Skila skal einni .zip / .rar skrá sem inniheldur allan kóða verkefnisins þannig að hægt sé að þýða og keyra verkefnið. Einnig skal fylgja með gagnaskrá með nokkrum færslum, bæði fyrir vísindamenn og tölvur, og tengingar þar á milli. 

- [ ]  Kóðinn skal vera lesanlegur, vel formaður, vel skjalaður, og viðhaldanlegur, og að samræmi sé í forritunarstíl, til dæmis:
  - [ ] Rétt inndreginn
  - [ ] Samræmi í staðsetningu á slaufusvigum
  - [x] Stíll við nafnagiftir á breytum, föllum og klösum (t.d. að velja PascalCasing, camelCasing, snake_casing o.s.frv.)
  - [ ] Athugasemdir lýsandi en í hófi. Lýsa af hverju kóðinn er eins og hann er, en ekki hvað hann gerir
  - [ ] o.s.frv.
