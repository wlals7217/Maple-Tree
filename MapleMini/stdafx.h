// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <unordered_map>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <thread>
#include <cstdint>
#include <filesystem>
#include <conio.h>
#include <vector>
#include <regex>
#include <map>
#include <future>
#include <string>
#include <stdarg.h>
#include <bitset>
#include <iomanip>
#include <algorithm>
#include <limits>

// TODO: reference additional headers your program requires here

typedef std::unordered_map<std::string, std::thread> ThreadMap;

typedef unsigned __int64 ulong;
typedef unsigned __int64 u64;
typedef signed __int64 s64;

typedef unsigned int uint;
typedef unsigned int u32;
typedef signed int s32;

typedef unsigned short ushort;
typedef unsigned short u16;
typedef signed short s16;

typedef unsigned char u8;
typedef signed char s8;

//Third Party libraries
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>
#include <boost/beast/core.hpp>
#include <boost/asio.hpp>
#include <boost/progress.hpp>
using namespace boost::filesystem;
namespace po = boost::program_options;

#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
using namespace nana;
#pragma comment (lib, "nana_v141_Debug_x64.lib")

#include "ThirdParty\frozen.h"
#include "ThirdParty\rang.hpp"
#include "ThirdParty\cdecrypt.cpp"

using namespace std;

#include <windows.h>
#include <Wininet.h>
#pragma comment (lib, "Wininet.lib")

#include "gen-versioninfo.h"
#include "ThreadManager.h"
#include "DownloadClient.h"
#include "TitleInfo.h"
#include "MapleTicket.h"
#include "MapleMini.h"
#include "UIMain.h"
#include "Tools.h"

using namespace MapleSeed;
using namespace CommonTools;
