/* $Id: vuser_end.c,v 1.1 2007/12/31 11:25:54 sevitz Exp $ [MISCCSID] */
vuser_end()
{
	lr_start_transaction("S01_T07_SignOff");

	web_url("welcome.pl_2",
		"URL=http://{url}/cgi-bin/welcome.pl?signOff=1",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://{url}/cgi-bin/nav.pl?page=menu&in=itinerary",
		"Snapshot=t8.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("S01_T07_SignOff", LR_AUTO);

	return 0;
}

