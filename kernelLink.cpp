#include <iostream>
#include <string>
#include <sys/utsname.h> //Kernel名を取得するためのヘッダー
#include <boost/filesystem.hpp>
using namespace std;
using namespace boost::filesystem;

int main(void)
{
  //Kernel名を取得する
  struct utsname uts;
  uname(&uts);
  string kernel_version = uts.release;
  path lib = "/lib/modules";
  path headers = "/usr/src/linux-headers-";
  //path型では文字列演算が出来ないので変換
  string src = headers.string();
  //kernelの位置へのパス
  src += kernel_version;

  //シンボリックリンクの中身
  path to = src;
  //シンボリックリンクを作成するディレクトリ
  path from = lib / kernel_version / "build";
  //シンボリックリンクを貼る 　
  //存在しているものには上書き出来ないので一旦消してから書き込み
  if(exists(from)){
	char ch;
	do{
	  cout << "Do you want to overwrite symblic link \"" << from << "\"?(Y/N)" << endl;
          cin >> ch;
	  if(ch == 'N' || ch == 'n'){
		cout << "stoppped." << endl;
		return -1;
	  }
	}while( ch != 'Y' && ch != 'y');
	remove( from );
  }
   create_symlink( to, from );

  return 0;
}
