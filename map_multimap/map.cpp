/*
 * =====================================================================================
 *
 *       Filename:  map.cpp
 *
 *    Description:  usage of map
 *
 *        Version:  1.0
 *        Created:  03/30/12 01:50:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *        Company:
 *
 * =====================================================================================
 */
#include    "../my.h"

typedef pair<int, string> clientfile;
typedef map<clientfile, int> file_location;
typedef map<clientfile, int>::value_type file_valtype;
typedef map<int, char*> fs_info;
typedef map<int, char*>::value_type fs_info_valtype;

typedef map<string, int>::value_type valType;
int main(void)
{
	map<string, int> word_count;//empty map from string to int

	file_location file;
	clientfile client_id(1, "a");
	file.insert(file_valtype(client_id, 1));
	clientfile client_id_2(2, "a");
	file.insert(file_valtype(client_id_2, 1));

	fs_info fs_data;
	fs_data.insert(fs_info_valtype(2, "64"));
	fs_data.insert(fs_info_valtype(3, "63"));
	fs_data.insert(fs_info_valtype(1, "12"));

	cout << "fs_data.size():" << fs_data.size() << endl;
	cout << "fs_data[2]:" << fs_data[2] << endl;
	cout << "fs_data[1]:" << fs_data[1] << endl;
	cout << "fs_data[4]:" << fs_data[4] << endl;
	fs_info::iterator fs_begin = fs_data.begin();
	cout << "fs_info, begin:" << (fs_begin)->first << endl;
	cout << "fs_info, sencond:" << (fs_begin)->second<< endl;
	cout << endl << endl;


	cout << "file.size:" << file.size() << endl;
	file_location::iterator itoffile_location = file.find(client_id);

	if (itoffile_location != file.end())
	{
		cout << "find the location of the fs:" << itoffile_location->second << endl;
	}

	file_location::iterator ito_of_file_loc = file.begin();

	while (ito_of_file_loc != file.end())
	{
		cout << "clientid:" << ito_of_file_loc->first.first << endl;
		ito_of_file_loc++;
	}



	if (file.erase(client_id))
	{
		cout << "ok, client_id removed" << endl;
	}

	else
	{
		cout << "client_id not found" << endl;
	}

	//insert element
	//there are 3 types operation of insert in map
	//when the argument of insert is such as <key, value>(pair typye),
	//insert will return object of pair type.
	word_count.insert(map<string, int>::value_type("lxf", 1));
	word_count.insert(valType("lyh", 2));
	cout << "word_count.size:" << word_count.size() << endl;
	cout << "word_count[1]:" << word_count.begin()->first << "EOF" << endl;

	if (!(word_count.insert(valType("lyh", 1)).second))
	{
		cerr << "This element is already in map" << endl;
	}

	//search element
	int lxf = 0;

	if (word_count.count("lxf"))
	{
		lxf = word_count["lxf"];
		cout << "lxf:" << lxf << endl;
	}

	else
	{
		cout << "oops: lxf not found" << endl;
	}

	int occurs = 0;
	map<string, int>::iterator it = word_count.find("lxf");

	if (it != word_count.end())
	{
		occurs = it->second;
		cout << "lxf's occurs :" << occurs << endl;
	}

	//delete element
	if (word_count.erase("lxf"))
	{
		cout << "ok, lxf removed" << endl;
	}

	else
	{
		cout << "oops, lxf not found" << endl;
	}

	if (word_count.count("lxf"))
	{
		lxf = word_count["lxf"];
		cout << "lxf:" << lxf << endl;
	}

	else
	{
		cout << "oops: lxf not found" << endl;
	}

	return 0;
}
