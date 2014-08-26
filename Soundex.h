#ifndef SOUNDEX_H
#include <string>
#include <unordered_map>

using namespace std;

class Soundex
{
public:
	string encode(const string& word) const 
	{
        return zeroPad(upperFront(head(word)) + tail(encodedDigits(word)));
    }

    string upperFront(const string& string) const
    {
        return std::string(1,toupper(static_cast<unsigned char>(string.front())));
    }

private:
 	string tail(const string& word) const
	{
		return word.substr(1);
	}

	string head(const string& word) const
	{
		return word.substr(0,1);
	}

    const string NotADigit{"*"};

    string encodedDigits(const string& word) const
	{
		string encoding;
        encodeHead(encoding, word);
        encodeTail(encoding, word);
        return encoding;
	}

    void encodeHead(string& encoding, const string& word) const
    {
        encoding += encodedDigit(word.front());
    }

    void encodeTail(string& encoding, const string& word) const
    {
        for (auto i = 1u; i < word.length(); i++)
        {
            if (!isComplete(encoding))
            {
                encodeLetter(encoding, word[i], word[i-1]);
            }
        }
    }

    void encodeLetter(string& encoding,char letter,
                      char lastLetter) const
    {
        auto digit = encodedDigit(letter);
        if (digit != NotADigit &&
            (digit != lastDigit(encoding) ||
            isVowel(lastLetter)))
        {
            encoding += digit;
        }
    }

    bool isVowel(char letter) const
    {
        return string("aeiouy").find(lower(letter)) != string::npos;
    }

    string lastDigit(const string encoding) const
    {
        if (encoding.empty()) return NotADigit;
        return string(1,encoding.back());
    }

    bool isComplete(string encoding) const
    {
        return encoding.length() == MaxCode_Length;
    }

public:
	string encodedDigit(char letter) const
	{
		const unordered_map<char, std:: string> encodings {
			{'b',"1"}, {'f',"1"}, {'p',"1"}, {'v',"1"},
			{'c',"2"}, {'g',"2"}, {'j',"2"}, {'k',"2"}, {'q',"2"},
            {'s',"2"}, {'x',"2"}, {'z',"2"}, {'k',"2"},
			{'d',"3"}, {'t',"3"},
			{'l',"4"},
			{'m',"5"}, {'n',"5"},
			{'r',"6"}
		};
        auto it = encodings.find(lower(letter));
		
        return it == encodings.end() ? NotADigit : it->second;
	}

private:

    char lower(char c) const
    {
        return tolower(static_cast<unsigned char>(c));
    }
    static const size_t MaxCode_Length{4};

	string zeroPad(const string& word) const 
	{
		auto zerosNeeded = MaxCode_Length - word.length();
        return word                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     + string(zerosNeeded,'0');
	}
};
#endif
