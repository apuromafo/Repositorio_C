// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include<stdlib.h>
#include<time.h>

#include "Unit2.h"
#include <string>
using namespace std;

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

// Prototipo de la Funci�n Login.

TForm2 *Form2;

// ---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender) {

	// Initialize String Array

	string msj[4] = {
		"N�mero Correcto", "Tu N�mero es Menor, aumenta m�s", " Tu N�mero Mayor, disminuye", "M�ximo de intentos, lo siento has perdido"
	};
	int num, code;
	int cont = Label4->Caption.ToInt();
	num = Label5->Caption.ToInt();
	// si nombre es igual a

	if (cont <= 10) {

		if (Edit1->Text.ToInt() == num) {

			Label9->Caption = Label9->Caption.ToInt() + 1;
			Button1->Enabled = False;
			Label13->Caption = "Ganador ->";
			Label13->Visible = True;
			Label5->Visible = True;
			ShowMessage(msj[0].c_str());

		}
		else {
			if (Edit1->Text.ToInt() < num) {
				ShowMessage(msj[1].c_str());
			}

			else {
				if (Edit1->Text.ToInt() > num) {
					ShowMessage(msj[2].c_str());
				};
			}
			Label4->Caption = cont - 1;

			if (cont <= 1) {
				Label11->Caption = Label11->Caption.ToInt() + 1;
				Button1->Enabled = False;
                	Label13->Caption = "Perdedor ->";
				Label5->Visible = True;
				Label13->Visible = True;
				ShowMessage(msj[3].c_str());


				// exit(0);
			}

		}
	}

}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender) {
	int num;

	srand(time(NULL));
	num = 1 + rand() % (101 - 1);
	Label4->Caption = 10;
	Label5->Caption = num;
	Label7->Caption = Label7->Caption.ToInt() + 1;
	Button1->Enabled = True;
	Label5->Visible = False;
	Label13->Visible = False;
	Label12->Caption = Label7->Caption.ToInt() - Label9->Caption.ToInt() -
		Label11->Caption.ToInt() - 1;
}
// ---------------------------------------------------------------------------
