
TestUserStory2_Payment()
{
	
	lr_start_transaction("TestUserStory2_03_SearchFlight");
	
	web_reg_find("Text=Find Flight", 
		LAST);
	
	web_url("welcome.pl",
		"URL=http://{url}/cgi-bin/welcome.pl?page=search",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://{url}/cgi-bin/nav.pl?page=menu&in=home",
		"Snapshot=t3.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("TestUserStory2_03_SearchFlight", LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("TestUserStory2_04_BookFlight");
	
	
/*  Num is a parameter of listed depart and arrival locations. Random - each occurance setting is given so that each time a different value 
will be used and fligts for two different destinations will be booked for each iteration */

	web_submit_form("reservations.pl",
		"Snapshot=t4.inf",
		ITEMDATA,	
		"Name=depart", "Value={num}", ENDITEM,
		"Name=departDate", "Value={departdate}", ENDITEM,
		"Name=arrive", "Value={num}", ENDITEM,
		"Name=returnDate", "Value={returndate}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=roundtrip", "Value=<OFF>", ENDITEM,
		"Name=seatPref", "Value=Aisle", ENDITEM,
		"Name=seatType", "Value=Coach", ENDITEM,
		"Name=findFlights.x", "Value=18", ENDITEM,
		"Name=findFlights.y", "Value=6", ENDITEM,
		LAST);

	web_submit_form("reservations.pl_2",
		"Snapshot=t5.inf",
		ITEMDATA,
		"Name=outboundFlight", "Value=030;251;{departdate}", ENDITEM,
		"Name=reserveFlights.x", "Value=34", ENDITEM,
		"Name=reserveFlights.y", "Value=13", ENDITEM,
		LAST);

	lr_end_transaction("TestUserStory2_04_BookFlight", LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("TestUserStory2_05_PaymentDetails");
	
	web_reg_find("Text=Payment Details", 
		LAST);

	//All the below values are parameterised and substituted for each user
	web_submit_form("reservations.pl_3",
		"Snapshot=t6.inf",
		ITEMDATA,
		"Name=firstName", "Value={firstname}", ENDITEM,
		"Name=lastName", "Value={lastname}", ENDITEM,
		"Name=address1", "Value={Address1}", ENDITEM,
		"Name=address2", "Value={address2}", ENDITEM,
		"Name=pass1", "Value={firstname} {lastname}", ENDITEM,
		"Name=creditCard", "Value={creditcardnumber}", ENDITEM,
		"Name=expDate", "Value={expdate}", ENDITEM,
		"Name=saveCC", "Value=<OFF>", ENDITEM,
		"Name=buyFlights.x", "Value=41", ENDITEM,
		"Name=buyFlights.y", "Value=15", ENDITEM,
		LAST);

	lr_end_transaction("TestUserStory2_05_PaymentDetails", LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("TestUserStory2_06_CheckItenary");

	web_image("Itinerary Button",
		"Alt=Itinerary Button",
		"Snapshot=t7.inf",
		LAST);

	lr_end_transaction("TestUserStory2_06_CheckItenary", LR_AUTO);

	lr_think_time(5);

	return 0;
}


