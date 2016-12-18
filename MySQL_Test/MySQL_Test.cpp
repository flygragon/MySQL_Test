// MySQL_Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include<Windows.h>
#include<mysql.h>
#include<iostream>
#include<string>
//#pragma comment (lib,"D:\\MySQL\\mysql-5.7.16-winx64\\lib\\libmysql.lib")

int main()
{
	std::string user_name = "user01",
		user_passwd = "user01passwd",
		db_name = "user01db";
	MYSQL mysql_obj;
	mysql_init(&mysql_obj);
	if (!mysql_real_connect(&mysql_obj, "localhost", user_name.c_str(), user_passwd.c_str(), db_name.c_str(), 3306, NULL, 0)) {
		std::cout << "Connect Error!!" << std::endl;
		return 0;
	}
	else {
		std::cout << "Connect Succeed" << std::endl;
		std::string cmd_ins_str = "insert into stuinf values(35,'Kugou','M',25)",
			cmd_select_str ="select * from stuinf";
		int res_int = mysql_real_query(&mysql_obj, cmd_select_str.c_str(), (unsigned int)strlen(cmd_select_str.c_str()));
		MYSQL_RES *res;
		MYSQL_ROW query_row;
		if (res_int) {
			std::cout << "Query Failed" << std::endl;
		}
		else {
			res = mysql_store_result(&mysql_obj);
			while ((query_row = mysql_fetch_row(res))) {
				for (unsigned int i = 0; i < mysql_num_fields(res); i++)
					std::cout << query_row[i] << ' ';
				std::cout << std::endl;
			}
			mysql_free_result(res);
		}
		
		res_int = mysql_real_query(&mysql_obj, cmd_ins_str.c_str(), (unsigned int)strlen(cmd_ins_str.c_str()));
		if (res_int)
			std::cout << "Insert Failed" << std::endl;
		else
			std::cout << "Insert Succeed" << std::endl;
		//mysql_free_result(res);
		
	}
	
    return 0;
}

