/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			bank_account.h
 * Author:			P. Bauer
 * Due Date:		November 30, 2015
 * ----------------------------------------------------------
 * Description:
 * bank_account abstract data type demo.
 * ----------------------------------------------------------
 */
#ifndef ___BANK_ACCOUNT_H
#define ___BANK_ACCOUNT_H

typedef struct BankAccountImplementation * 	BankAccount;



void 	init_bank_accounts();
BankAccount 	new_bank_account(int account_number);
BankAccount 	new_bank_account(int account_number, double interest_rate);
int 	get_account_number(BankAccount b);
double 	get_balance(BankAccount b);
double 	get_interest_rate(BankAccount b);
void 	deposit_amount(BankAccount b, double amount);
bool 	withdraw_amount(BankAccount b, double amount);


#endif
