//#include <iostream>
//#include <string>
//#include <regex>
//
//using namespace std;
//
//int main(){
//	string input;
//	while (1){
//		regex RE1("abc");//it will pass abc only.
//		regex RE2("abc", regex_constants::icase);//it will pass abc, Abc, aBc, abC, ABc, aBC, AbC,ABC // icase means ignore case.
//		regex RE3("abc.", regex_constants::icase);// . means any character except a new line.
//		regex RE4("abc?", regex_constants::icase);//it will accept ab(ignore case) followed by either 0 or 1 'c'(ignore case).
//		regex RE5("abc*", regex_constants::icase);//it will accept ab(ignore case) followed by either 0 or many 'c'(ignore case).
//		regex RE6("abc+", regex_constants::icase);//it will accept ab(ignore case) followed by either 1 or many 'c'(ignore case).
//		regex RE7("ab[cd]*", regex_constants::icase);//it will accept ab(ignore case) followed by either 0 or many 'c' or 'd'(ignore case).
//		regex RE8("ab[cd]+", regex_constants::icase);//it will accept ab(ignore case) followed by either 1 or many 'c' or 'd'(ignore case).
//		regex RE9("ab[^cd]*", regex_constants::icase);//it will accept ab(ignore case) followed by either any string except the string having 'c' or 'd'(ignore case).
//		regex RE10("ab[cd]{3}", regex_constants::icase);//it will accept ab(ignore case) followed by total 3 'c' or 'd'(ignore case).
//		regex RE11("ab[cd]{3,}", regex_constants::icase);//it will accept ab(ignore case) followed by total 3 or many 'c' or 'd'(ignore case).
//		regex RE12("ab[cd]{3,5}", regex_constants::icase);//it will accept ab(ignore case) followed by total 3 or 4 or 5 'c' or 'd'(ignore case).
//		regex RE13("abc|def", regex_constants::icase);//	| means OR statement.
//		
//		// lets talk about groups in Regular Expression
//
//		regex RE14("(abc)de+\\1", regex_constants::icase);//it will will accept "abc d e+ abc";
//		regex RE15("(abc)de*\\1", regex_constants::icase);//it will will accept "abc d e* abc";
//		regex RE16("(abc)de?\\1", regex_constants::icase);//it will will accept "abc d e? abc";
//
//
//		regex RE17("(abc)d(ef+)\\2\\1", regex_constants::icase);//it will will accept "abc d e f+ e f+ abc". both f+ should be same
//
//		//it will accept email ending with .com	
//
//		regex Mail("[[:w:]]+@[[:w:]]+\.com");//[[:w:]] word character : digit, number or underscope.
//
//		cin >> input;
//
//		//it Matches the string 1 with 2 and save result in bool match.
//		//bool match = regex_match(input, Mail);
//
//		regex RE18("abc.", regex_constants::icase);//it will accept the string having abc and 1 or more  character after abc.
//		regex RE19("^abc.", regex_constants::icase);//it will accept the string having abc in start.
//		regex RE20("(abc)$", regex_constants::icase);//it will accept the string ending with abc.
//		//it will search the string in input string.
//		bool match = regex_search(input, RE20);
//
//		if (match)
//			cout << "Matched.\n";
//		else
//			cout << "Not Matched.\n";
//	}
//	system("pause");
//	return 0;
//}