# Ultrazvukovy merac vzdialenosti - cuvaci senzor- ESP32
Projekt Ultrazvukový merač vzdialenosti – cúvací senzor sa zameriava na návrh a realizáciu jednoduchého IoT zariadenia založeného na mikrokontroléri ESP32, ktoré umožňuje bezkontaktné meranie vzdialenosti pomocou ultrazvukového senzora. Projekt simuluje princíp cúvacích senzorov používaných v automobilovom priemysle.

Cieľom projektu je: navrhnúť funkčný systém na meranie vzdialenosti,implementovať vizuálnu spätnú väzbu pre používateľa,overiť princíp fungovania ultrazvukového merania, preukázať schopnosť samostatne navrhnúť, naprogramovať a zdokumentovať IoT riešenie.Projekt je určený ako študijný a demonštračný materiál pre predmet Internet vecí.

Použité technológie a nástroje
Hardvér 
ESP32 – mikrokontrolér s podporou IoT aplikácií
Ultrazvukový senzor HC-SR04
OLED displej SSD1306 (128×64, I2C)
LED dióda (vizuálna signalizácia)
Rezistory a prepojovacie vodiče
Softvér
Arduino IDE
Programovací jazyk Arduino

Knižnice:
Adafruit_GFX
Adafruit_SSD1306
Wire (I2C komunikácia)

Architektúra a princíp činnosti
Zariadenie pracuje na princípe odrazu ultrazvukových vĺn. Ultrazvukový senzor vyšle krátky zvukový impulz, ktorý sa odrazí od prekážky a vráti sa späť k senzoru. Mikrokontrolér na základe času návratu signálu vypočíta vzdialenosť objektu.

Namerené údaje sú: spracované mikrokontrolérom ESP32, zobrazené na OLED displeji v slovenskom jazyku, vyhodnotené z hľadiska bezpečnej vzdialenosti. Ak je prekážka príliš blízko, systém aktivuje LED diódu ako výstražný prvok.

Používateľské rozhranie (UI)
Používateľské rozhranie je realizované pomocou OLED displeja: zobrazuje aktuálnu vzdialenosť v centimetroch, v prípade prekročenia rozsahu merania sa zobrazí hlásenie „Mimo rozsahu“, rozhranie je jednoduché, prehľadné a plne lokalizované do slovenského jazyka. LED dióda slúži ako okamžitý vizuálny indikátor kritickej vzdialenosti.

Funkčné scenáre
Normálny stav: Objekt je vo vzdialenosti väčšej ako 10 cm → LED nesvieti, na displeji je zobrazená vzdialenosť.
Varovný stav: Objekt je vo vzdialenosti 10 cm alebo menej → LED dióda sa rozsvieti.
Chybný alebo neplatný údaj: Objekt je mimo merateľného rozsahu → na displeji sa zobrazí informačné hlásenie.

Praktické využitie
Projekt je možné využiť: ako základ cúvacieho senzora, v mobilnej robotike, v automatizácii a smart zariadeniach, ako edukačnú pomôcku pri výučbe IoT a embedded systémov.
Možnosti rozšírenia
zvuková signalizácia (bzučiak),
webové rozhranie ESP32,
bezdrôtový prenos údajov (Wi-Fi, MQTT),
mobilná aplikácia,
viacúrovňová signalizácia podľa vzdialenosti.

Zdroje a inšpirácia
https://www.youtube.com/@kiku-uniot/videos
