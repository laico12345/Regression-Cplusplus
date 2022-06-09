//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GD.h"
#include <Math.hpp>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
 #include <cfloat>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
using namespace std;
int T=0;
float sample[1000]={0};
int count = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    randomize();
    T=1 + random(50);
    _control87(MCW_EM, MCW_EM);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnGDClick(TObject *Sender)
{
    if(RadioGroup1->ItemIndex==0)
        GradientDescent();
    else if(RadioGroup1->ItemIndex==1)
        Liner();
    else if(RadioGroup1->ItemIndex==2)
        AnalyticExpression();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    FILE *stream;
    Series1->Clear(); Series2->Clear();
    Series3->Clear(); Series4->Clear();
    ListBox1->Clear(); ListBox2->Clear();
    urlOpen->Text="";
    float x=0,y=0;
    int xmax=-1000,xmin=1000;
    int ymax=-1000,ymin=1000;
    count=0;
    AnsiString getstring="",getword="",getresult="";
    char word;
    OpenDialog1->Options.Clear();
    OpenDialog1->Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
    OpenDialog1->FilterIndex = 2; // start the dialog showing all files
    if (OpenDialog1->Execute()){
        stream = fopen(OpenDialog1->Files->Strings[0].c_str(), "r");
        urlOpen->Text=OpenDialog1->FileName;
        while ((word = fgetc(stream)) != EOF)
        {
            getword=AnsiString(word);
             if(getword=="\n" || getword==","){
                getresult=getstring;
                sample[count]=StrToFloat(getresult);
                count++;
                getstring="";
            }
            else{
                getstring+=AnsiString(word);
            }
        }
        fclose(stream);

        for(int j=0;j<count;j++){
            if(j%2==0){
                x=sample[j];
                xmin = xmin>x?x:xmin;
                xmax = xmax<x?x:xmax;
            }
            else{
                y=sample[j];
                ymin = ymin>y?y:ymin;
                ymax = ymax<y?y:ymax;
            }
            if(x !=0 && y!=0){
                Series1->AddXY(x,y, "", clRed );
                x=0,y=0;
            }
        }
    }
    Series1->GetVertAxis->SetMinMax(ymin-1,ymax+2);
    Series1->GetHorizAxis->SetMinMax(xmin-1,xmax+2);

}
//---------------------------------------------------------------------------





void __fastcall TForm1::GradientDescent()
{
    //TODO: Add your source code here
    double Learning_Rate=StrToFloat(edtRate->Text);
    double y=0,L,n=count/2;
    double *sample_x;
    double *sample_y;
    double a[4]={0},bias[4]={0},sum=0,Residual=0;
    int xc=0,yc=0;
    int iter=StrToInt(Edit1->Text);
    sample_x = new double[n];
    sample_y = new double[n];
    AnsiString Str="梯度下降法 Gradient Descent : ";
    Series2->Clear();
    ListBox1->Clear();
    Learning_Rate = RoundTo( Learning_Rate , -8);
    ListBox1->Items->Add(Str);
    ListBox1->Items->Add("");
    for(int j=0;j<4;j++){
        a[j] = sin(3.141215967*T*10./180);
        T = 1 + random(50);
        Str="初始值 a"+IntToStr(j)+" = " + FloatToStr(a[j]);
        ListBox1->Items->Add(Str);
    }
    Str="------";
    ListBox1->Items->Add(Str);
    for(int j=0;j<count;j++){
        if(j%2==0){
            sample_x[xc]=sample[j];
            xc++;
        }
        else{
            sample_y[yc]=sample[j];
            yc++;
        }
    }
    for(int j=1;j<=iter;j++){
        for(int o=0;o<n;o++){
            for(int k=3;k>=0;k--){
                    if (k != 0 ) y+=(a[k] * pow(sample_x[o],k));
                    else y+=a[k];
            }
            sum += pow(y - sample_y[o],2);
            bias[0] += RoundTo(y - sample_y[o],-8);
            bias[1] += RoundTo((y - sample_y[o]) * pow(sample_x[o],1),-8);
            bias[2] += RoundTo((y - sample_y[o]) * pow(sample_x[o],2),-8);
            bias[3] += RoundTo((y - sample_y[o]) * pow(sample_x[o],3),-8);
            y=0;
        }
        L=(1/(2*n)) * sum;

        for(int k=3;k>=0;k--){
            a[k] = a[k] - (Learning_Rate*((1/n)*bias[k]));
            bias[k]=0;
        }
        sum=0;
        if(j % 10000 == 0){
            Str = "Iter = " + IntToStr(j) + ", Loss = " + FloatToStr(L);
            ListBox1->Items->Add(Str);
        }
        Series2->Clear();
        for(int o=0;o<n;o++){
            for(int k=3;k>=0;k--){
                if (k != 0 ) y+=(a[k] * pow(sample_x[o],k));
                else y+=a[k];
            }
            sum += fabs(y - sample_y[o]);
            Series2->AddXY(sample_x[o],y,"",clBlue);
            y=0;
        }
        Chart1->Refresh();
    }
    Str="------";
    ListBox1->Items->Add(Str);
    /*for(int o=0;o<n;o++){
        for(int k=3;k>=0;k--){
            if (k != 0 ) y+=(a[k] * pow(sample_x[o],k));
            else y+=a[k];
        }
        sum += fabs(y - sample_y[o]);
        Series2->AddXY(sample_x[o],y,"",clBlue);
        y=0;
    }    */
    Residual = (1/n) * sum;
    for(int o=0;o<4;o++){
        Str="梯度下降結果 a"+IntToStr(o)+" = " + FloatToStr(a[o]);
        ListBox1->Items->Add(Str);
    }
    Str="------";
    ListBox1->Items->Add(Str);
    Str="Residual = " + FloatToStr(Residual);
    ListBox1->Items->Add(Str);

    
}

void __fastcall TForm1::Liner()
{
    //TODO: Add your source code here
    double Learning_Rate=StrToFloat(edtRate->Text);
    double y=0,L,n=count/2;
    double *sample_x;
    double *sample_y;
    double a[2]={0},bias[2]={0},sum=0,Residual=0;
    int xc=0,yc=0;
    int iter=StrToInt(Edit1->Text);
    sample_x = new double[n];
    sample_y = new double[n];
    AnsiString Str="線性回歸 Linear Regression : ";
    Series3->Clear();
    ListBox2->Clear();
    Learning_Rate = RoundTo( Learning_Rate , -3);
    ListBox2->Items->Add(Str);
    ListBox2->Items->Add("");
    for(int j=0;j<2;j++){
        a[j] = sin(3.141215967*T*10./180);
        T = 1 + random(50);
        Str="初始值 a"+IntToStr(j)+" = " + FloatToStr(a[j]);
        ListBox2->Items->Add(Str);
    }
    Str="------";
    ListBox2->Items->Add(Str);
    for(int j=0;j<count;j++){
        if(j%2==0){
            sample_x[xc]=sample[j];
            xc++;
        }
        else{
            sample_y[yc]=sample[j];
            yc++;
        }
    }
    for(int j=1;j<=iter;j++){
        for(int o=0;o<n;o++){
            for(int k=1;k>=0;k--){
                    if (k != 0 ) y+=(a[k] * pow(sample_x[o],k));
                    else y+=a[k];
            }
            sum += pow(y - sample_y[o],2);
            bias[0] += RoundTo(y - sample_y[o],-4);
            bias[1] += RoundTo((y - sample_y[o]) * pow(sample_x[o],1),-4);
            y=0;
        }
        L=(1/(2*n)) * sum;

        for(int k=1;k>=0;k--){
            a[k] = a[k] - (Learning_Rate*((1/n)*bias[k]));
            bias[k]=0;
        }
        sum=0;
        if(j % 10000 == 0){
            Str = "Iter = " + IntToStr(j) + ", Loss = " + FloatToStr(L);
            ListBox2->Items->Add(Str);
        }
        Series3->Clear();
        for(int o=0;o<n;o++){
            for(int k=1;k>=0;k--){
                if (k != 0 ) y+=(a[k] * pow(sample_x[o],k));
                else y+=a[k];
            }
            sum += fabs(y - sample_y[o]);
            Series3->AddXY(sample_x[o],y,"",clGreen);
            y=0;
        }
        Chart1->Refresh();
    }
    Str="------";
    ListBox2->Items->Add(Str);
    /*for(int o=0;o<n;o++){
        for(int k=1;k>=0;k--){
            if (k != 0 ) y+=(a[k] * pow(sample_x[o],k));
            else y+=a[k];
        }
        sum += fabs(y - sample_y[o]);
        Series3->AddXY(sample_x[o],y,"",clGreen);
        y=0;
    }    */
    Residual = (1/n) * sum;
    for(int o=0;o<2;o++){
        Str="線性回歸結果 a"+IntToStr(o)+" = " + FloatToStr(a[o]);
        ListBox2->Items->Add(Str);
    }
    Str="------";
    ListBox2->Items->Add(Str);
    Str="Residual = " + FloatToStr(Residual);
    ListBox2->Items->Add(Str);
}
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Chart1->SaveToBitmapFile("D:\\C++ Builder Regression Analysis\\result\\test.jpg");
    ListBox1->Clear();
    ListBox2->Clear();
    Series1->Clear();
    Series2->Clear();
    Series3->Clear();
    urlOpen->Text="";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::AnalyticExpression()
{
    //TODO: Add your source code here
    Series4->Clear();
    ListBox3->Clear();
    double Ymean=0,Xmean=0;
    double n=count/2,a,b,y;
    double sum1=0,sum2=0,sum3=0;;
    double Residual;
    double *sample_x;
    double *sample_y;
    int xc=0,yc=0;
    AnsiString Str="線性解析解 Linear Analytic expression : ";
    ListBox3->Items->Add(Str);
    ListBox3->Items->Add("");
    ///Init
    sample_x = new double[n];
    sample_y = new double[n];
    for(int j=0;j<count;j++){
        if(j%2==0){
            sample_x[xc]=sample[j];
            xc++;
        }
        else{
            sample_y[yc]=sample[j];
            yc++;
        }
    }
    ///Compute
    for(int i=0;i<n;i++){
        Ymean += sample_y[i];
        Xmean += sample_x[i];
    }
    Ymean=Ymean * (1/n);
    Xmean=Xmean * (1/n);
    for(int i=0;i<n;i++){
        sum1 += ((sample_y[i]-Ymean)*(sample_x[i]-Xmean));
        sum2 += pow((sample_x[i] - Xmean),2);
    }
    b=sum1/sum2;
    a=Ymean - (b*Xmean);
    ListBox3->Items->Add("Bvalue= " + FloatToStr(b));
    ListBox3->Items->Add("Avalue= " + FloatToStr(a));
    for(int i=0;i<n;i++){
       y=a+(b*sample_x[i]);
       sum3 += fabs(y - sample_y[i]);
       Series4->AddXY(sample_x[i],y,"",clPurple);
    }
    Residual = (1/n) * sum3;
    Str="------";
    ListBox3->Items->Add(Str);
    Str="Residual = " + FloatToStr(Residual);
    ListBox3->Items->Add(Str);
}
