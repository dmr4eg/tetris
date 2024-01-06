# Hra "Tetris"
### Projekt do předmětu B6B36PCC - Programování v C/C++
### Autor: Kabi Damir (assyldam)
### Vyučující: RNDr. Ingrid Nagyová, Ph.D.

## Popis hry  
#### Hra Tetris je klasická hra, která se hrá na čtvrcovém poli o velikosti 10x20. Hráč má za úkol skládat padající kostky do řádků, které se poté z pole vytrácejí. Hra končí, pokud se kostky dostanou až k hornímu okraji herního pole. Hráč má možnost ovládat kostky pomocí šipek na klávesnici. Kostky se mohou pohybovat doprava a doleva. 

## Ovládání
#### 'A' - posun kostky doleva
#### 'D' - posun kostky doprava
#### 'S' - zrychlení pádu kostky

## Základní struktura programu
#### Program je rozdělen do několika souborů. Hlavní soubor je main.cpp, který obsahuje hlavní main funkci hry. Dále v souboru jsou různé funkci, které obsahuje funkce pro vytvoření herního pole, vykreslení herního pole, vykreslení kostky, posun kostky, kontrolu kolize kostky s okrajem herního pole a kontrolu kolize kostky s ostatními kostkami. 

## Testování
#### K tomu je použit soubor tetristest.cpp, který obsahuje funkce pro testování. Testování je provedeno pomocí knihovny Google Test. Testování obsahuje testy pro všechny funkce, které jsou v programu použity.

## Překlad programu
#### Program je přeložen pomocí cmake souboru. Překlad je proveden pomocí příkazu `cmake .` a `make`. Po překladu vznikne spustitelný soubor tetris.

## Poznámky
#### V kódu jsou použity komentáře, které popisují funkce a části kódu. 
#### Pro testování: V main.cpp souboru je methoda `drawLoop()`, ve kterém `std::this_thread::sleep_for(std::chrono::milliseconds(1200));` (181 řádek) hodnota millisekund je nastavena na 1200, ale já bych změnil hodnotu na 10, aby nebyla chyba `Process terminated due to timeout.` Tato hodnota určuje rychlost běhu hry. 
#### Když uživatel stiská klavesu, pak pro vstup do programu musí stisknout klávesu enter. Například: `s` a pak stisknout enter.

## Checklist pro odevzdání
* Kód
    * Obsahuje váš kód CMakeLists.txt přes který se vaše semestrálka dá postavit? `Ano`
    * Je implementována nápověda (argument programu --help)? `Ano`
* Použití vláken pro vyšší bodové hodnocení
    * Používá váš kód alespoň tři vlákna, která správně komunikují? `Ano`
    * Nepoužívá váš kód rozšíření jazyka? (Například OpenMP, VLA) `Ne`
    * Nepoužívá váš kód nepřenosné knihovny (Například POSIX, Win32, filesystem) `Ne`
* Testování
    * Obsahuje vaše řešení popis způsobů a postupů testování? Obsahuje příklady testů, které jste prováděli? `Ano`
    * Zkontrolovali jste svoje řešení s využitím vhodného analytického nástroje (valgrind, dr. Memory apod.)? `Ano`
* Zpráva
    * Obsahuje vaše zpráva hash commitu (nebo tag), vůči kterému byla napsaná? `Ano`
    * Obsahuje vaše zpráva popis zadání? `Ano`
    * Obsahuje vaše zpráva popis ovládání hry? `Ano`
    * Obsahuje vaše zpráva popis možností a způsobů nastavení hry? `Takové možnosti nejsou`
    * Máte proměnné a funkce programu řádně zdokumentovány? Jsou všude doplněny komentáře? `Ano`