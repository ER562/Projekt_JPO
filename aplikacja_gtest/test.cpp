#include <gtest/gtest.h>
#include "../../aplikacja/data_base.h"

TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

data_center base;
person per1 = { "Ula","Nowak",30,9,1986,"balicka",87,"Mydlniki","Polska",444555666,"ula@hotmail.com" };
person per2 = { "Mateusz", "Kowalczyk",12,5,2001,"stefana okrzei",4,"S³omniki","Polska",222333444,"mateusz@wp.pl" };
person per3 = { "Iwona", "Wiœniewska",28,7,1996,"³¹kowa",25,"Modlniczka","Polska",333444555,"iwona@interia.pl" };



TEST(TestCaseName, size_test) {
	base.put_record(per1);
	base.put_record(per2);
	EXPECT_EQ(base.size(), 2);
	//puting 2 records and checking size
}

TEST(TestCaseName, put_record_test) {
	base.put_record(per3);
	EXPECT_EQ(base.size(), 3);
	//adding 1 more
}

TEST(TestCaseName, get_record_test1) {
	person y;
	int x = base.get_record(0, y);
	EXPECT_EQ(x, 0);
	EXPECT_EQ(y.name, per1.name);
	EXPECT_EQ(y.surname, per1.surname);
	//geting right index
}

TEST(TestCaseName, get_record_test2) {
	person y;
	int x = base.get_record(3, y);
	EXPECT_EQ(x, 1);
	std::cout << y.name;
	//geting wrong index
	//only 3 data sets <-- indexes from 0 to 2
}

TEST(TestCaseName, delete_record_test) {
	base.delete_record(2);
	EXPECT_EQ(base.size(), 2);
	//deleting 1 of 3 records
}

TEST(TestCaseName, find_record_test) {
	base.put_record(per3);
	vector <int> k = base.find_record(per2, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0);
	EXPECT_EQ(k[0], 1);
	//searching for person 2 which index is 1
}

TEST(TestCaseName, load_record_test) {
	person u = base.load_record("Ula,Nowak,30,9,1986,balicka,87,Mydlniki,Polska,444555666,ula@hotmail.com");
	EXPECT_EQ(u.name, per1.name);
	EXPECT_EQ(u.surname, per1.surname);
	//person 1 is the same as the one loaded
}

TEST(TestCaseName, save_record_test) {
	string st1 = base.save_record(1);
	string st2 = "Ula,Nowak,30,9,1986,balicka,87,Mydlniki,Polska,444555666,ula@hotmail.com";
	EXPECT_EQ(st1, st2);
	//doing the same thing as in test above but saveing records instead of loading
}