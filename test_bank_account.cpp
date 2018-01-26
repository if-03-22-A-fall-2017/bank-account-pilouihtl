/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			test_bank_account.cpp
 * Author:			P. Bauer
 * Due Date:		November 30, 2015
 * ----------------------------------------------------------
 * Description:
 * Test functions for bank_account.
 * ----------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>

#include "shortcut.h"
#include "bank_account.h"
#include "test_bank_account.h"

TEST(simple_creation)
{
	init_bank_accounts();

	int account_number = 314159265;

	BankAccount b = new_bank_account(account_number);
	ASSERT_EQUALS(account_number, get_account_number(b));
	ASSERT_EQUALS_TOLERANCE(0., get_balance(b), 0.);
	ASSERT_EQUALS_TOLERANCE(0.25, get_interest_rate(b), 0.);
}

TEST(customized_creation)
{
	init_bank_accounts();

	int account_number = 123456789;
	double interest_rate = 0.3;

	BankAccount b = new_bank_account(account_number, interest_rate);
	ASSERT_EQUALS(account_number, get_account_number(b));
	ASSERT_EQUALS_TOLERANCE(0., get_balance(b), 0.);
	ASSERT_EQUALS_TOLERANCE(0.3, get_interest_rate(b), 0.);
}

TEST(create_max_number_of_accounts)
{
	init_bank_accounts();

	int i = -1;
	BankAccount b;

	do {
		b = new_bank_account(i * 100);
		i++;
	} while (b != 0);

	ASSERT_EQUALS(2, i);
}

TEST(deposit_amount)
{
	init_bank_accounts();
	BankAccount b = new_bank_account(111111111);
	deposit_amount(b, 100.);

	ASSERT_EQUALS_TOLERANCE(100., get_balance(b), 0.001);

	deposit_amount(b, 200.);
	ASSERT_EQUALS_TOLERANCE(300., get_balance(b), 0.001);
}

TEST(withdraw_amount) {
	init_bank_accounts();
	BankAccount b = new_bank_account(222222222);

	deposit_amount(b, 300.25);
	bool transaction_is_ok = withdraw_amount(b, 50.);

	ASSERT_TRUE(transaction_is_ok, "Withrawal expected to be ok");
	ASSERT_EQUALS_TOLERANCE(250.25, get_balance(b), 0.001);

	transaction_is_ok = withdraw_amount(b, 150.25);
	ASSERT_TRUE(transaction_is_ok, "Withrawal expected to be ok");
	ASSERT_EQUALS_TOLERANCE(100., get_balance(b), 0.001);
}

TEST(withdraw_under_0)
{
	init_bank_accounts();
	BankAccount b = new_bank_account(333333333);

	deposit_amount(b, 0.01);
	bool transaction_is_ok = withdraw_amount(b, 0.01);
	ASSERT_TRUE(transaction_is_ok, "Withdrawal until a balance of 0. expected to be ok");

	transaction_is_ok = withdraw_amount(b, 0.01);
	ASSERT_FALSE(transaction_is_ok, "Withdrawals bringing balance under 0. expected to be denied");
	ASSERT_EQUALS_TOLERANCE(0., get_balance(b), 0.);
}
