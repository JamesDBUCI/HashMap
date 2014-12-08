#include <iostream>
#include <sstream>
#include "HashMap.hpp"
#include "Command.hpp"

int main()
{

	bool debug = false;
	std::string input_line;
	std::string input1;
	std::string input2; 
	std::string input3; 
	HashMap storage;

	do
	{

		// get exactly one line of input
		std::getline( std::cin, input_line );      

		// initialize/reset all input variables
		input1 = "";
		input2 = "";
		input3 = "";

		// go back and see what input was
		std::istringstream parse_input( input_line );      
		parse_input >> input1 >> input2 >> input3;

		// std::cout << "Input1 --> " << input1 << std::endl;
		// std::cout << "Input2 --> " << input2 << std::endl;
		// std::cout << "Input3 --> " << input3 << std::endl;	


		// main check command section
		if (input1 == "CREATE" && input2 != "" && input3 != "")
			create(input2, input3, storage);      
		
		else if (input1 == "LOGIN" && input2 != "" && input3 != "")
			login(input2, input3, storage);      

		else if (input1 == "REMOVE" && input2 != "" && input3 == "")
			remove(input2, storage);      

		
		else if (input1 == "CLEAR" && input2 == "" && input3 == "")
			{
				storage.clear();      
				std::cout << "CLEARED" << std::endl;
			}

		else if (input1 == "DEBUG" && input2 == "ON" && input3 == "")
			{
				if (!debug)
				{
					debug = true;
					std::cout << "ON NOW" << std::endl;
				}
				else
					std::cout << "ON ALREADY" << std::endl;
			}

		else if (input1 == "DEBUG" && input2 == "OFF" && input3 == "")
			{
				if (debug)
				{
					debug = false;
					std::cout << "OFF NOW" << std::endl;
				}
				else
					std::cout << "OFF ALREADY" << std::endl;
			}

		// debug section
		
				
		else if (input1 == "LOGIN" && input2 == "COUNT" && input3 == "" && debug)
			std::cout << storage.size() << std::endl;
		
		else if (input1 == "BUCKET" && input2 == "COUNT" && input3 == "" && debug)
			std::cout << storage.bucketCount() << std::endl;
		
		else if (input1 == "LOAD" && input2 == "FACTOR" && input3 == "" && debug)
			std::cout << storage.loadFactor() << std::endl;
		
		else if (input1 == "MAX" && input2 == "BUCKET" && input3 == "SIZE" && debug)
			std::cout << storage.maxBucketSize() << std::endl;


		else if (input1 == "QUIT" && input2 == "" && input3 == "")	
				continue;
		
		else
			std::cout << "INVALID" << std::endl;
	
	
	} while (input1 != "QUIT");      

	std::cout << "GOODBYE" << std::endl;


 //   HashMap hm1;
   
	// hm1.add("hwood0@blogger.com", "zUNeCBQEkTb");      
	// hm1.add("aanderson1@sourceforge.net", "72R0kc");      
	// hm1.add("rknight2@mysql.com", "e5dTMMBum3L");      
	// hm1.add("cmartinez3@4shared.com", "cz0Xv9");      
	// hm1.add("mstanley4@globo.com", "QG41ZiY");      
	// hm1.add("snguyen5@gizmodo.com", "YMme9L2yKSd");      
	// hm1.add("kpayne6@army.mil", "wT0FCC");      
	// hm1.add("jfields7@mozilla.com", "OLcGJXlb6");      
	// hm1.add("rstevens8@tinyurl.com", "zkHSfkr1gXl");      
	// hm1.add("jlarson9@toplist.cz", "ROGhi3");      
	// hm1.add("balvareza@mozilla.org", "hHlEdzmFEDY");      
	// hm1.add("tryanb@vistaprint.com", "nOwX6OOLZYo");      
	// hm1.add("tlongc@biblegateway.com", "g4LtObsP");      
	// hm1.add("kschmidtd@imdb.com", "lgBjj2b55L");      
	// hm1.add("ajacksone@fastcompany.com", "sqddYh");      
	// hm1.add("awalkerf@dedecms.com", "l5hxfxshlf4w");      
	// hm1.add("dscottg@fda.gov", "3Kzwnn");      
	// hm1.add("jmarshallh@tmall.com", "8JBtu9mRhNX");      
	// hm1.add("spricei@msu.edu", "WHpae5IBVmo");      
	// hm1.add("smitchellj@google.co.uk", "eJx0Dg0");      
	// hm1.add("jcrawfordk@indiatimes.com", "jlFZt8");      
	// hm1.add("jcampbelll@e-recht24.de", "3jCPCE0NT");      
	// hm1.add("alarsonm@qq.com", "CiaYnXu9875T");      
	// hm1.add("lturnern@bizjournals.com", "8MJcJ4hv");      
	// hm1.add("ereynoldso@reuters.com", "rpwNbzsRaH");      
	// hm1.add("aramirezp@webnode.com", "jc8ZpfxF");      
	// hm1.add("drobertsq@google.pl", "HPD5jnzsX");      
	// hm1.add("rgrahamr@aol.com", "gseqal5");      
	// hm1.add("gmorgans@uol.com.br", "DSAC8s7W0y");      
	// hm1.add("tcookt@goo.ne.jp", "cQ3xBDC7KNTX");      
	// hm1.add("eharrisonu@wix.com", "gXmSU6sbNJRB");      
	// hm1.add("jmillerv@engadget.com", "Z4D7bWaNsK3");      
	// hm1.add("hwilliamsw@ebay.com", "09wiZ8JmbkO");      
	// hm1.add("wfieldsx@bandcamp.com", "Xw2rGIm");      
	// hm1.add("smorgany@vk.com", "5eN0ixrm0TlC");      
	// hm1.add("ccookz@ifeng.com", "mVAt6Av");      
	// hm1.add("greid10@163.com", "dLsO1d22f");      
	// hm1.add("iharrison11@washingtonpost.com", "MBYFV9tU");      
	// hm1.add("rcarroll12@wordpress.com", "gfmpJlD0kwOI");      
	// hm1.add("khanson13@about.me", "XdIAOGx8ouW");      
	// hm1.add("jmorgan14@army.mil", "p5uWhh8v");      
	// hm1.add("sjames15@ow.ly", "ynWavDp8xM");      
	// hm1.add("barmstrong16@mapy.cz", "PACG58K");      
	// hm1.add("jmartinez17@webmd.com", "52dvW3x");      
	// hm1.add("jsmith18@un.org", "L0uEYeLT");      
	// hm1.add("tkim19@qq.com", "vd4QNFtG1");      
	// hm1.add("mschmidt1a@washingtonpost.com", "Ze31jfVEU");      
	// hm1.add("mbryant1b@dailymail.co.uk", "JGZ0nQz5u");      
	// hm1.add("jblack1c@unesco.org", "AgSdXHd6g");      
	// hm1.add("abailey1d@reverbnation.com", "MVy0zr");      
	// hm1.add("stucker1e@facebook.com", "TUAtWJH");      
	// hm1.add("jsimpson1f@webmd.com", "Llwl5mfd");      
	// hm1.add("aphillips1g@devhub.com", "BkuisRTr");      
	// hm1.add("tporter1h@nbcnews.com", "hfCbY5kO");      
	// hm1.add("vmoreno1i@earthlink.net", "6J5xDdlpoPP");      
	// hm1.add("ccarpenter1j@privacy.gov.au", "erh4MUX");      
	// hm1.add("wrobinson1k@nature.com", "DTHEAphQDvOU");      
	// hm1.add("srogers1l@jimdo.com", "DdNnQS1Sa");      
	// hm1.add("hgreen1m@t-online.de", "111W4Bxd");      
	// hm1.add("eperkins1n@rambler.ru", "Ruezg6gJCNl");      
	// hm1.add("tdavis1o@reuters.com", "jKNVNfBon73");      
	// hm1.add("ablack1p@exblog.jp", "DoKe9Z5fA5");      
	// hm1.add("adavis1q@sun.com", "iImxVr");      
	// hm1.add("arivera1r@cyberchimps.com", "Wkai75BtlUvY");      
	// hm1.add("acruz1s@tamu.edu", "iEMMcD");      
	// hm1.add("jbishop1t@storify.com", "R4DuOrvfIP4");      
	// hm1.add("dramirez1u@princeton.edu", "ZEnAFvavuNh");      
	// hm1.add("pschmidt1v@acquirethisname.com", "tB4UDn6Y813");      
	// hm1.add("shanson1w@taobao.com", "vzo195O3cpXA");      
	// hm1.add("agrant1x@usnews.com", "ap1yxo4Uke");      
	// hm1.add("drodriguez1y@myspace.com", "IeJd6CiCmi");      
	// hm1.add("llawrence1z@tinypic.com", "Lj8hxyS2RBu");      
	// hm1.add("acarr20@whitehouse.gov", "2Kn10Odb");      
	// hm1.add("itaylor21@tinyurl.com", "Wl05y4Qze2");      
	// hm1.add("dnichols22@qq.com", "BhJA3LUd");      
	// hm1.add("adixon23@php.net", "8lOPcjUA4qG");      
	// hm1.add("jking24@ask.com", "rIuldj5");      
	// hm1.add("ppayne25@cbsnews.com", "lZX3uXH4k");      
	// hm1.add("hmason26@storify.com", "JmPA8rFO4hu");      
	// hm1.add("jkelley27@ca.gov", "1BuPrsiQvOnB");      
	// hm1.add("tmontgomery28@reference.com", "6VSeVqG9Q");      
	// hm1.add("karmstrong29@list-manage.com", "sFMnggVEFi");      
	// hm1.add("khudson2a@psu.edu", "tnVwVHS21");      
	// hm1.add("wwoods2b@japanpost.jp", "ZXZpP5dS");      
	// hm1.add("dwilliamson2c@wikipedia.org", "DIl5GfVq");      
	// hm1.add("gstephens2d@storify.com", "H8vIfpyfZ");      
	// hm1.add("pknight2e@tinypic.com", "f5mYuoXHueqJ");      
	// hm1.add("avasquez2f@example.com", "lqtYjD5TKmbd");      
	// hm1.add("jshaw2g@bandcamp.com", "pGtvoRkH4m5J");      
	// hm1.add("mcole2h@mayoclinic.com", "oUJoGREXAFKA");      

	// std::cout << "HM1 Size --> " << hm1.size() << std::endl;
	// std::cout << "HM1  Bucket Count --> " << hm1.bucketCount() << std::endl;
	// std::cout << "HM1  Load Factor --> " << hm1.loadFactor() << std::endl;
	// std::cout << "HM1 Max Bucket Size --> " << hm1.maxBucketSize() << std::endl;
	// std::cout << "---------------- - --------------" << std::endl;	

	// HashMap hm2;
	// std::cout << "HM2 Size --> " << hm2.size() << std::endl;
	// std::cout << "HM2  Bucket Count --> " << hm2.bucketCount() << std::endl;
	// std::cout << "HM2  Load Factor --> " << hm2.loadFactor() << std::endl;
	// std::cout << "HM2 Max Bucket Size --> " << hm2.maxBucketSize() << std::endl;
	// std::cout << "----------------After Copy--------------" << std::endl;
	// hm2 = hm1;
	// std::cout << "HM2 Size --> " << hm2.size() << std::endl;
	// std::cout << "HM2  Bucket Count --> " << hm2.bucketCount() << std::endl;
	// std::cout << "HM2  Load Factor --> " << hm2.loadFactor() << std::endl;
	// std::cout << "HM2 Max Bucket Size --> " << hm2.maxBucketSize() << std::endl;

	// std::cout << hm2.contains("hwood0@blogger.com") << std::endl;
	// std::cout << hm2.contains("aanderson1@sourceforge.net") << std::endl; 
	// std::cout << hm2.contains("rknight2@mysql.com") << std::endl;
	// std::cout << hm2.contains("cmartinez3@4shared.com") << std::endl; 
	// std::cout << hm2.contains("mstanley4@globo.com") << std::endl;
	// std::cout << hm2.contains("snguyen5@gizmodo.com") << std::endl;
	// std::cout << hm2.contains("kpayne6@army.mil") <<std::endl;
	// std::cout << hm2.contains("jfields7@mozilla.com") << std::endl;
	// std::cout << hm2.contains("rstevens8@tinyurl.com") << std::endl;
	// std::cout << hm2.contains("jlarson9@toplist.cz") <<std::endl;
	// std::cout << hm2.contains("balvareza@mozilla.org") << std::endl;
	// std::cout << hm2.contains("tryanb@vistaprint.com") << std::endl;
	// std::cout << hm2.contains("tlongc@biblegateway.com") << std::endl;
	// std::cout << hm2.contains("kschmidtd@imdb.com") << std::endl;
	// std::cout << hm2.contains("ajacksone@fastcompany.com") << std::endl;
	// std::cout << hm2.contains("awalkerf@dedecms.com") << std::endl;
	// std::cout << hm2.contains("dscottg@fda.gov" ) <<std::endl;
	// std::cout << hm2.contains("jmarshallh@tmall.com") << std::endl;
	// std::cout << hm2.contains("spricei@msu.edu") << std::endl;
	// std::cout << hm2.contains("smitchellj@google.co.uk") << std::endl;
	// std::cout << hm2.contains("jcrawfordk@indiatimes.com" ) <<std::endl;
	// std::cout << hm2.contains("jcampbelll@e-recht24.de") << std::endl;
	// std::cout << hm2.contains("alarsonm@qq.com") << std::endl; 
	// std::cout << hm2.contains("lturnern@bizjournals.com") << std::endl;
	// std::cout << hm2.contains("ereynoldso@reuters.com") << std::endl;
	// std::cout << hm2.contains("aramirezp@webnode.com") << std::endl;
	// std::cout << hm2.contains("drobertsq@google.pl") << std::endl;
	// std::cout << hm2.contains("rgrahamr@aol.com") << std::endl;
	// std::cout << hm2.contains("gmorgans@uol.com.br") << std::endl;
	// std::cout << hm2.contains("tcookt@goo.ne.jp") << std::endl;
	// std::cout << hm2.contains("eharrisonu@wix.com") << std::endl;
	// std::cout << hm2.contains("jmillerv@engadget.com") << std::endl;
	// std::cout << hm2.contains("hwilliamsw@ebay.com") << std::endl;
	// std::cout << hm2.contains("wfieldsx@bandcamp.com") << std::endl;
	// std::cout << hm2.contains("smorgany@vk.com") << std::endl;
	// std::cout << hm2.contains("ccookz@ifeng.com") << std::endl;
	// std::cout << hm2.contains("greid10@163.com") << std::endl;
	// std::cout << hm2.contains("iharrison11@washingtonpost.com") << std::endl;
	// std::cout << hm2.contains("rcarroll12@wordpress.com") << std::endl; 
	// std::cout << hm2.contains("khanson13@about.me") << std::endl;
	// std::cout << hm2.contains("jmorgan14@army.mil") << std::endl;
	// std::cout << hm2.contains("sjames15@ow.ly") << std::endl;
	// std::cout << hm2.contains("barmstrong16@mapy.cz") << std::endl;
	// std::cout << hm2.contains("jmartinez17@webmd.com") << std::endl;
	// std::cout << hm2.contains("jsmith18@un.org") << std::endl;
	// std::cout << hm2.contains("tkim19@qq.com") << std::endl;
	// std::cout << hm2.contains("mschmidt1a@washingtonpost.com") << std::endl;
	// std::cout << hm2.contains("mbryant1b@dailymail.co.uk") << std::endl;
	// std::cout << hm2.contains("jblack1c@unesco.org") << std::endl;
	// std::cout << hm2.contains("abailey1d@reverbnation.com") << std::endl;
	// std::cout << hm2.contains("stucker1e@facebook.com") << std::endl;
	// std::cout << hm2.contains("jsimpson1f@webmd.com") << std::endl;
	// std::cout << hm2.contains("aphillips1g@devhub.com") << std::endl;
	// std::cout << hm2.contains("tporter1h@nbcnews.com") << std::endl;
	// std::cout << hm2.contains("vmoreno1i@earthlink.net") << std::endl;
	// std::cout << hm2.contains("ccarpenter1j@privacy.gov.au") << std::endl;
	// std::cout << hm2.contains("wrobinson1k@nature.com") << std::endl; 
	// std::cout << hm2.contains("srogers1l@jimdo.com") << std::endl;
	// std::cout << hm2.contains("hgreen1m@t-online.de") << std::endl;
	// std::cout << hm2.contains("eperkins1n@rambler.ru") << std::endl;
	// std::cout << hm2.contains("tdavis1o@reuters.com") << std::endl;
	// std::cout << hm2.contains("ablack1p@exblog.jp") << std::endl;
	// std::cout << hm2.contains("adavis1q@sun.com" ) <<std::endl;
	// std::cout << hm2.contains("arivera1r@cyberchimps.com") << std::endl;
	// std::cout << hm2.contains("acruz1s@tamu.edu" ) << std::endl;
	// std::cout << hm2.contains("jbishop1t@storify.com") << std::endl;
	// std::cout << hm2.contains("dramirez1u@princeton.edu") << std::endl;
	// std::cout << hm2.contains("pschmidt1v@acquirethisname.com") << std::endl;
	// std::cout << hm2.contains("shanson1w@taobao.com") << std::endl;
	// std::cout << hm2.contains("agrant1x@usnews.com") << std::endl;
	// std::cout << hm2.contains("drodriguez1y@myspace.com") << std::endl;
	// std::cout << hm2.contains("llawrence1z@tinypic.com") << std::endl;
	// std::cout << hm2.contains("acarr20@whitehouse.gov") << std::endl;
	// std::cout << hm2.contains("itaylor21@tinyurl.com") << std::endl;
	// std::cout << hm2.contains("dnichols22@qq.com") << std::endl;
	// std::cout << hm2.contains("adixon23@php.net") << std::endl;
	// std::cout << hm2.contains("jking24@ask.com") << std::endl;
	// std::cout << hm2.contains("ppayne25@cbsnews.com") << std::endl;
	// std::cout << hm2.contains("hmason26@storify.com") << std::endl;
	// std::cout << hm2.contains("jkelley27@ca.gov") << std::endl;
	// std::cout << hm2.contains("tmontgomery28@reference.com") << std::endl;
	// std::cout << hm2.contains("karmstrong29@list-manage.com") << std::endl;
	// std::cout << hm2.contains("khudson2a@psu.edu") << std::endl;
	// std::cout << hm2.contains("wwoods2b@japanpost.jp") << std::endl;
	// std::cout << hm2.contains("dwilliamson2c@wikipedia.org") << std::endl;
	// std::cout << hm2.contains("gstephens2d@storify.com") << std::endl;
	// std::cout << hm2.contains("pknight2e@tinypic.com") << std::endl;
	// std::cout << hm2.contains("avasquez2f@example.com") << std::endl;
	// std::cout << hm2.contains("jshaw2g@bandcamp.com") << std::endl;
	// std::cout << hm2.contains("mcole2h@mayoclinic.com") << std::endl;
   

    return 0;
}

