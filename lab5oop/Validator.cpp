#pragma comment(lib, "urlmon.lib")
#include "Validator.h"

#include<fstream>
#include<winerror.h>
#include<Urlmon.h>
//#include<urlmon.lib>

using std::istream;

bool Validator::id_exists(const string &id, const vector<string> & ids_list)
{
	int l = ids_list.size();
	for (int i = 0; i < l; i++)
		if (id == ids_list[i]) return false;
	return true;
}

bool Validator::id_does_not_exist(const string& id, const vector<string> & ids_list)
{
	return(!id_exists(id, ids_list));
}

bool Validator::validate_year(const int &year)
{
	return (1887 <= year && year <= 2020); // primul film ever a aparut in 1887
}

bool Validator::validate_likes(const int &likes)
{
	return (lowest_likes <= likes);
}

bool Validator::validate_trailer(const string& url)
{
	string aux = '"' + url + '"';
	///string aux = '"' + url + '"';
	IStream* pStream = NULL;
	//if (SUCCEEDED(URLOpenBlockingStream(0, aux.c_str(), &pStream, 0, 0))) {
	if (URLOpenBlockingStream(0, aux.c_str(), &pStream, 0, 0) == S_OK) {
		// Release the stream immediately since we don't use the data.
		pStream->Release();
//		return TRUE;
		return true;
	}
	else {
	//	return FALSE;
		return false;
	}
}