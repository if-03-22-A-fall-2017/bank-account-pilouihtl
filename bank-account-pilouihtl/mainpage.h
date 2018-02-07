/**
* @mainpage
* @section intro Einleitung
* Es soll abstrakter Datentyp BankAccount implementiert werden, welcher einfache
* Kontotransaktionen ermöglichen soll.
*
* @section example Beispiel
* Eine typische Code-Sequenz für das Anlegen eines neuen Kontos, das Einzahlen
* von 300.25 Euro und das Abheben von 50.00 Euro wäre folgendermaßen:

* @code
* init_bank_accounts();
* BankAccount b = new_bank_account(222222222);

* deposit_amount(b, 300.25);
* bool transaction_is_ok = withdraw_amount(b, 50.);
*
* // Assertions expected to hold after the above transactions.
* ASSERT_TRUE(transaction_is_ok, "Withrawal expected to be ok");
* ASSERT_EQUALS_TOLERANCE(250.25, get_balance(b), 0.001);
* @endcode
*
* @section assignment Aufgabe
* -# Machen Sie eine forward-Deklaration für BankAccount, und erstellen Sie Prototypen
* für die in den Unit Tests aufgerufenen Funktionen.
* -# Erstellen Sie minimale Leerimplementierungen für alle erforderlichen Funktionen,
* damit das Gesamtprojekt baut und läuft (Unit Tests fail).
* -# Definieren Sie das struct aus der forward-Deklaration.
* -# Erstellen Sie lokale (nur im File bank_account.cpp) Variablen für alle erforderlichen
* Autos.
* -# Erstellen Sie ein lokales Array <code>available_accounts</code> in welchem alle
* Accounts abgespeichert werden können.
* -# Implementieren Sie die Funktionen so, dass alle Unit Tests erfolgreich
* durchlaufen.
*/
