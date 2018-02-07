/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			bank_account.cpp
 * Author:			P. Bauer
 * Due Date:		November 30, 2015
 * ----------------------------------------------------------
 * Description:
 * Implementation of bank_account.h.
 * ----------------------------------------------------------
 */
 #include "bank_account.h"
 #include <stdio.h>
 #include <stdbool.h>

 struct BankAccountImplementation{
   int number;
   double interest_rate;
   double balance;
   bool is_taken;
 };

BankAccountImplementation available_count[2];
 void init_bank_accounts(){
   for(int i = 0; i < 2; i++){
     available_count[i].number = 0;
     available_count[i].interest_rate = 0.25;
     available_count[i].balance = 0;
     available_count[i].is_taken = false;
   }
 }
 BankAccount 	new_bank_account(int account_number){
   BankAccount account;
   if(account_number < 0){
     account = NULL;
   }
   else{
     for(int i = 0; i < 2; i++){
       if(available_count[i].is_taken == false){
         available_count[i].is_taken = true;
         account = &available_count[i];
       }

     }
   }
   if(account != NULL){
     account->number = account_number;
     return account;
   }
   return 0;
 }
 BankAccount 	new_bank_account(int account_number, double interest_rate){
   BankAccount account;
   account = new_bank_account(account_number);
   account->interest_rate = interest_rate;

   return account;
 }
 int 	get_account_number(BankAccount b){
   return b->number;
 }
 double 	get_balance(BankAccount b){
   return b->balance;
 }
 double 	get_interest_rate(BankAccount b){
   return b->interest_rate;
 }
 void 	deposit_amount(BankAccount b, double amount){
   b->balance = b->balance + amount;
 }
 bool 	withdraw_amount(BankAccount b, double amount){
   if(b->balance >= amount){
     b->balance = b->balance - amount;
     return true;
   }
   b->balance = 0;
   return false;
 }
