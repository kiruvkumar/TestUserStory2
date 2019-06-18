
/* -------------------------------------------------------------------------------
	Script Title       : TestUserStory2 - Payment
	Script Description : Payment made by booking flight 
   
   ------------------------------------------------------------------------------- */

vuser_init()
{
	
	
	lr_start_transaction("TestUserStory2_01_HomePage");
	
	//check point to ensure page load correctly
	web_reg_find("Text=Web Tours", 
		LAST);
	
	web_url("WebTours",
		"URL=http://{url}/WebTours/",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=",
		"Snapshot=t1.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("TestUserStory2_01_HomePage", LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("TestUserStory2_02_Login");
	
	//username and password are parameterized to execute the script for multiple users
	web_submit_form("login.pl",
		"Snapshot=t2.inf",
		ITEMDATA,
		"Name=username", "Value={username}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=43", ENDITEM,
		"Name=login.y", "Value=12", ENDITEM,
		LAST);

	lr_end_transaction("TestUserStory2_02_Login", LR_AUTO);

	//think time at end of each transaction to ensure enough time is given between each transaction like how users will take time between each action
	lr_think_time(5);

	return 0;
}


