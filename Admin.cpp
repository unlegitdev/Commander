//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <netudp.h>
#include "Main.h"
#include <nconfig.h>
#include <filesystem.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
try{
 WSASession session;
 UDPSocket s;

 s.SendTo(tar->Text.c_str(),9100,cmd->Text.c_str(),cmd->Text.Length());

}catch(...){
 MessageBox(this->Handle, "Could not connect to client!","Error",0);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
std::string x;
std::string x2;
x2=tar->Text.c_str();
x="LASTCLIENT="+x2+";";
Std_Out("config.txt",x.c_str());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormActivate(TObject *Sender)
{
tar->Text=ProcessConfig("LASTCLIENT",Std_LineIn("config.txt").c_str()).c_str();
}
//---------------------------------------------------------------------------

