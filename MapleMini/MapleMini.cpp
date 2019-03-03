// MapleMini.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MapleMini.h"

void header()
{
	WriteLineBold("MapleSeed CLI Version %4.2fb", 1.0);
	WriteLineBold("Built: %s @ %s\n", __DATE__, __TIME__);
}

void info()
{
	WriteLineBold("Command Line Options: [] Required, {} Optional");

	WriteLine(" Decypt: MapleMini.exe [\"c:\\Location\\to\\encrypted\\content\"]");
	WriteLine(" Download: MapleMini.exe {-dl} [Title ID]");

	WriteLineBold("\nInput Options: [] Required, {} Optional");
	WriteLine(" Download: [-dl] [\"Title ID\"]");
	WriteLine(" Decrypt: [-de] [\"c:\\Location\\to\\encrypted\\content\"]");

	WriteLineBold("----------------------------------------------------------\n");
}

void simpleDecrypt(const char* path, const char* defaultDir)
{
	_chdir(path);

	struct stat buffer;
	if (stat("tmd", &buffer) != 0)
	{
		WriteLineRed("tmd file is missing. Decryption failed!");
		return;
	}

	if (stat("cetk", &buffer) != 0)
	{
		WriteLineRed("cetk file is missing. Decryption failed!");
		return;
	}

	start(3, "tmd", "cetk");
	std::cout << "Content Decryption Complete.\n\n";
	_chdir(defaultDir);
	info();
}

int main(signed int argc, char* argv[])
{
	rang::setControlMode(rang::control::Auto);
	SetConsoleTitleA("MapleSeed Command Line");

	auto fsp = path((char*)argv[0]).normalize();
	auto tmpdir = fsp.parent_path().generic_string();
	auto defaultdir = tmpdir.c_str();

	struct stat buffer;

	if ((stat("tmd", &buffer) == 0) && (stat("cetk", &buffer) == 0)) {
		simpleDecrypt("./", defaultdir);
		getchar();
		return 0;
	}

	header();
	info();

	while (true)
	{
		auto input = getUserInput();
		auto _input = string(input);
		_input.replace(0, 4, "");

		std::string path;
		std::regex re("\\\"(.*)\\\"");
		std::smatch match;
		if (std::regex_search(input, match, re) && match.size() > 1) {
			path = match.str(1);
		}
		else path = std::string("");

		if (input[0] == '-' && input[1] == 'd' && input[2] == 'l' && _input.length() == 16)
		{
			string url = string("http://api.tsumes.com/title/" + _input);
			auto jd = DownloadBytes(url.c_str());
			if (!jd.len) continue;

			auto ti = TitleInfo(jd.data, jd.len, defaultdir);
			ti.DownloadContent();

			simpleDecrypt(ti.workingDir.c_str(), defaultdir);
			continue;
		}

		if (input[0] == '-' && input[1] == 'd' && input[2] == 'e' && path.length() > 2)
		{
			simpleDecrypt(StringToCharArray(path), defaultdir);
			continue;
		}

		if (path.length() > 2 && DirExists(StringToCharArray(path)))
		{
			simpleDecrypt(StringToCharArray(path), defaultdir);
			break;
		}

		if (strcmp(StringToCharArray(input), "exit") == 0)
			exit(0);
	}
}

