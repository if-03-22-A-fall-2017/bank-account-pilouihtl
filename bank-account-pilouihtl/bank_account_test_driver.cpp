/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			bank_account
 * Author:			P. Bauer
 * Due Date:		November 30, 2015
 * ----------------------------------------------------------
 * Description:
 * bank_account demo project.
 * ----------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>

#include "bank_account.h"

#include "shortcut.h"
#include "test_bank_account.h"

int main(int argc, char *argv[])
{
	ADD_TEST(simple_creation);
	ADD_TEST(customized_creation);
	ADD_TEST(create_max_number_of_accounts);
	ADD_TEST(deposit_amount);
	ADD_TEST(withdraw_amount);
	ADD_TEST(withdraw_under_0);

	run_tests();
	return 0;
}
