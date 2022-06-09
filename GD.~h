//---------------------------------------------------------------------------

#ifndef GDH
#define GDH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TLabel *Label1;
        TEdit *edtRate;
        TButton *btnGD;
        TOpenDialog *OpenDialog1;
        TChart *Chart1;
        TPointSeries *Series1;
        TEdit *urlOpen;
        TLabel *Label2;
        TEdit *Edit1;
        TLineSeries *Series2;
        TListBox *ListBox1;
        TRadioGroup *RadioGroup1;
        TLineSeries *Series3;
        TListBox *ListBox2;
        TButton *Button2;
        TLineSeries *Series4;
        TListBox *ListBox3;
        void __fastcall btnGDClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        void __fastcall GradientDescent();
        void __fastcall Liner();
        void __fastcall AnalyticExpression();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
