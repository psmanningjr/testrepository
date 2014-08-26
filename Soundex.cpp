#ifndef SOUNDEX_H

using namespace std;

class Soundex
{
public:
	string encode(const string& word) const 
	{
		return zeroPad(word);
	}	

private:
	string zeroPad(const string& word) const 
	{
		return word + "000";
	}
};
